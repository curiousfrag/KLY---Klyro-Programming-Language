#include "kly/token.hpp"

namespace kly {
    std::string tokenTypeName(TokenType type) {
        switch (type) {
            case TokenType::IDENTIFIER: return "IDENTIFIER";
            case TokenType::INT_LITERAL: return "INT_LITERAL";
            case TokenType::FLOAT_LITERAL: return "FLOAT_LITERAL";
            case TokenType::STRING_LITERAL: return "STRING_LITERAL";
            case TokenType::LET: return "LET";
            case TokenType::FN: return "FN";
            case TokenType::IF: return"IF"; 
            case TokenType::ELSE: return "ELSE";
            case TokenType::WHILE: return"WHILE";
            case TokenType::AND: return"AND";
            case TokenType::OR: return"OR";
            case TokenType::RETURN: return"RETURN";
            case TokenType::STRUCT: return"STRUCT";
            case TokenType::TRUE: return"TRUE";
            case TokenType::FALSE: return"FALSE";
            case TokenType::INT_TYPE: return"INT_TYPE";
            case TokenType::FLOAT_TYPE: return"FLOAT_TYPE";
            case TokenType::BOOL_TYPE: return"BOOL_TYPE";
            case TokenType::STRING_TYPE: return"STRING_TYPE";
            case TokenType::VOID_TYPE: return"VOID_TYPE";
            case TokenType::PLUS: return"PLUS";
            case TokenType::MINUS: return"MINUS";
            case TokenType::STAR: return"STAR";
            case TokenType::SLASH: return"SLASH";
            case TokenType::PERCENT: return"PERCENT";
            case TokenType::EQUAL: return"EQUAL";
            case TokenType::EQUAL_EQUAL: return"EQUAL_EQUAL";
            case TokenType::BANG: return"BANG";
            case TokenType::BANG_EQUAL: return"BANG_EQUAL";
            case TokenType::LESS: return"LESS";
            case TokenType::LESS_EQUAL: return"LESS_EQUAL";
            case TokenType::GREATER: return"GREATER";
            case TokenType::GREATER_EQUAL: return"GREATER_EQUAL";
            case TokenType::LPAREN: return"LPAREN";
            case TokenType::RPAREN: return"RPAREN";
            case TokenType::LBRACE: return"LBRACE";
            case TokenType::RBRACE: return"RBRACE";
            case TokenType::COMMA: return"COMMA";
            case TokenType::SEMICOLON: return"SEMICOLON";
            case TokenType::COLON: return"COLON";
            case TokenType::ARROW: return"ARROW";
            case TokenType::DOT: return"DOT";
            case TokenType::END_OF_FILE: return"EOF";
            default: return "UNKNOWN";
    }

}

}