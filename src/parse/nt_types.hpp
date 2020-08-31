#pragma once

#include <cstddef>
#include <unordered_map>
#include <string>

#include "./nt_def.hpp"

class NonterminalType {
    public:
        #define X(type) type,
        enum Type : size_t {
            NT_TYPES
        };
        #undef X

        NonterminalType() : type{0} {}
        NonterminalType(const Type &type) : type{type} {}
        operator Type() {
            return type;
        }
        std::string str() const {
            return type_strings.at(type);
        }

    private:
        Type type;

        #define X(type) {type, #type},
        std::unordered_map<Type, std::string> type_strings{
            NT_TYPES
        };
        #undef X
};