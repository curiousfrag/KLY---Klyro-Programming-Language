#pragma once 

#include <string>

namespace  kly {

    enum class TokenType {
    
    //Literals
    IDENTIFIER, INT_LITERAL, FLOAT_LITERAL, STRING_LITERAL,

    //Keywords
    LET, FN, IF, ELSE, WHILE, RETURN, STRUCT, TRUE, FALSE, INT_TYPE, FLOAT_TYPE, BOOL_TYPE, STRING_TYPE,VOID_TYPE,

    //Symbols 
    PLUS, MINUS, STAR, SLASH, PERCENT, EQUAL,EQUAL_EQUAL, BANG, BANG_EQUAL, LESS, LESS_EQUAL, GREATER, GREATER_EQUAL, AND, OR, LPAREN, RPAREN, LBRACE, RBRACE, COMMA, SEMICOLON, COLON, ARROW, DOT,


    END_OF_FILE, UNKNOWN
    };

    struct Token { 

    
        TokenType type;
        std::string lexeme;
        int line;

        Token(TokenType type, std::string lexeme, int line)
            : type(type), lexeme(std::move (lexeme)), line(line) {}
};

std::string tokenTypeName(TokenType  type);
}