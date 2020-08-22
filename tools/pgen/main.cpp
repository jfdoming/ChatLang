#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

template <typename T, typename H = hash<T>>
void printSet(const unordered_set<T, H> &set) {
    auto iter = set.begin();
    cerr << "{";
    if (iter != set.end()) {
        cerr << " \"" << *iter << "\"";
        ++iter;
    }
    for (; iter != set.end(); ++iter) {
        cerr << ", \"" << *iter << "\"";
    }
    cerr << " }" << endl;
}

class Item {
        size_t pos;
        string lhs;
        size_t rhsIndex;
        vector<string> rule;

        friend ostream &operator <<(ostream &, const Item &);
        friend struct hash_item;
    public:
        Item(const vector<string> &rule, const string &lhs, size_t rhsIndex) : rule{rule}, lhs{lhs}, rhsIndex{rhsIndex}, pos{0} {}

        bool hasNext() const {
            return rule.size() > pos;
        }
        string next() const {
            return rule[pos];
        }
        Item advance() const {
            Item result{*this};
            ++result.pos;
            return result;
        }
        string name() const {
            return lhs;
        }
        size_t ruleIndex() const {
            return rhsIndex;
        }

        bool operator==(const Item &other) const {
            return (
                other.pos == pos
                && other.lhs == lhs
                && other.rhsIndex == rhsIndex
            );
        }
};

ostream &operator <<(ostream &out, const Item &item) {
    out << item.lhs << " ->";
    for (size_t i = 0; i < item.rule.size(); ++i) {
        if (i == item.rhsIndex) {
            out << " .";
        }
        out << " " << item.rule[i];
    }
    out << endl;
    return out;
}

template <typename T, typename U, typename H = hash<T>>
struct hash_pair {
        H hashT;
        hash<U> hashU;
    public:
        size_t operator()(const pair<T, U> &x) const {
            return 3 * hashT(x.first) + hashU(x.second);
        }
};

struct hash_item {
        hash<size_t> hashPos;
        hash<string> hashLhs;
    public:
        size_t operator()(const Item &x) const {
            return 7 * hashPos(x.pos) + 3 * hashLhs(x.lhs) + hashPos(x.rhsIndex);
        }
};

