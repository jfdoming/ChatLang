#pragma once

#include <string>

#include "../ast_node.hpp"

struct UsageNode : public ASTNode {
    UsageNode(const std::string &name) : ASTNode{TokenType::ID, name} {}

    virtual Value *interpret(Environment &env, short caller = 0) const {
        Value *value = nullptr;
        int result = env.get(lexeme, value);
        cerr << lexeme;
        if (result || !value || !*value) {
            return new Value;
        }
        return new Value(4);
    }
};
