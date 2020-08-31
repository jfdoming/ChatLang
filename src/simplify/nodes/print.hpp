#pragma once

#include "../ast_node.hpp"

struct PrintNode : public ASTNode {
    PrintNode() : ASTNode{NonterminalType::fn} {}
    virtual Value *interpret(Environment &env, short caller = 0) const {
        if (!caller) {
            return new Value{this, {"arg"}};
        }
        Value *value;
        int retval = env.get("arg", value);
        if (retval || !*value) {
            cout << endl;
        } else {
            cout << value.str() << endl;
        }
        return new Value{0};
    }
};