#include <iostream>
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
        if (i == item.pos) {
            out << " .";
        }
        out << " " << item.rule[i];
    }
    if (item.pos == item.rule.size()) {
        out << " .";
    }
    return out;
}

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
    virtual string str(bool nonterminal = false) = 0;
    virtual bool operator !=(const Action &other) = 0;

    virtual ~Action() {}
};

class IAutomatonResult {
    public:
        unordered_map<unordered_set<Item, hash_item>, size_t, hash_set<Item, hash_item>> stateSetToIndex;

        virtual ~IAutomatonResult() {}
};

struct ShiftAction : public Action {
        ShiftAction(IAutomatonResult *grammar, const unordered_set<Item, hash_item> &nextState) : grammar{grammar}, nextState{nextState} {}

        bool operator !=(const Action &other) {
            if(auto* o = dynamic_cast<const ShiftAction *>(&other)) {
                return o->nextState != nextState;
            }
            return false;
        }

        virtual string str(bool nonterminal = false) {
            ostringstream oss;
            if (nonterminal) {
                oss << "                            state.shiftNT(" << grammar->stateSetToIndex.at(nextState) << ");" << endl;
            } else {
                oss << "                            state.shift(" << grammar->stateSetToIndex.at(nextState) << ");" << endl;
            }
            return oss.str();
        }
    private:
        IAutomatonResult *grammar;
        unordered_set<Item, hash_item> nextState;
};

struct ReduceAction : public Action {
        ReduceAction(const string &name, const vector<string> &rule, size_t ruleIndex) : name{name}, rule{rule}, ruleIndex{ruleIndex} {}

        bool operator !=(const Action &other) {
            if(auto* o = dynamic_cast<const ReduceAction *>(&other)) {
                return o->ruleIndex != ruleIndex;
            }
            return false;
        }

        virtual string str(bool) {
            ostringstream oss;
            oss << "                            state.reduce(" << rule.size() << ", NonterminalType::" << name << ");" << endl;
            return oss.str();
        }
    private:
        string name;
        vector<string> rule;
        size_t ruleIndex;
};

struct ShiftAction;

class Grammar : public IAutomatonResult {
        string start;
        unordered_set<string> nonterminals;
        unordered_set<string> terminals;
        unordered_map<string, vector<vector<string>>> rules;
        unordered_map<string, unordered_set<string>> follow;
        unordered_set<Item, hash_item> initialState;
        vector<unordered_map<string, unordered_set<string>>> transitions;

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
                    size_t oldSize = statesToClose.size();
                    for (auto &rule : rules[symbol]) {
                        statesToClose.emplace(rule, symbol, rhsIndex++);
                    }
                    if (oldSize != statesToClose.size()) {
                        changed = true;
                    }
                }
                // If the set is unchanged for one iteration, return.
                if (!changed) return statesToClose;
            }
            return statesToClose;
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
        int addAction(unordered_map<unordered_set<Item, hash_item>, unordered_map<string, Action *>, hash_set<Item, hash_item>> &transitionTable, const unordered_set<Item, hash_item> &stateItems, const string &nextSym, Action *paramAction) {
            int retVal = 0;
            auto *action = transitionTable[stateItems][nextSym];
            if (action != nullptr && *action != *paramAction) {
                cerr << "Conflict on symbol " << nextSym << " in state ";
                printSet(stateItems);
                cerr << "Perhaps you have a duplicate rule?" << endl;
                cerr << endl;
                retVal = -1;

                delete paramAction;
            } else {
                if (action == nullptr) {
                    transitionTable[stateItems][nextSym] = paramAction;
                    retVal = 1;
                } else {
                    delete paramAction;
                }
            }

            return retVal;
        }

        bool computeAutomatonTable() {
            unordered_map<unordered_set<Item, hash_item>, unordered_map<string, Action *>, hash_set<Item, hash_item>> transitionTable;

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
                unordered_set<unordered_set<Item, hash_item>, hash_set<Item, hash_item>> newSeenStates{seenStates};
                for (unordered_set<Item, hash_item> stateItems : seenStates) {
                    for (auto &item : stateItems) {
                        if (!item.hasNext()) continue;
                        string nextSym = item.next();
                        unordered_set<Item, hash_item> statesFromCurrentItemNextSym = gotoFromSymbol(stateItems, nextSym);

                        auto oldSize = newSeenStates.size();
                        newSeenStates.emplace(statesFromCurrentItemNextSym);
                        if (newSeenStates.size() != oldSize) {
                            changed = true;
                        }
                        int addResult = addAction(transitionTable, stateItems, nextSym, new ShiftAction(this, statesFromCurrentItemNextSym));
                        if (addResult == -1) {
                            return false;
                        }
                        if (addResult == 1) {
                            changed = true;
                        }
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
                        if (addAction(transitionTable, items, str, new ReduceAction(item.name(), rules[item.name()][item.ruleIndex()], item.ruleIndex())) == -1) {
                            return false;
                        }
                    }
                }
            }

            // Eliminate the map from sets to maps since it's unnecessarily complex.
            size_t stateIndex = 0;
            for (auto &state : seenStates) {
                stateSetToIndex[state] = stateIndex++;
            }
            for (auto &state : seenStates) {
                unordered_map<string, unordered_set<string>> tempTransition;
                for (auto &transition: transitionTable[state]) {
                    if (nonterminals.find(transition.first) != nonterminals.end()) {
                        tempTransition[transition.second->str(true)].insert(transition.first);
                    }
                    if (terminals.find(transition.first) != terminals.end()) {
                        tempTransition[transition.second->str()].insert(transition.first);
                    }
                }
                transitions.emplace_back(tempTransition);
            }

            return true;
        }

        bool computeAuxTables() {
            computeFollowTable();
            return computeAutomatonTable();
        }

        friend istream &operator >>(istream &, Grammar &);
        friend ostream &operator <<(ostream &, Grammar &);
    public:
        void computeVocabulary() {
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
        }
        bool validate() {
            computeVocabulary();

            cerr << "Found the following nonterminal symbols:" << endl;
            printSet(nonterminals);

            cerr << "Assuming the following are terminal symbols:" << endl;
            printSet(terminals);

            return computeAuxTables();
        }

        void printVocabulary(ostream &out) {
            out << "// This file was automatically generated; please do not modify it." << endl;
            out << "\n#define NT_TYPES \\" << endl;
            bool first = true;
            for (auto &word : nonterminals) {
                if (first) {
                    first = false;
                } else {
                    out << " \\\n";
                }
                out << "X(" << word << ")";
            }
            out << endl;
        }

        ~Grammar() {
            for (auto &stateEntry : transitions) {
                for (auto &transitionEntry : stateEntry) {
                    //delete transitionEntry.first;
                }
            }
        }
};

