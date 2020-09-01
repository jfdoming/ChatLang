#include "./tokenizer.hpp"

#include <iostream>
#include <cctype>
#include <functional>

using namespace std;

string ERROR_STATE = "error";
string HARD_ERROR_STATE = "hard_error";

unordered_map<string, function<string(char)>> TRANSITIONS = {
    {"start", [](char c)->string {
        if (isalpha(c)) {
            return "id_seen_alpha";
        }
        if (isdigit(c)) {
            return "num_seen_digit";
        }
        if (c == '`') {
            return "symbol";
        }
        if (c == '*') {
            return "star1";
        }
        if (c == '<') {
            return "lt";
        }
        if (c == '\'') {
            return "single_string";
        }
        if (c == '"') {
            return "double_string";
        }
        if (isspace(c)) {
            return "whitespace";
        }
        if (c == '#') {
            return "comment";
        }
        return ERROR_STATE;
    }},
    {"symbol", [](char c)->string {
        if (isalnum(c) || c == '_') {
            return "symbol";
        }
        return ERROR_STATE;
    }},
    {"id_seen_alpha", [](char c)->string {
        if (isalpha(c) || isdigit(c)) {
            return "id_seen_alpha";
        }
        return ERROR_STATE;
    }},
    {"num_seen_digit", [](char c)->string {
        if (isdigit(c)) {
            return "num_seen_digit";
        }
        if (c == '.') {
            return "num_seen_decimal";
        }
        if (isalpha(c)) {
            return HARD_ERROR_STATE;
        }
        return ERROR_STATE;
    }},
    {"num_seen_decimal", [](char c)->string {
        if (isdigit(c)) {
            return "num_seen_decimal";
        }
        if (isalpha(c)) {
            return HARD_ERROR_STATE;
        }
        return ERROR_STATE;
    }},
    {"single_string", [](char c)->string {
        if (c == '\'') {
            return "string_end";
        }
        if (c == '\\') {
            return "escaped_single_string";
        }
        return "single_string";
    }},
    {"escaped_single_string", [](char c)->string {
        return "single_string";
    }},
    {"double_string", [](char c)->string {
        if (c == '"') {
            return "string_end";
        }
        if (c == '\\') {
            return "escaped_double_string";
        }
        return "double_string";
    }},
    {"escaped_double_string", [](char c)->string {
        return "double_string";
    }},
    {"whitespace", [](char c)->string {
        if (isspace(c)) {
            return "whitespace";
        }
        return ERROR_STATE;
    }},
    {"comment", [](char c)->string {
        return "comment";
    }},
    {"lt", [](char c)->string {
        if (c == '-') {
            return "eqsignal";
        }
        return ERROR_STATE;
    }},
    {"star1", [](char c)->string {
        if (c == '*') {
            return "star2";
        }
        return ERROR_STATE;
    }}
};

unordered_map<char, string> SINGLE_CHAR_STATES = {
    {'+', ERROR_STATE},
    {'-', ERROR_STATE},
    {'/', ERROR_STATE},
    {'%', ERROR_STATE},
    {'(', ERROR_STATE},
    {')', ERROR_STATE},
    {'{', ERROR_STATE},
    {'}', ERROR_STATE},
    {'[', ERROR_STATE},
    {']', ERROR_STATE},
    {';', ERROR_STATE},
    {',', ERROR_STATE},
    {'=', ERROR_STATE},
};

unordered_map<string, TokenType> ACCEPT_STATES = {
    {"symbol", TokenType::SYMBOL},
    {"id_seen_alpha", TokenType::ID},
    {"num_seen_digit", TokenType::NUM},
    {"num_seen_decimal", TokenType::NUM},
    {"string_end", TokenType::STRING},
    {"+", TokenType::PLUS},
    {"-", TokenType::MINUS},
    {"star1", TokenType::STAR},
    {"star2", TokenType::STARSTAR},
    {"/", TokenType::SLASH},
    {"%", TokenType::PERCENT},
    {"(", TokenType::LPAREN},
    {")", TokenType::RPAREN},
    {"{", TokenType::LBRACE},
    {"}", TokenType::RBRACE},
    {"[", TokenType::LBRACK},
    {"]", TokenType::RBRACK},
    {";", TokenType::SEMICOLON},
    {",", TokenType::COMMA},
    {"=", TokenType::EQUALS},
    {"eqsignal", TokenType::EQSIGNAL},
    {"whitespace", TokenType::WHITESPACE},
    {"comment", TokenType::COMMENT},
};

void accept(vector<Token> &tokens, const string &state, const string &lexeme, size_t lineNumber, size_t position) {
    // For now, skip all whitespace and comments.
    if (
        ACCEPT_STATES[state] != TokenType::WHITESPACE
        && ACCEPT_STATES[state] != TokenType::COMMENT
    ) {
        tokens.emplace_back(ACCEPT_STATES[state], lexeme, lineNumber, position);
    }
}

// The tokenizer makes the assumption that tokens do not cross lines.
int tokenize(const string &input, size_t lineNumber, vector<Token> &tokens) {
    string state = "start";
    size_t lexemeStart = 0;
    size_t i = 0;
    while (i < input.size()) {
        char c = input[i];

        string new_state = ERROR_STATE;

        if (TRANSITIONS.count(state)) {
            new_state = TRANSITIONS[state](c);
        }
        if (
            new_state == ERROR_STATE
            && state == "start"
            && SINGLE_CHAR_STATES.count(c)
        ) {
            new_state = c;
        }

        if (new_state == HARD_ERROR_STATE) {
            return i;
        }

        if (new_state == ERROR_STATE) {
            // Potentially reached end of token, or failure.
            if (!ACCEPT_STATES.count(state)) {
                return i;
            }

            string lexeme = input.substr(lexemeStart, i - lexemeStart);
            accept(tokens, state, lexeme, lineNumber, lexemeStart);

            lexemeStart = i;
            state = "start";
        } else {
            ++i;
            state = new_state;
        }
    }

    if (state == "start") {
        // Empty string is valid, though not a token.
        return -1;
    }
    
    // Potentially reached end of token, or failure.
    if (!ACCEPT_STATES.count(state)) {
        return i;
    }

    string lexeme = input.substr(lexemeStart, i - lexemeStart);
    accept(tokens, state, lexeme, lineNumber, lexemeStart);

    return -1;
}