#pragma once

#include <stack>

#include "./lr_node.hpp"
#include "./nt_types.hpp"

struct ParseState {
        size_t state;
        size_t curPos = 0;
        LRNode cur{Token{TokenType::B0F, "", 0, 0}};
        bool peeked = true;
        bool done = false;
        bool success = false;

        ParseState(size_t state, NonterminalType::Type start, std::vector<std::string> *lines) : state{state}, start{start}, lines{lines} {
            nodeStack.push(new LRNode{17});
        }
        void shift(size_t state) {
            this->state = state;
            nodeStack.push(new LRNode{cur.getTerminal()});
            nodeStack.push(new LRNode{state});
        }
        void shiftNT(size_t state) {
            this->state = state;
            peeked = true;
            cur = *(nodeStack.top());
            delete nodeStack.top();
            nodeStack.pop();
            nodeStack.push(new LRNode{state});
        }
        void reduce(size_t count, NonterminalType::Type type) {
            peeked = true;

            LRNode *newParent = new LRNode{type};
            for (size_t i = 0; i < count; ++i) {
                if (nodeStack.size() < 2) {
                    cerr << "ERROR at " << curPos << endl;
                    done = true;
                    return;
                }
                delete nodeStack.top(); // Delete state node.
                nodeStack.pop(); // Pop deleted state.
                auto *child = nodeStack.top();
                newParent->addChild(child);
                nodeStack.pop(); // Pop vocabulary.
            }
            state = nodeStack.top()->getState();
            nodeStack.push(newParent);

            LRNode *top = nodeStack.top();
            if (!top->isState() && !top->isTerminal() && top->getNonterminal() == start) {
                // Success!
                success = true;
                done = true;
            } else {
                nodeStack.push(new LRNode{cur});
                cur = {type};
            }
        }
        void error() {
            cerr << "Code 2-" << state << ": internal error" << endl;
            done = true;
        }
        void fail() {
            cerr << ":" << (cur.getTerminal().lineNumber + 1) << ":" << (cur.getTerminal().position + 1) << ": Misplaced token " << cur.getTerminal().type.str() << " with error code " << state << endl;
            cerr << (*lines)[cur.getTerminal().lineNumber] << endl;
            cerr << string(cur.getTerminal().position, ' ') << "^" << endl;
            done = true;
        }

        int storeResult(LRNode *&tree) {
            tree = nodeStack.top();
            nodeStack.pop();

            while (!nodeStack.empty()) {
                delete nodeStack.top();
                nodeStack.pop();
            }

            if (!success) {
                delete tree;
                tree = nullptr;
                return -1;
            }

            return 0;
        }

    private:
        stack<LRNode *> nodeStack;
        NonterminalType::Type start;
        vector<string> *lines;
};
