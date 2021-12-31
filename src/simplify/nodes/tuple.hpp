#pragma once

#include <vector>

#include "../ast_node.hpp"

struct TupleNode : public ASTNode {
    TupleNode() : ASTNode{NonterminalType::exprcat3} {}
    virtual Value interpret(Environment &env, short = 0) const override {
        std::vector<Value> values;
        for (size_t i = 0; i < children.size(); i += 2) {
            values.emplace_back(children[i]->interpret(env));
        }
        return values;
    }
};
