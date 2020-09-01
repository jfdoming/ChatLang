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
            /*Value *args = nullptr;
            if (children.size() == 6) {
                args = children[1]->interpret(env);
            }*/
            return new Value{procChild, {}};
        }

        cerr << children.size() << endl;
        cerr << "Uh-oh! An internal error occurred while interpreting your program. This is probably a bug..." << endl;
        return new Value;
    }
};