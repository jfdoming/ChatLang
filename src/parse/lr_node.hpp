#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

#include "../scan/token_types.hpp"
#include "../parse/nt_types.hpp"

using namespace std;

struct LRNode {
        LRNode(const NonterminalType::Type &nonterminal) : nonterminal{nonterminal}, holdsState{false}, holdsTerminal{false} {}
        LRNode(const TokenType &type, string lexeme) : terminal{type}, holdsState{false}, holdsTerminal{true} {}
        explicit LRNode(size_t state) : state{state}, holdsState{true}, holdsTerminal{false} {}
        ~LRNode() {
            for (auto &child : children) {
                delete child;
            }
        }

        void addChild(LRNode *child) {
            children.emplace(children.begin(), child);
        };
        size_t getState() const { assert(holdsState); return state; }
        NonterminalType getNonterminal() const { assert(!(holdsTerminal || holdsState)); return nonterminal; }
        TokenType getTerminal() const { assert(holdsTerminal); return terminal; }
        string getLexeme() const { assert(!holdsState); return lexeme; }
        bool isState() const { return holdsState; }
        bool isTerminal() const { return holdsTerminal; }

        friend ostream &operator<<(ostream &, const LRNode &);
    private:
        size_t state;
        NonterminalType nonterminal;
        TokenType terminal;
        string lexeme;
        bool holdsState;
        bool holdsTerminal;
        vector<LRNode *> children;
};

ostream &operator<<(ostream &out, const LRNode &el) {
    if (el.isState()) {
        out << "LRNode(STATE:" << el.getState();
    } else if (el.isTerminal()) {
        out << el.getTerminal().str() << " " << el.getLexeme() << endl;
        for (auto *child : el.children) {
            out << *child;
        }
    } else {
        out << el.getNonterminal().str() << " " << el.getLexeme() << endl;
        for (auto *child : el.children) {
            out << *child;
        }
    }
    return out;
}
