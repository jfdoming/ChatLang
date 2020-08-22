#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "../scan/token_types.hpp"

using namespace std;

struct LRNode {
        LRNode(size_t state) : state{state}, holdsState{true}, holdsTerminal{false} {}
        LRNode(string nonterminal, string lexeme) : nonterminal{nonterminal}, lexeme{lexeme}, holdsState{false}, holdsTerminal{false} {}
        LRNode(const TokenType &type, string lexeme) : terminal{type}, holdsState{false}, holdsTerminal{true} {}
        ~LRNode() {
            for (auto &child : children) {
                delete child;
            }
        }

        void addChild(LRNode *child) {
            children.emplace(children.begin(), child);
        };
        size_t getState() const { return state; }
        string getNonterminal() const { return nonterminal; }
        string getTerminal() const { return terminal; }
        string getLexeme() const { return lexeme; }
        bool isState() const { return holdsState; }
        bool isTerminal() const { return holdsTerminal; }

        friend ostream &operator<<(ostream &, const LRNode &);
    private:
        size_t state;
        string nonterminal;
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
        out << el.getNonterminal() << " " << el.getLexeme() << endl;
        for (auto *child : el.children) {
            out << *child;
        }
    }
    return out;
}
