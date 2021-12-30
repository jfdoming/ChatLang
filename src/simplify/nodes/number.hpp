#pragma once

#include <string>

#include "../ast_node.hpp"

struct NumberNode : public ASTNode {
        /*NumberNode(const std::string &lexeme) {
            if (lexeme[0] == '-')
            ASTNode = new ASTNode(TokenType::NUM, lexeme);
            value = stod(lexeme, nullptr);
        }*/
        NumberNode(const std::string &lexeme) : ASTNode{TokenType::NUM, lexeme}, value{stod(lexeme, nullptr)} {}

        virtual Value interpret(Environment &env, short caller = 0) const {
            return value;
        }
    private:
        double value;
};
