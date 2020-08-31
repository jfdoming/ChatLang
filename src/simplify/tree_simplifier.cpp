#include "./tree_simplifier.hpp"

#include <queue>
#include <unordered_set>
#include <iostream>

#include "../parse/lr_node.hpp"
#include "../scan/token_types.hpp"

#include "./ast_node.hpp"
#include "./nodes/number.hpp"
#include "./nodes/binary_operator.hpp"

using namespace std;

/*unordered_set<TokenType> xatTokens = {TokenType::B0F, TokenType::E0F, TokenType::LPAREN, TokenType::RPAREN, TokenType::LBRACE, TokenType::RBRACE, TokenType::LBRACK, TokenType::RBRACK, TokenType::SEMICOLON};

bool skipNode(LRNode *cur) {
    if (cur->isState()) return 1;
    if (!cur->isTerminal()) return 1;// we might want to keep some NTs though? As glue, e.g. we still want to know about function calls
    if (xatTokens.find(cur->getNonterminal()) != xatTokens.end()) return 1;
    return 0;
}*/

ASTNode *parseToAST(LRNode *cur) {
    if (!cur) return nullptr;
    // State
    if (cur->isState()) return nullptr;

    ASTNode *temp;
    // NonTerminal
    if (!cur->isTerminal()) {
        switch (cur->getNonterminal()) {
            case NonterminalType::expr:
                if (cur->getChildren().size() > 1) {
                    temp = new BinaryOperatorNode;
                } else {
                    temp = new ASTNode{cur->getNonterminal()};
                }
                // break;
            default:
                temp = new ASTNode{cur->getNonterminal()};
        }
        for (auto &node: cur->getChildren()) {
            ASTNode *tempchild = parseToAST(node);
            if (tempchild) temp->addChild(tempchild);
        }
        return temp;
    }
    // Terminal TokenType
    switch (cur->getTerminal()) {
        case TokenType::NUM:
            temp = new NumberNode{cur->getLexeme()};
            break;
        case TokenType::LPAREN: case TokenType::RPAREN: 
            temp = nullptr;
            break;
        default:
            temp = new ASTNode{cur->getTerminal(), cur->getLexeme()};
    }
    for (auto &node: cur->getChildren()) {
        temp->addChild(parseToAST(node));
    }
    return temp;
}

void simplify(LRNode *tree, ASTNode *&ast) {
    ast = parseToAST(tree);
}
