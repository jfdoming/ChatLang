#pragma once

#include <vector>
#include <string>

#include "../ast_node.hpp"

struct ExprParNode : public ASTNode {
    ExprParNode() : ASTNode{NonterminalType::exprpar} {}
    virtual Value interpret(Environment &env, short caller = 0) const override {
        Value last{nullptr};
        Value cur{nullptr};
        for (size_t i = 1; i < children.size(); i += 3) {
            cur = children[i]->interpret(env);
            if (cur.isFalsy()) {
                return cur;
            }
            last = cur;
        }
        return last;
    }
};
