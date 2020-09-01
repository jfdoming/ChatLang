#pragma once

#include <string>

#include "../ast_node.hpp"

void replaceString(
    std::string& haystack,
    const std::string& needle,
    const std::string& replacement
) {
    size_t currentPos = 0;
    while ((currentPos = haystack.find(needle, currentPos)) != std::string::npos) {
         haystack.replace(currentPos, needle.length(), replacement);
         currentPos += replacement.length();
    }
}

struct StringNode : public ASTNode {
    StringNode(const std::string &lexeme) : ASTNode{TokenType::STRING, lexeme.substr(1, lexeme.size() - 2)} {
        // This is bad, but I don't have time...
        replaceString(this->lexeme, "\\n", "\n");
        replaceString(this->lexeme, "\\t", "\t");
    }

    virtual Value *interpret(Environment &env, short caller = 0) const {
        return new Value{lexeme};
    }
};
