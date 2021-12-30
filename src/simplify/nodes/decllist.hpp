#pragma once

#include <vector>
#include <string>

#include "../ast_node.hpp"

struct DeclListNode : public ASTNode {
    DeclListNode() : ASTNode{NonterminalType::decllist} {}
    virtual Value interpret(Environment &env, short caller = 0) const override {
        std::vector<std::string> values;
        for (size_t i = 0; i < children.size(); i += 2) {
            values.emplace_back(children[i]->getLexeme());
        }
        return {this, values};
    }
};
