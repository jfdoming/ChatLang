#pragma once

#include "../parse/lr_node.hpp"
#include "./ast_node.hpp"

void simplify(LRNode *tree, ASTNode *&ast);