#pragma once

#include <cstddef>

#define X_ENUM_VALUE(T) T,
#define X_ENUM_PAIR(T) #T,
#define GEN_ENUM_TYPES(TYPES) TYPES(X_ENUM_VALUE)
#define GEN_ENUM_NAMES(TYPES) TYPES(X_ENUM_PAIR)

#define DEF_ENUM_CLASS(ClassName, TYPES) public: \
enum Type : size_t { \
    GEN_ENUM_TYPES(TYPES) \
}; \
ClassName() : type{0} {} \
ClassName(const Type &type) : type{type} {} \
const char *str() const { \
    return type_strings[type]; \
} \
operator Type() const { \
    return type; \
} \
private: \
Type type; \
enum class X_Type : size_t { \
    GEN_ENUM_TYPES(TYPES) X_MAX \
}; \
static constexpr const char *type_strings[size_t(X_Type::X_MAX)] = {GEN_ENUM_NAMES(TYPES)};
