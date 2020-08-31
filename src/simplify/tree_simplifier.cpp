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

ASTNode *convertExpratomToAST(LRNode *cur) {
    auto &&children = cur->getChildren();
    if (children[0]->isTerminal()) {
        if (children[0]->getTerminal() == TokenType::NUM) {
            return new NumberNode{cur->getLexeme()};
        }
        if (children[0]->getTerminal() == TokenType::MINUS) {
            return new NumberNode{"-" + cur->getLexeme()};
        }
    }
    return new ASTNode{cur->getTerminal(), cur->getLexeme()};
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
                if (cur->getChildren().size() > 1) {
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
                    && cur->getChildren()[0]->getTerminal() == TokenType::COMMA
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
    temp = new ASTNode{cur->getTerminal(), cur->getLexeme()};
    for (auto &node: cur->getChildren()) {
        temp->addChild(convertToAST(node));
    }
    return temp;
}

void simplify(LRNode *tree, ASTNode *&ast) {
    ast = convertToAST(tree);
}
