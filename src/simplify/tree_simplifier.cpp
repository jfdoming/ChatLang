#include "./tree_simplifier.hpp"

#include <queue>
#include <unordered_set>
#include <iostream>

#include "../parse/lr_node.hpp"
#include "../scan/token_types.hpp"

#include "./ast_node.hpp"
#include "./nodes/number.hpp"
#include "./nodes/binary_operator.hpp"
#include "./nodes/function.hpp"

using namespace std;

ASTNode *convertToAST(LRNode *cur);

// TODO list:
// 1. Add tuple support.
// 2. Implement function parameters.
// 3. Implement the print function.
// 4. Fix unary - so that it has lower precedence (basic program should output 1).
// 5. Add variable support in expressions.
// 6. Add boolean support.
// 7. Fix Valgrind errors in sample.lang.

ASTNode *convertExpratomToAST(LRNode *cur) {
    auto &&children = cur->getChildren();
    if (children[0]->isTerminal()) {
        if (children[0]->getTerminal().type == TokenType::NUM) {
            return new NumberNode{children[0]->getTerminal().lexeme};
        }
        if (children[0]->getTerminal().type == TokenType::MINUS) {
            return new NumberNode{"-" + children[1]->getTerminal().lexeme};
        }
    }
    return new ASTNode{cur->getNonterminal()};
}

ASTNode *convertToAST(LRNode *cur) {
    if (!cur) return nullptr;
    // State
    if (cur->isState()) return nullptr;

    ASTNode *temp;
    // NonTerminal
    if (!cur->isTerminal()) {
        switch (cur->getNonterminal()) {
            case NonterminalType::expr:
            case NonterminalType::exprcat1:
            case NonterminalType::exprcat2:
                if (cur->getChildren().size() > 2) {
                    temp = new BinaryOperatorNode;
                } else {
                    temp = new ASTNode{cur->getNonterminal()};
                }
                break;
            case NonterminalType::exprcat3:
                // Potentially a tuple.
                if (
                    cur->getChildren().size() > 1
                    && cur->getChildren()[0]->isTerminal()
                    && cur->getChildren()[0]->getTerminal().type == TokenType::COMMA
                ) {
                    auto &&children = cur->getChildren();
                    vector<ASTNode *> tupleNodes;
                    tupleNodes.emplace_back(convertToAST(children[0]));
                }
            case NonterminalType::expratom:
                temp = convertExpratomToAST(cur);
                break;
            case NonterminalType::fn:
                if (cur->getChildren().size() > 1) {
                    temp = new FunctionNode;
                } else {
                    temp = new ASTNode{cur->getNonterminal()};
                }
                break;
            default:
                temp = new ASTNode{cur->getNonterminal()};
        }
        for (auto &node: cur->getChildren()) {
            temp->addChild(convertToAST(node));
        }
        return temp;
    }
    // Terminal TokenType
    temp = new ASTNode{cur->getTerminal().type, cur->getTerminal().lexeme};
    for (auto &node: cur->getChildren()) {
        temp->addChild(convertToAST(node));
    }
    return temp;
}

void simplify(LRNode *tree, ASTNode *&ast) {
    ast = convertToAST(tree);
}
