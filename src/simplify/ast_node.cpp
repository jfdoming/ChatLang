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

NonterminalType ASTNode::getNonterminal() const {
    return nonterminal;
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
                if (result && !result->isAutoDelete()) {
                    delete result;
                }
                result = next;
            }
        }
    }

    // Return the last value seen.
    return result;
}

ostream &operator<<(ostream &out, const ASTNode &el) {
    if (el.isTerminal()) {
        out << el.terminal.str() << endl;
    } else {
        out << el.nonterminal.str() << endl;
    }
    for (auto *child : el.children) {
        out << *child;
    }
    out << "--" << endl;
    return out;
}
