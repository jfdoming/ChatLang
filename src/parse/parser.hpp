#pragma once

#include <vector>

#include "../scan/tokenizer.hpp"
#include "./lr_node.hpp"

int parse(const std::vector<Token> &tokens, std::vector<std::string> *lines, LRNode *& tree);
