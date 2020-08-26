#pragma once

#include <cstddef>
#include <unordered_map>
#include <string>

#define TOKEN_TYPES \
X(B0F) \
X(E0F) \
X(SYMBOL) \
X(ID) \
X(NUM) \
X(STRING) \
X(PLUS) \
X(MINUS) \
X(STAR) \
X(SLASH) \
X(PERCENT) \
X(LPAREN) \
X(RPAREN) \
X(LBRACE) \
X(RBRACE) \
X(LBRACK) \
X(RBRACK) \
X(WHITESPACE) \
X(COMMENT) \
X(NEWLINE) \
X(SEMICOLON) \
X(EQUALS) \
X(COMMA) \
X(EQSIGNAL)

class TokenType {
    public:
        #define X(type) type,
        enum Type : size_t {
            TOKEN_TYPES
        };
        #undef X

        TokenType() : type{0} {}
        TokenType(const Type &type) : type{type} {}
        operator Type() {
            return type;
        }
        std::string str() const {
            return type_strings.at(type);
        }

    private:
        Type type;

        #define X(type) {type, #type},
        std::unordered_map<Type, std::string> type_strings{
            TOKEN_TYPES
        };
        #undef X
};