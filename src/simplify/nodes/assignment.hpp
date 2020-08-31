#pragma once

#include "../ast_node.hpp"

struct AssignmentNode : public ASTNode {
    virtual Value *interpret(Environment &env, short caller = 0) const {
        if (children.size() != 3) {
            cerr << "Uh-oh! An internal error occurred while interpreting your program. This is probably a bug..." << endl;
            return new Value;
        }

        Value result = children[2]->interpret(env);
        if (children[1]->type == TokenType::EQUALS) {
            // Regular assignment.
            env.set(children[0]->interpret(env), result);
        } else if (children[1]->type == TokenType::EQSIGNAL) {
            // Effect assignment.
            env.setEffect(children[0]->interpret(env), result);
        } else {
            cerr << "Uh-oh! An internal error occurred while interpreting your program. This is probably a bug..." << endl;
            return new Value;
        }
        
        return result;
    }
};