template <typename T, typename H = hash<T>>
struct hash_set {
        H hashEl;
    public:
        // Thanks to https://stackoverflow.com/questions/20511347/a-good-hash-function-for-a-vector.
        std::size_t operator()(const std::unordered_set<T, H> &set) const {
            std::size_t seed = set.size();
            for(auto &i : set) {
                seed ^= hashEl(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
};

struct Action {
        string str() {
            if (!initialized) {
                return "// ERROR: not initialized";
            }
            return _str();
        };

        void initialize() {
            _initialize();
            initialized = true;
        }

        virtual bool operator !=(const Action &other) = 0;

        virtual ~Action() {}
    private:
        bool initialized = false;
        virtual string _str() = 0;
        virtual void _initialize() = 0;
};

struct ShiftAction : public Action {
        ShiftAction(const unordered_set<Item, hash_item> &states) : states{states} {}

        bool operator !=(const Action &other) {
            if(auto* o = dynamic_cast<const ShiftAction *>(&other)) {
                return o->states == states;
            }
            return false;
        }
    private:
        size_t state;
        unordered_set<Item, hash_item> states;

        virtual string _str() {
            ostringstream oss;
            oss << "state = " << state << ";" << endl;
            //oss << "state.push(new LRNode{cur.})"
            oss << R"action(state = stoi((*transition)[2]);
stack.push(new LRNode{cur.getVocab(), cur.getLexeme()});
stack.push(new LRNode{state});
// TODO fix
++count;)action";
            return oss.str();
        }

        virtual void _initialize() {}
};

struct ReduceAction : public Action {
        ReduceAction(const string &name, size_t ruleIndex) : name{name}, ruleIndex{ruleIndex} {}

        bool operator !=(const Action &other) {
            if(auto* o = dynamic_cast<const ReduceAction *>(&other)) {
                return o->ruleIndex == ruleIndex;
            }
            return false;
        }
    private:
        string name;
        size_t ruleIndex;

        virtual string _str() {
            ostringstream oss;
            
            oss << R"action(peeked = true;" << endl;
            auto &rule = eof ? rules[0] : rules[stoi((*transition)[2])];

            // Build rule string.
            string ruleString;
            for (size_t i = 1; i < rule.size(); ++i) {
                if (i != 1) ruleString += " ";
                ruleString += rule[i];
            }
            LRNode *newParent = new LRNode{rule[0], ruleString};

            for (size_t i = 0; i < rule.size() - 1; ++i) {
                if (stack.size() < 2) {
                    cerr << "ERROR at " << count << endl;
                    break;
                }
                delete stack.top(); // Delete state node.
                stack.pop(); // Pop deleted state.
                auto *child = stack.top();
                newParent->addChild(child);
                stack.pop(); // Pop vocabulary.
            }

            state = stack.top()->getState();
            stack.push(newParent);

            if (!stack.top()->isState() && stack.top()->getVocab() == start) {
                // Success!
                success = true;
                break;
            }

            transition = nullptr;
            for (auto &t : transitions[state]) {
                if (t[0] != rule[0]) {
                    continue;
                }
                // We've found our rule.
                transition = &t;
            }
            if (!transition) {
                cerr << "ERROR at " << count << endl;
                break;
            }

            state = stoi((*transition)[2]);
            stack.push(new LRNode{state});)action" << endl;
            return oss.str();
        }

        virtual void _initialize() {}
};

class Grammar {
        unordered_map<string, vector<vector<string>>> rules;
        string start;
        unordered_set<string> nonterminals;
        unordered_set<string> terminals;
        unordered_map<string, unordered_set<string>> follow;
        unordered_set<Item, hash_item> initialState;
        unordered_map<pair<unordered_set<Item, hash_item>, string>, Action *, hash_pair<unordered_set<Item, hash_item>, string, hash_set<Item, hash_item>>> table;

        bool auxTablesComputed = false;

        bool allNullable(
            const unordered_set<string> &nullable,
            const vector<string> &listOfVocabToCheck,
            size_t checkStart,
            size_t checkEnd
        ) {
            bool result = true;
            for (int i = checkStart; i < checkEnd; i++) {
                if (nullable.find(listOfVocabToCheck[i]) == nullable.end()) {
                    result = false;
                }
            }
            return result;
        }

