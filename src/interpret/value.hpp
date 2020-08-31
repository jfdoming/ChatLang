#pragma once

#include <iostream>
#include <string>
#include <cinttypes>

class ASTNode;

enum class ValueType {
    NUMBER, STRING, SYMBOL, FUNCTION, ERROR
};

class Value {
        float num;
        std::string strsym;
        ASTNode *fn;
        ValueType type;
    public:
        Value() : type{ValueType::ERROR} {}
        Value(float num) : num{num}, type{ValueType::NUMBER} {}
        Value(std::string strsym, bool sym = false) : strsym{strsym}, type{sym ? ValueType::SYMBOL : ValueType::STRING} {}
        Value(ASTNode *fn) : fn{fn}, type{ValueType::FUNCTION} {}

        ValueType getType() {
            return type;
        }

        operator bool() const {
            return type != ValueType::ERROR;
        }

        inline std::string str() const {
            if (type == ValueType::NUMBER) {
                return std::to_string(num);
            }
            if (type == ValueType::FUNCTION) {
                return std::to_string(reinterpret_cast<uintptr_t
  
>(fn));
            }
            return strsym;
        }

        Value *operator +(const Value &other) const {
            if (
                type == ValueType::SYMBOL
                || other.type == ValueType::SYMBOL
                || type == ValueType::FUNCTION
                || other.type == ValueType::FUNCTION) {
                return new Value;
            }
            if (type == ValueType::NUMBER && other.type == ValueType::NUMBER) {
                return new Value{num + other.num};
            }
            return new Value{str() + other.str()};
        }

        Value *operator -(const Value &other) const {
            if (type == ValueType::NUMBER && other.type == ValueType::NUMBER) {
                return new Value{num - other.num};
            }
            return new Value;
        }

        ASTNode *getFn() {
            return fn;
        }
};