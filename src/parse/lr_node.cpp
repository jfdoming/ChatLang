#include "./lr_node.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

#include "../scan/token_types.hpp"
#include "../parse/nt_types.hpp"

using namespace std;

LRNode::LRNode(const NonterminalType::Type &nonterminal) : nonterminal{nonterminal}, holdsState{false}, holdsTerminal{false} {}

LRNode::LRNode(const TokenType &type, string lexeme) : terminal{type}, lexeme{lexeme}, holdsState{false}, holdsTerminal{true} {}

LRNode::LRNode(size_t state) : state{state}, holdsState{true}, holdsTerminal{false} {}

LRNode::~LRNode() {
    for (auto &child : children) {
        delete child;
    }
}

void LRNode::addChild(LRNode *child) {
    children.emplace(children.begin(), child);
};

size_t LRNode::getState() const { assert(holdsState); return state; }

NonterminalType LRNode::getNonterminal() const { assert(!(holdsTerminal || holdsState)); return nonterminal; }

TokenType LRNode::getTerminal() const { assert(holdsTerminal); return terminal; }

string LRNode::getLexeme() const { assert(!holdsState); return lexeme; }

bool LRNode::isState() const { return holdsState; }

bool LRNode::isTerminal() const { return holdsTerminal; }

vector<LRNode *> LRNode::getChildren() const {
    return children;
}

ostream &operator<<(ostream &out, const LRNode &el) {
    if (el.isState()) {
        out << "LRNode(STATE:" << el.getState() << ")";
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
