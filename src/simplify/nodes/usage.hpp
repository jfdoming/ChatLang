#pragma once

#include <string>

#include "../ast_node.hpp"

struct UsageNode : public ASTNode {
    UsageNode(const std::string &name) : ASTNode{TokenType::ID, name} {}

    virtual Value interpret(Environment &env, short = 0) const {
        Value value{nullptr};
        int result = env.get(lexeme, value);
        if (result || !value) {
            return {};
        }
        return value;
    }
};