        void computeFollowTable() {
            unordered_set<string> nullable;
            unordered_map<string, unordered_set<string>> first;

            for (auto &terminal : terminals) {
                first[terminal].insert(terminal);
            }

            bool changed;
            do {
                changed = false;
                for (auto &rule : rules) {
                    for (auto &rhs : rule.second) {
                        size_t rhsSize = rhs.size();
                        if (allNullable(nullable, rhs, 0, rhsSize) && nullable.find(rule.first) == nullable.end()) {
                            nullable.insert(rule.first);
                            changed = true;
                        }
                        for (size_t i = 0; i < rhsSize; i++) {
                            if (allNullable(nullable, rhs, 0, i)) {
                                for (auto &rhsEl : first[rhs[i]]) {
                                    if (first[rule.first].find(rhsEl) == first[rule.first].end()) {
                                        first[rule.first].insert(rhsEl);
                                        changed = true;
                                    }
                                }
                            }

                            if (allNullable(nullable, rhs, i + 1, rhsSize)) {
                                for (auto &lhsEl : follow[rule.first]) {
                                    if (follow[rhs[i]].find(lhsEl) == follow[rhs[i]].end()) {
                                        follow[rhs[i]].insert(lhsEl);
                                        changed = true;
                                    }
                                }
                            }
                            for (int j = i + 1; j < rhsSize; j++) {
                                if (allNullable(nullable, rhs, i + 1, j)) {
                                    for (auto &rhsEl : first[rhs[j]]) {
                                        if (follow[rhs[i]].find(rhsEl) == follow[rhs[i]].end()) {
                                            follow[rhs[i]].insert(rhsEl);
                                            changed = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            } while (changed);

            auxTablesComputed = true;
        }
        
        unordered_set<Item, hash_item> closure(unordered_set<Item, hash_item> statesToClose) {
            while (true) {
                bool changed = false;
                unordered_set<Item, hash_item> prevStates{statesToClose};
                for (auto &item : prevStates) {
                    if (!item.hasNext()) continue;
                    string symbol = item.next();
                    if (terminals.find(symbol) != terminals.end()) continue;

                    size_t rhsIndex = 0;
                    for (auto &rule : rules[symbol]) {
                        statesToClose.emplace(rule, symbol, rhsIndex++);
                        changed = true;
                    }
                }
                // If the set is unchanged for one iteration, return.
                if (!changed) return statesToClose;
            }
        }
        
        unordered_set<Item, hash_item> gotoFromSymbol(const unordered_set<Item, hash_item> &itemsInCurrentState, const string &nextSym) {
            unordered_set<Item, hash_item> nextItems;
            for (auto &item : itemsInCurrentState) {
                if (!item.hasNext()) {
                    continue;
                }
                if (item.next() != nextSym) {
                    continue;
                }
                nextItems.emplace(item.advance());
            }
            return closure(nextItems);
        }

        // Return values: -1 => error, 0 => no action, 1 => added
        int addAction(const unordered_set<Item, hash_item> &stateItems, const string &nextSym, Action *paramAction) {
            int retVal = 0;
            pair<unordered_set<Item, hash_item>, string> pair{stateItems, nextSym};
            auto *action = table[pair];
            if (action != nullptr && *action != *paramAction) {
                cerr << "Conflict on symbol " << nextSym << " in state ";
                printSet(stateItems);
                cerr << endl;
                retVal = -1;
            } else {
                if (action == nullptr) {
                    retVal = 1;
                }
                table[pair] = paramAction;
            }

            return retVal;
        }

        bool computeAutomatonTable() {
            unordered_set<Item, hash_item> startItems;
            size_t rhsIndex = 0;
            for (auto &rule : rules[start]) {
                startItems.emplace(rule, start, rhsIndex++);
            }
            initialState = closure(startItems);
            unordered_set<unordered_set<Item, hash_item>, hash_set<Item, hash_item>> seenStates;
            seenStates.insert(initialState);

            bool changed;
            do {
                changed = false;
                unordered_set<unordered_set<Item, hash_item>, hash_set<Item, hash_item>> newSeenStates;
                for (unordered_set<Item, hash_item> stateItems : seenStates) {
                    for (auto &item : stateItems) {
                        if (!item.hasNext()) continue;
                        string nextSym = item.next();
                        unordered_set<Item, hash_item> statesFromCurrentItemNextSym = gotoFromSymbol(stateItems, nextSym);

                        auto oldSize = newSeenStates.size();
                        newSeenStates.emplace(statesFromCurrentItemNextSym);
                        if (newSeenStates.size() != oldSize){
                            changed = true;
                        }
                        if (addAction(stateItems, nextSym, new ShiftAction(statesFromCurrentItemNextSym))) changed = true;
                    }
                }
                for (auto &items : newSeenStates) {
                    seenStates.emplace(items);
                }
            } while (changed);

            for (auto &items : seenStates) {
                for (auto &item : items) {
                    if (item.hasNext()) continue;
                    for (auto &str : follow[item.name()]) {
                        addAction(items, str, new ReduceAction(item.name(), item.ruleIndex()));
                    }
                }
            }
        }

        bool computeAuxTables() {
            computeFollowTable();
            return true;//computeAutomatonTable();
        }

        friend istream &operator>>(istream &, Grammar &);
    public:
        bool validate() {
            nonterminals.clear();
            terminals.clear();

            for (auto &entry : rules) {
                nonterminals.insert(entry.first);
            }

            for (auto &entry : rules) {
                for (auto &rule : entry.second) {
                    for (auto &symbol : rule) {
                        if (nonterminals.find(symbol) == nonterminals.end()) {
                            terminals.insert(symbol);
                        }
                    }
                }
            }

            cerr << "Found the following nonterminal symbols:" << endl;
            printSet(nonterminals);

            cerr << "Assuming the following are terminal symbols:" << endl;
            printSet(terminals);

            return computeAuxTables();
        }
};

istream &operator >>(istream &is, Grammar &grammar) {
    string line;
    bool startSet = false;
    while (getline(is, line)) {
        istringstream iss{line};
        string lhs;
        vector<string> rhs;
        string rhsPart;
        iss >> lhs;
        while (iss >> rhsPart) {
            if (!rhsPart.size()) {
                break;
            }
            rhs.emplace_back(rhsPart);
        }

        if (!startSet) {
            startSet = true;
            grammar.start = lhs;
        }

        grammar.rules[lhs].emplace_back(rhs);
    }
    return is;
}

ostream &operator <<(ostream &os, Grammar &grammar) {
    cout << R"(// This file was automatically generated; please do not modify it.

#include "./parser.hpp"

#include <stack>

#include "./parse_node.hpp"

using namespace std;

int parse(const std::vector<Token> &tokens, ParseNode *& tree) {
    size_t state = 0;
    size_t count = 0;
    stack<LRNode *> stack;
    stack.push(new LRNode{0});
    bool peeked = true;
    bool eofHit = false;
    bool success = false;
    LRNode cur{"BOF", "BOF"};
    while (true) {
        bool eof = false;
        if (!peeked) {
            if (!(cin >> buf)) {
                if (eofHit) {
                    eof = true;
                } else {
                    cur = {"EOF", "EOF"};
                    eofHit = true;
                }
            } else {
                string name = buf;
                cin >> buf;
                cur = {name, buf};
            }
        }
        peeked = false;

        vector<string> *transition = <transition for cur state and vocab>;

        switch (state) {)" << endl;

        //for (auto &transition : grammar.transitions) {
            // TODO locate right Action
        //    cout << action.str() << endl;
        //}

        cout << R"(        }
        if (!eof && (*transition)[1] == "shift") {
            state = stoi((*transition)[2]);
            stack.push(new LRNode{cur.getVocab(), cur.getLexeme()});
            stack.push(new LRNode{state});

            ++count;
        } else {
            peeked = true;
            auto &rule = eof ? rules[0] : rules[stoi((*transition)[2])];

            // Build rule string.
            string ruleString;
            for (size_t i = 1; i < rule.size(); ++i) {
                if (i != 1) ruleString += " ";
                ruleString += rule[i];
            }
            LRNode *newParent = new LRNode{rule[0], ruleString};

            for (size_t i = 0; i < rule.size() - 1; ++i) {
                if (stack.size() < 2) {
                    cerr << "ERROR at " << count << endl;
                    break;
                }
                delete stack.top(); // Delete state node.
                stack.pop(); // Pop deleted state.
                auto *child = stack.top();
                newParent->addChild(child);
                stack.pop(); // Pop vocabulary.
            }

            state = stack.top()->getState();
            stack.push(newParent);

            if (!stack.top()->isState() && stack.top()->getVocab() == start) {
                // Success!
                success = true;
                break;
            }

            transition = nullptr;
            for (auto &t : transitions[state]) {
                if (t[0] != rule[0]) {
                    continue;
                }
                // We've found our rule.
                transition = &t;
            }
            if (!transition) {
                cerr << "ERROR at " << count << endl;
                break;
            }

            state = stoi((*transition)[2]);
            stack.push(new LRNode{state});
        }
    }

    // Build parse tree from LRNode tree.
    // TODO augment LRNode class with ParseNode nodes for efficiency.

    return 0;
})" << endl;

    //for (auto &transition : grammar.transitions) {
    //    cout << "something" << endl;
    //}

    return os;
}

int main() {
    Grammar grammar;
    cin >> grammar;
    if (!grammar.validate()) {
        return -1;
    }
    cout << grammar;
}