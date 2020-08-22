#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int parse() {
    // win for wlp4-in
    ifstream win{"wlp4in.lr1"};

    string buf;
    size_t count;

    // Read terminal symbols.
    vector<string> term;
    if (!getline(win, buf)) {
        cerr << "ERROR at 0" << endl;
        return 1;
    }
    count = stoi(buf);
    for (size_t i = 0; i < count; ++i) {
        if (!getline(win, buf)) {
            cerr << "ERROR at 0" << endl;
            return 1;
        }
        term.emplace_back(buf);
    }

    // Read non-terminal symbols.
    vector<string> nonterm;
    if (!getline(win, buf)) {
        cerr << "ERROR at 0" << endl;
        return 1;
    }
    count = stoi(buf);
    for (size_t i = 0; i < count; ++i) {
        if (!getline(win, buf)) {
            cerr << "ERROR at 0" << endl;
            return 1;
        }
        nonterm.emplace_back(buf);
    }

    string start;
    if (!getline(win, start)) {
        cerr << "ERROR at 0" << endl;
        return 1;
    }

    // Read rules.
    vector<vector<string>> rules;
    if (!getline(win, buf)) {
        cerr << "ERROR at 0" << endl;
        return 1;
    }
    count = stoi(buf);
    for (size_t i = 0; i < count; ++i) {
        if (!getline(win, buf)) {
            cerr << "ERROR at 0" << endl;
            return 1;
        }
        istringstream iss{buf};
        vector<string> rule;
        while (iss >> buf) {
            rule.emplace_back(buf);
        }
        rules.emplace_back(rule);
    }

    if (!getline(win, buf)) {
        cerr << "ERROR at 0" << endl;
        return 1;
    }

    size_t nTransitions;
    if (!getline(win, buf)) {
        cerr << "ERROR at 0" << endl;
        return 1;
    }
    nTransitions = stoi(buf);

    unordered_map<int, vector<vector<string>>> transitions;
    for (size_t i = 0; i < nTransitions; ++i) {
        if (!getline(win, buf)) {
            cerr << "ERROR at 0" << endl;
            return 1;
        }
        istringstream iss{buf};
        vector<string> transition;
        size_t state;
        if (!(iss >> state)) {
            cerr << "ERROR at 0" << endl;
            return 1;
        }
        while (iss >> buf) {
            transition.emplace_back(buf);
        }
        transitions[state].emplace_back(transition);
    }

    size_t state = 0;
    count = 0;
    stack<StackEl *> stack;
    stack.push(new StackEl{0});
    bool peeked = true;
    bool eofHit = false;
    bool success = false;
    StackEl cur{"BOF", "BOF"};
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

        vector<string> *transition = nullptr;
        if (!eof) {
            for (auto &t : transitions[state]) {
                if (t[0] != cur.getVocab()) {
                    continue;
                }
                // We've found our rule.
                transition = &t;
            }
            if (!transition) {
                cerr << "ERROR at " << count << endl;
                break;
            }
        }

        if (!eof && (*transition)[1] == "shift") {
            state = stoi((*transition)[2]);
            stack.push(new StackEl{cur.getVocab(), cur.getLexeme()});
            stack.push(new StackEl{state});

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
            StackEl *newParent = new StackEl{rule[0], ruleString};

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
            stack.push(new StackEl{state});
        }
    }

    if (success) {
        // Print pre-order traversal.
        cout << *stack.top();
    }

    // Clean up memory.
    while (!stack.empty()) {
        delete stack.top();
        stack.pop();
    }

    return 0;
}
