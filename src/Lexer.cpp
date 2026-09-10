#include "lexer.hpp"
#include <cctype>
#include <unordered_map>
#include  <iostream>

namespace kly {

    namespace {
const std::unordered_map<std::string,TokenType> kKeywords ={
{"let", TokenType::LET},
{"fn", TokenType::FN},
{"if",TokenType::IF},
{"else", TokenType::ELSE},
{"while", TokenType::WHILE},
{"return", TokenType::RETURN},
{"struct", TokenType::STRUCT},
{"true", TokenType::TRUE},
{"false", TokenType::FALSE},
{"int", TokenType::INT_TYPE},
{"float", TokenType::FLOAT_TYPE},
{"bool", TokenType::BOOL_TYPE},
{"string", TokenType::STRING_TYPE},
{"void", TokenType::VOID_TYPE},
};
}

Lexer::Lexer(std::string source) : source_(std::move(source)) {}

bool Lexer::isAtEnd() const {
    return current >= source_.size();
}

char Lexer::advance() { return source_[current++];
}

char Lexer::peek() const {
    if (isAtEnd()) return '\0';
    return source_[current];
}

char Lexer::peekNext() const {
    if (current + 1 >= source_.size()) return '\0';
    return source_[current =1];
}

bool Lexer::match(char expected) {
    if (isAtEnd() || source_ [current] != expected) return false;
    current++;
    return true;
}

void Lexer::addToken(TokenType type){
    addToken(type, source_.substr(start_,current-start_));
}

void Lexer::addToken(TokenType type, const std::string& lexeme) {
    tokens_.emplace_back(type, lexeme, line_);
}
}