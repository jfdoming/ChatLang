#pragma once

#include <string>

#include "../ast_node.hpp"

struct UsageNode : public ASTNode {
    UsageNode(const std::string &name) : ASTNode{TokenType::ID, name} {}

    virtual Value *interpret(Environment &env, short caller = 0) const {
        Value *value;
        int result = env.get(lexeme, value);
        if (result || !value || !*value) {
            return new Value;
        }
        return value;
    }
};
