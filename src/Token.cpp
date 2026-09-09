#include "Token.hpp"

namespace kly {
    std::string tokenTypeName(TokenType type) {
        switch (type) {
            case TokenType::IDENTIFIER: return "IDENTIFIER";
            case TokenType::INT_LITERAL: return "INT_LITERAL";
            case TokenType::FLOAT_LITERAL: return "FLOAT_LITERAL";
            case TokenType::STRING_LITERAL: return "STRING_LITERAL";
            default: return "UNKNOWN";
        }
    }
}