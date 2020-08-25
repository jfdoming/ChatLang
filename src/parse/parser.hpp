#pragma once

#include <vector>

#include "../scan/tokenizer.hpp"
#include "./parse_node.hpp"

int parse(const std::vector<Token> &tokens, ParseNode *& tree);