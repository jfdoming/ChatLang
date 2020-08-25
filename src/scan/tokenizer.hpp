#pragma once

#include <string>
#include <vector>

#include "token_types.hpp"

class Token {
    public:
        TokenType type;
        std::string lexeme;

        Token(TokenType type, const std::string &lexeme) : type{type}, lexeme{lexeme} {}
};

int tokenize(const std::string &input, std::vector<Token> &tokens);