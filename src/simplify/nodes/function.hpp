#pragma once

#include "../ast_node.hpp"

struct FunctionNode : public ASTNode {
    FunctionNode() : ASTNode{NonterminalType::fn} {}
    virtual Value *interpret(Environment &env, short caller = 0) const {
        ASTNode *procChild = nullptr;
        if (children.size() == 3) {
            procChild = children[1];
        } else if (children.size() == 5) {
            procChild = children[3];
        } else if (children.size() == 6) {
            procChild = children[4];
        }

        if (procChild) {
            if (caller) {
                return procChild->interpret(env);
            }
            Value *params = nullptr;
            Value *result;
            if (children.size() == 6) {
                params = children[1]->interpret(env);
                result = new Value{procChild, params->getParams()};
                delete params;
            } else {
                result = new Value{procChild, {}};
            }
            return result;
        }

        cerr << "Uh-oh! An internal error occurred while interpreting your program. This is probably a bug..." << endl;
        return new Value;
    }
};