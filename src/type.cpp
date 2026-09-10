#include "kly/type.hpp"

namespace kly {

    ValueType typeFromName(const std::string& name) {
        if (name == "int") return ValueType::Int;
        if (name == "float") return ValueType::Float;
        if (name == "bool") return ValueType::Bool;
        if (name == "string") return ValueType::String; 
        if (name =="void") return ValueType::Void;
        return ValueType::Unknown;
    }

std::string TypeName(ValueType type) {
    switch (type) {
        case ValueType::Int: return "int";
        case ValueType::Float: return "float";
        case ValueType::Bool: return"bool";
        case ValueType::String: return "string";
        case ValueType::Void: return "voif";            default: return "unknown";
    }
}
}