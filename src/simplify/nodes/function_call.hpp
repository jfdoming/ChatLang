#pragma once

#include <string>

#include "../ast_node.hpp"

struct FunctionCallNode : public ASTNode {
    FunctionCallNode() : ASTNode{NonterminalType::fncall} {}

    virtual Value *interpret(Environment &env, short caller = 0) const {
        Value *value;
        Value *params;
        if (children.size() == 3) {
            // Parameters provided.
            params = children[1]->interpret(env);
        }
        
        int retval;
        if (children[0]->isTerminal()) {
            retval = env.invoke(children[0]->getLexeme(), value);
        } else {
            retval = env.invoke(children[0]->interpret(env));
        }

        if (retval || !*value) {
            cerr << "Uh-oh! An internal error occurred while interpreting your program. This is probably a bug..." << endl;
            delete value;
            return new Value;
        }
        return value;
    }
};