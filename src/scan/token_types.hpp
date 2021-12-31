#pragma once

#include "../utils/enum.hpp"

#define TOKEN_TYPES(X) \
X(B0F) \
X(E0F) \
X(SYMBOL) \
X(ID) \
X(NUM) \
X(STRING) \
X(PLUS) \
X(MINUS) \
X(STAR) \
X(STARSTAR) \
X(SLASH) \
X(PERCENT) \
X(LPAREN) \
X(RPAREN) \
X(LBRACE) \
X(RBRACE) \
X(LBRACK) \
X(RBRACK) \
X(NEWLINE) \
X(WHITESPACE) \
X(COMMENT) \
X(SEMICOLON) \
X(EQUALS) \
X(COMMA) \
X(EQSIGNAL)

class TokenType {
    DEF_ENUM_CLASS(TokenType, TOKEN_TYPES);
};
