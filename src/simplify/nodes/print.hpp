#pragma once

#include <iostream>

#include "../ast_node.hpp"

struct PrintNode : public ASTNode {
    PrintNode() : ASTNode{NonterminalType::fn} {}
    virtual Value *interpret(Environment &env, short caller = 0) const {
        if (!caller) {
            return new Value{this, {"arg"}};
            return new Value{this, {}};
        }
        Value *value;
        int retval = env.get("arg", value);
        if (retval || !*value) {
            std::cout << std::endl;
        } else {
            std::cout << value->str() << std::flush;
        }
        return new Value{0};
    }
};