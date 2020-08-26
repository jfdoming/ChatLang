#pragma once

#include <stack>

#include "./lr_node.hpp"
#include "./nt_types.hpp"

struct ParseState {
        size_t state;
        size_t curPos = 0;
        LRNode cur{TokenType::B0F, ""};
        bool peeked = true;
        bool done = false;
        bool success = false;

        ParseState(size_t state, NonterminalType::Type start) : state{state}, start{start} {
            nodeStack.push(new LRNode{17});
        }
        void shift(size_t state) {
            this->state = state;
            nodeStack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
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
                    break;
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
            cerr << "Misplaced token " << cur.getTerminal().str() << " with error code " << state << endl;
            done = true;
        }
    
    private:
        stack<LRNode *> nodeStack;
        NonterminalType::Type start;
};