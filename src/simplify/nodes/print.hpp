#pragma once

#include <iostream>

#include "../ast_node.hpp"

struct PrintNode : public ASTNode {
        PrintNode(bool newline = false) : ASTNode{NonterminalType::fn}, newline{newline} {}
        virtual Value interpret(Environment &env, short caller = 0) const {
            if (!caller) {
                return {this, {"arg"}};
            }
            Value value;
            int retval = env.get("arg", value);
            if (retval || !value) {
                if (newline) {
                    std::cout << std::endl;
                } else {
                    std::cout << std::flush;
                }
            } else {
                if (newline) {
                    std::cout << value.str() << std::endl;
                } else {
                    std::cout << value.str() << std::flush;
                }
            }
            return 0;
        }
    private:
        bool newline;
};
