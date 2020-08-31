#include "./ast_node.hpp"
#include "../scan/token_types.hpp"
#include "../parse/nt_types.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

using namespace std;

ASTNode::ASTNode(const NonterminalType::Type &nonterminal) : nonterminal{nonterminal}, holdsTerminal{false} {}

ASTNode::ASTNode(const TokenType &type, string lexeme) : terminal{type}, lexeme{lexeme}, holdsTerminal{true} {}

ASTNode::~ASTNode() {
    for (auto *child : children) {
        delete child;
    }
}

void ASTNode::addChild(ASTNode *child) {
    children.emplace_back(child);
};

string ASTNode::getLexeme() const { return lexeme; }

TokenType ASTNode::getTerminal() const {
    return terminal;
}

bool ASTNode::isTerminal() const { return holdsTerminal; }

// Default behaviour.
Value *ASTNode::interpret(Environment &env, short) const {
    Value *result = nullptr;
    for (auto *child : children) {
        if (child) {
            Value *next = child->interpret(env);
            if (next) {
                if (!*next) {
                    return next;
                }
                delete result;
                result = next;
            }
        }
    }

    // Return the last value seen.
    return result;
}

ostream &operator<<(ostream &out, const ASTNode &el) {
    if (el.isTerminal()) {
        cerr << el.terminal.str() << endl;
    } else {
        cerr << el.nonterminal.str() << endl;
    }
    for (auto *child : el.children) {
        out << *child;
    }
    return out;
}
