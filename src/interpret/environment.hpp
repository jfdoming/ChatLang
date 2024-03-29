#pragma once

#include <stack>
#include <unordered_map>
#include <utility>

#include "./value.hpp"

class Environment {
        std::stack<std::unordered_map<std::string, Value>> frames;
        std::stack<const ASTNode *> frameIDs;
        std::unordered_map<std::string, std::stack<std::pair<const ASTNode *, Value>>> effectFrames;
    public:
        Environment(ASTNode *root);
        ~Environment();

        int invoke(const std::string &name, Value args, Value &value);
        int invoke(Value fn, Value args, Value &value);
        int get(const std::string &name, Value &value) const;
        int set(const std::string &name, Value value);
        int setEffect(const std::string &name, Value value);
};
