#pragma once

#include <string>

#include "../ast_node.hpp"

struct BinaryOperatorNode : public ASTNode {
    BinaryOperatorNode() : ASTNode{NonterminalType::expr} {}

    virtual Value *interpret(Environment &env, short caller = 0) const {
        if (children.size() != 3) {
            cerr << "Uh-oh! An internal error occurred while interpreting your program. This is probably a bug..." << endl;
            return new Value;
        }

        Value *result;
        Value *leftValue = children[0]->interpret(env);
        Value *rightValue = children[2]->interpret(env);
        switch (children[1]->getTerminal()) {
            case TokenType::PLUS:
                result = *leftValue + *rightValue;
                break;
            case TokenType::MINUS:
                result = *leftValue - *rightValue;
                break;
            default:
                cerr << "Uh-oh! An internal error occurred while interpreting your program. This is probably a bug..." << endl;
                delete leftValue;
                delete rightValue;
                return new Value;
        }
        delete leftValue;
        delete rightValue;
        return result;
    }
};