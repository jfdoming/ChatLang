#pragma once

#include <string>
#include <vector>

#include "token_types.hpp"

class Token {
    public:
        TokenType type;
        std::string lexeme;
        size_t lineNumber;
        size_t position;

        Token() {}
        Token(TokenType type, const std::string &lexeme, size_t lineNumber, size_t position) : type{type}, lexeme{lexeme}, lineNumber{lineNumber}, position{position} {}
};

int tokenize(const std::string &input, size_t lineNumber, std::vector<Token> &tokens);