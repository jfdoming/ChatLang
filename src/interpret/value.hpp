#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cinttypes>
#include <cmath>

#include "../enum.hpp"

class ASTNode;

#define VALUE_TYPES(X) \
    X(NUMBER) \
    X(STRING) \
    X(SYMBOL) \
    X(FUNCTION) \
    X(TUPLE) \
    X(ERROR)

class ValueType {
    DEF_ENUM_CLASS(ValueType, VALUE_TYPES);
};

class Value {
        struct Data {
            double num;
            std::string strsym;
            const ASTNode *fn;
            std::vector<std::string> fnParams;
            std::vector<Value> values;
            ValueType type;

            unsigned int refCount = 1;

            Data() : type{ValueType::ERROR} {}
            Data(double num) : num{num}, type{ValueType::NUMBER} {}
            Data(std::string strsym, bool sym) : strsym{strsym}, type{sym ? ValueType::SYMBOL : ValueType::STRING} {}
            Data(const ASTNode *fn, const std::vector<std::string> &params) : fn{fn}, fnParams{params}, type{ValueType::FUNCTION} {}

            // Note: ()-style rather than {}-style initialization is required
            // in order to avoid implicit conversions.
            Data(const std::vector<Value> &values)
                : values(values), type{ValueType::TUPLE} {}
        };

        Data *data;
    public:
        Value() : data{new Data} {}
        Value(double num) : data{new Data{num}} {}
        Value(std::string strsym, bool sym = false) : data{new Data{strsym, sym}} {}
        Value(const ASTNode *fn, const std::vector<std::string> &params) : data{new Data{fn, params}} {}
        Value(const std::vector<Value> &values) : data{new Data{values}} {}

        explicit Value(Value *other) : data{other ? other->data : nullptr} {
            if (data) ++data->refCount;
        }
        Value(const Value &other) : data{other.data} {
            if (data) ++data->refCount;
        }
        Value &operator=(const Value &other) {
            if (data && !--data->refCount) delete data;
            data = other.data;
            if (data) ++data->refCount;
            return *this;
        }

        ~Value() {
            if (data && !--data->refCount) delete data;
        }

        ValueType getType() {
            return data->type;
        }

        bool isFalsy() const {
            if (data->type == ValueType::NUMBER) {
                return data->num == 0;
            }
            if (data->type == ValueType::STRING) {
                return data->strsym.size() == 0;
            }
            return false;
        }

        bool isEmpty() const {
            return !data;
        }

        operator bool() const {
            return data && data->type != ValueType::ERROR;
        }

        std::string str() const {
            if (data->type == ValueType::NUMBER) {
                return std::to_string(data->num);
            }
            if (data->type == ValueType::FUNCTION) {
                return std::to_string(reinterpret_cast<uintptr_t>(data->fn));
            }
            if (data->type == ValueType::TUPLE) {
                std::string output;
                for (auto &value : data->values) {
                    if (&value != &data->values[0]) {
                        output += ",";
                    }
                    output += value.str();
                }
                return output;
            }
            return data->strsym;
        }

        Value operator +(const Value &other) const {
            if (
                data->type == ValueType::SYMBOL
                || other.data->type == ValueType::SYMBOL
                || data->type == ValueType::FUNCTION
                || other.data->type == ValueType::FUNCTION) {
                return {};
            }
            if (data->type == ValueType::NUMBER && other.data->type == ValueType::NUMBER) {
                return data->num + other.data->num;
            }
            return str() + other.str();
        }

        Value operator -(const Value &other) const {
            if (data->type == ValueType::NUMBER && other.data->type == ValueType::NUMBER) {
                return data->num - other.data->num;
            }
            return {};
        }

        Value operator *(const Value &other) const {
            if (data->type == ValueType::NUMBER && other.data->type == ValueType::NUMBER) {
                return data->num * other.data->num;
            }
            // TODO string-int multiplication
            return {};
        }

        Value operator /(const Value &other) const {
            if (data->type == ValueType::NUMBER && other.data->type == ValueType::NUMBER) {
                return data->num / other.data->num;
            }
            // is there string-int division?
            return {};
        }

        Value operator %(const Value &other) const {
            if (data->type == ValueType::NUMBER && other.data->type == ValueType::NUMBER) {
                return fmod(data->num, other.data->num);
            }
            // is there string-int modulo?
            return {};
        }

        Value operator ^(const Value &other) const {
            if (data->type == ValueType::NUMBER && other.data->type == ValueType::NUMBER) {
                return pow(data->num, other.data->num);
            }
            // is there string-int division?
            return {};
        }

        const ASTNode *getFn() {
            return data->fn;
        }

        std::vector<std::string>& getParams() {
            return data->fnParams;
        }

        std::vector<Value>& getValues() {
            return data->values;
        }
};