istream &operator >>(istream &is, Grammar &grammar) {
    string line;
    bool startSet = false;
    while (getline(is, line)) {
        if (!line.size() || line[0] == '#') {
            // Rudimentary comment.
            continue;
        }

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
    size_t initialState = grammar.stateSetToIndex.at(grammar.initialState);

    cout << R"(// This file was automatically generated; please do not modify it.

#include "./parser.hpp"

#include "./parse_state.hpp"
#include "./nt_types.hpp"

using namespace std;

int parse(const std::vector<Token> &tokens, std::vector<std::string> *lines, LRNode *& tree) {)" << endl;
    cout << "    ParseState state{" << initialState << ", NonterminalType::" << grammar.start << ", lines};" << endl;
    cout << R"(    while (!state.done) {
        bool eof = false;
        if (!state.peeked) {
            if (state.curPos >= tokens.size()) {
                if (!eof) {
                    state.cur = Token{TokenType::E0F, "", 0, 0};
                    eof = true;
                }
            } else {
                state.cur = tokens[state.curPos];
                ++state.curPos;
            }
        }
        state.peeked = false;

        if (state.cur.isTerminal()) {
            switch (state.state) {)" << endl;

        // Terminals
        for (size_t state = 0; state < grammar.transitions.size(); ++state) {
            cout << "                case " << state << ":" << endl;
            if (grammar.transitions[state].size()) {
                cout << "                    switch (state.cur.getTerminal().type) {" << endl;
                for (auto &symbolEntry : grammar.transitions[state]) {
                    bool writtenCase = false;
                    for (auto &s: symbolEntry.second) {
                        if (grammar.terminals.find(s) != grammar.terminals.end()) {
                            writtenCase = true;
                            cout << "                        case TokenType::" << s << ":" << endl;
                        }
                    }
                    if (writtenCase) {
                        cout << symbolEntry.first << "                            break;" << endl;
                    }
                }
                cout << "                        default:" << endl;
                cout << "                            state.fail();" << endl;
                cout << "                    }" << endl;
            } else {
                // Assume we have an accepting state!
                cout << R"action(                    if (state.cur.isTerminal()) {
                        state.reduce()action" << grammar.rules[grammar.start][0].size() << ", NonterminalType::" << grammar.start << R"action();
                    })action" << endl;
            }
            cout << "                    break;" << endl;
        }

        cout << "            }" << endl;
        cout << "        } else {" << endl;
        cout << "            switch (state.state) {" << endl;

        // Nonterminals
        for (size_t state = 0; state < grammar.transitions.size(); ++state) {
            cout << "                case " << state << ":" << endl;
            if (grammar.transitions[state].size()) {
                cout << "                    switch (state.cur.getNonterminal()) {" << endl;
                for (auto &symbolEntry : grammar.transitions[state]) {
                    bool writtenCase = false;
                    for (auto &t: symbolEntry.second) {
                        if (grammar.nonterminals.find(t) != grammar.nonterminals.end()) {
                            writtenCase = true;
                            cout << "                        case NonterminalType::" << t << ":" << endl;
                        }
                    }
                    if (writtenCase) {
                        cout << symbolEntry.first << "                            break;" << endl;
                    }
                }
                cout << "                        default:" << endl;
                cout << "                            state.fail();" << endl;
                cout << "                    }" << endl;
            }
            cout << "                    break;" << endl;
        }

        cout << R"(                default:
                    state.error();
            }
        }
    }

    return state.storeResult(tree);
})" << endl;

    return os;
}

int main(int argc, char **argv) {
    bool printNTEnum = false;
    string ntFlag = "--nt-only";
    for (size_t i = 0; i < argc; ++i) {
        if (argv[i] == ntFlag) {
            printNTEnum = true;
        }
    }

    Grammar grammar;
    cin >> grammar;
    if (printNTEnum) {
        grammar.computeVocabulary();
        grammar.printVocabulary(cout);
    } else {
        if (!grammar.validate()) {
            return -1;
        }
        cout << grammar;

        cerr << "Automaton built." << endl;
    }
}
