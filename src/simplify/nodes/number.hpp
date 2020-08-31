#pragma once

#include <string>

#include "../ast_node.hpp"

struct NumberNode : public ASTNode {
    NumberNode(const std::string &lexeme) : ASTNode{TokenType::NUM, lexeme} {}

    virtual Value *interpret(Environment &env, short caller = 0) const {
        return new Value{stod(lexeme, nullptr)};
    }
};