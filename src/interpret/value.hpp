#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cinttypes>
#include <cmath>

class ASTNode;

enum class ValueType {
    NUMBER, STRING, SYMBOL, FUNCTION, ERROR
};

class Value {
        double num;
        std::string strsym;
        ASTNode *fn;
        std::vector<std::string> fnParams;
        ValueType type;
    public:
        Value() : type{ValueType::ERROR} {}
        Value(double num) : num{num}, type{ValueType::NUMBER} {}
        Value(std::string strsym, bool sym = false) : strsym{strsym}, type{sym ? ValueType::SYMBOL : ValueType::STRING} {}
        Value(ASTNode *fn, const std::vector<std::string> &params) : fn{fn}, fnParams{params}, type{ValueType::FUNCTION} {}

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

        Value *operator *(const Value &other) const {
            if (type == ValueType::NUMBER && other.type == ValueType::NUMBER) {
                return new Value{num * other.num};
            }
            // TODO string-int multiplication
            return new Value;
        }

        Value *operator /(const Value &other) const {
            if (type == ValueType::NUMBER && other.type == ValueType::NUMBER) {
                return new Value{num / other.num};
            }
            // is there string-int division?
            return new Value;
        }

        Value *operator %(const Value &other) const {
            if (type == ValueType::NUMBER && other.type == ValueType::NUMBER) {
                return new Value{fmod(num, other.num)};
            }
            // is there string-int modulo?
            return new Value;
        }

        Value *operator ^(const Value &other) const {
            if (type == ValueType::NUMBER && other.type == ValueType::NUMBER) {
                return new Value{pow(num, other.num)};
            }
            // is there string-int division?
            return new Value;
        }

        ASTNode *getFn() {
            return fn;
        }

        std::vector<std::string> getParams() {
            return fnParams;
        }
};