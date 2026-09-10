#pragma once 

#include <string>

namespace kly {

    enum class ValueType {
        Int, Float, Bool, String, Void, Unknown
    };

    ValueType typeFromName(const std::string& name);
    std::string typeName(ValueType type);
}