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
            case TokenType::STAR:
                result = *leftValue * *rightValue;
                break;
            case TokenType::SLASH:
                result = *leftValue / *rightValue;
                break;
            case TokenType::STARSTAR:
                result = *leftValue ^ *rightValue;
                break;
            case TokenType::PERCENT:
                result = *leftValue % *rightValue;
                break;
            case TokenType::EQUALS:
                env.set(children[0]->getLexeme(), rightValue);
                // Need to keep previous value around, so short circuit.
                delete leftValue;
                return rightValue;
            case TokenType::EQSIGNAL:
                env.setEffect(children[0]->getLexeme(), rightValue);
                // Need to keep previous value around, so short circuit.
                delete leftValue;
                return rightValue;
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