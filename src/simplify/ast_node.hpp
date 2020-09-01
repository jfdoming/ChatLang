#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "src/scan/token_types.hpp"

#include "src/parse/nt_types.hpp"

#include "src/interpret/value.hpp"
#include "src/interpret/environment.hpp"

struct ASTNode {
        ASTNode(const NonterminalType::Type &nonterminal);
        ASTNode(const TokenType &type, std::string lexeme);
        virtual ~ASTNode();
        void addChild(ASTNode *child);
        std::size_t getState() const;
        std::string getLexeme() const;
        TokenType getTerminal() const;
        NonterminalType getNonterminal() const;
        bool isTerminal() const;

        virtual Value *interpret(Environment &env, short caller = 0) const;

        friend std::ostream &operator<<(std::ostream &, const ASTNode &);
    protected:
        NonterminalType nonterminal;
        TokenType terminal;
        std::string lexeme;
        bool holdsTerminal;
        std::vector<ASTNode *> children;
};
