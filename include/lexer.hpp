#pragma once

#include <string>
#include <vector>
#include "Token.hpp"

namespace kly {

class Lexer {
public:
    explicit Lexer(std::string source);

        // Scans the entire source and returns all tokens, ending with END_OF_FILE.

    std::vector<Token> scanTokens();
private: 
    std::string source_;
    std::vector<Token> tokens_;
    size_t start_ =0;
    size_t current =0;
    int line_ =1;
    bool isAtEnd() const;
    char advance();
    char peek() const;
    char peekNext() const;
    bool match(char expected);

    void scanToken();
    void addToken(TokenType type);
    void addToken(TokenType type, const std::string& lexeme);

    void scanIdentifier();
    void scanNumber();
    void scanString();
    };
}