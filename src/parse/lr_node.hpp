#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

#include "../scan/tokenizer.hpp"
#include "../parse/nt_types.hpp"

using namespace std;

struct LRNode {
        LRNode(const NonterminalType::Type &nonterminal);
        LRNode(const Token &type);
        explicit LRNode(size_t state);
        ~LRNode();

        void addChild(LRNode *child);
        size_t getState() const;
        NonterminalType getNonterminal() const;
        Token getTerminal() const;
        bool isState() const;
        bool isTerminal() const;
        vector<LRNode *> getChildren() const;

        friend ostream &operator<<(ostream &, const LRNode &);
    private:
        size_t state;
        NonterminalType nonterminal;
        Token terminal;
        bool holdsState;
        bool holdsTerminal;
        vector<LRNode *> children;
};

ostream &operator<<(ostream &out, const LRNode &el);
