#pragma once

#include <string>

#include "../ast_node.hpp"

struct FunctionCallNode : public ASTNode {
    FunctionCallNode() : ASTNode{NonterminalType::fncall} {}

    virtual Value interpret(Environment &env, short caller = 0) const {
        Value value{nullptr};
        Value args{nullptr};
        if (children.size() == 4) {
            // Parameters provided.
            args = children[2]->interpret(env);
            if (!args) {
                return args;
            }
        }
        
        int retval;
        if (children[0]->isTerminal()) {
            retval = env.invoke(children[0]->getLexeme(), args, value);
        } else {
            retval = env.invoke(children[0]->interpret(env), args, value);
        }

        if (retval || !value) {
            // This is probably not a bug.
            return {};
        }
        return value;
    }
};
