#include "./tree_simplifier.hpp"

#include <queue>
#include <unordered_set>
#include <iostream>

#include "../parse/lr_node.hpp"
#include "../scan/token_types.hpp"

#include "./ast_node.hpp"
#include "./nodes/number.hpp"
#include "./nodes/usage.hpp"
#include "./nodes/string.hpp"
#include "./nodes/tuple.hpp"
#include "./nodes/binary_operator.hpp"
#include "./nodes/function.hpp"
#include "./nodes/function_call.hpp"

using namespace std;

ASTNode *convertToAST(LRNode *cur);

// TODO list:
// 5. Add variable support in expressions.
// 4. Fix unary - so that it has lower precedence (basic program should output -1).
// 6. Add boolean support.
// 7. Fix Valgrind errors in sample.lang.

void populateChildren(LRNode *cur, ASTNode *ast) {
    for (auto &node: cur->getChildren()) {
        ast->addChild(convertToAST(node));
    }
}

ASTNode *convertExprcat3ToAST(LRNode *cur, vector<ASTNode *> *tupleNodes = nullptr) {
    auto &&children = cur->getChildren();
    if (
        children.size() > 1
        && children[1]->isTerminal()
        && children[1]->getTerminal().type == TokenType::COMMA
    ) {
        vector<ASTNode *> nodeList;
        bool topLevel = false;
        if (!tupleNodes) {
            tupleNodes = &nodeList;
            topLevel = true;
        }
        auto iter = children.begin();
        convertExprcat3ToAST(*iter, tupleNodes);
        ++iter;
        for (; iter != children.end(); ++iter) {
            tupleNodes->emplace_back(convertToAST(*iter));
        }

        if (!topLevel) {
            return nullptr;
        }
        ASTNode *tuple = new TupleNode;
        for (auto &child : *tupleNodes) {
            tuple->addChild(child);
        }
        return tuple;
    } else if (tupleNodes) {
        for (auto &child : children) {
            tupleNodes->emplace_back(convertToAST(child));
        }
        return nullptr;
    } else {
        ASTNode *temp = new ASTNode{cur->getNonterminal()};
        populateChildren(cur, temp);
        return temp;
    }
}

ASTNode *convertExpratomToAST(LRNode *cur) {
    auto &&children = cur->getChildren();
    if (children[0]->isTerminal()) {
        if (children[0]->getTerminal().type == TokenType::STRING) {
            return new StringNode{children[0]->getTerminal().lexeme};
        }
        if (children[0]->getTerminal().type == TokenType::ID) {
            return new UsageNode{children[0]->getTerminal().lexeme};
        }
        if (children[0]->getTerminal().type == TokenType::NUM) {
            return new NumberNode{children[0]->getTerminal().lexeme};
        }
        if (children[0]->getTerminal().type == TokenType::MINUS) {
            return new NumberNode{"-" + children[1]->getTerminal().lexeme};
        }
        return new ASTNode{cur->getTerminal().type, cur->getTerminal().lexeme};
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
                populateChildren(cur, temp);
                break;
            case NonterminalType::exprcat3:
                // Potentially a tuple.
                temp = convertExprcat3ToAST(cur);
                break;
            case NonterminalType::expratom:
                temp = convertExpratomToAST(cur);
                populateChildren(cur, temp);
                break;
            case NonterminalType::fn:
                if (cur->getChildren().size() > 1) {
                    temp = new FunctionNode;
                } else {
                    temp = new ASTNode{cur->getNonterminal()};
                }
                populateChildren(cur, temp);
                break;
            case NonterminalType::fncall:
                temp = new FunctionCallNode;
                populateChildren(cur, temp);
                break;
            default:
                temp = new ASTNode{cur->getNonterminal()};
                populateChildren(cur, temp);
        }
        return temp;
    }
    // Terminal TokenType
    temp = new ASTNode{cur->getTerminal().type, cur->getTerminal().lexeme};
    return temp;
}

void simplify(LRNode *tree, ASTNode *&ast) {
    ast = convertToAST(tree);
}
