#include "kly/lexer.hpp"
#include <cctype>
#include <unordered_map>
#include <iostream>

namespace kly {

namespace {
const std::unordered_map<std::string, TokenType> kKeywords = {
    {"let", TokenType::LET},
    {"fn", TokenType::FN},
    {"if", TokenType::IF},
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

char Lexer::advance() {
    return source_[current++];
}

char Lexer::peek() const {
    if (isAtEnd()) return '\0';
    return source_[current];
}

char Lexer::peekNext() const {
    if (current + 1 >= source_.size()) return '\0';
    return source_[current + 1];
}

bool Lexer::match(char expected) {
    if (isAtEnd() || source_[current] != expected) return false;
    current++;
    return true;
}

void Lexer::addToken(TokenType type) {
    addToken(type, source_.substr(start_, current - start_));
}

void Lexer::addToken(TokenType type, const std::string& lexeme) {
    tokens_.emplace_back(type, lexeme, line_);
}

std::vector<Token> Lexer::scanTokens() {
    while (!isAtEnd()) {
        start_ = current;
        scanToken();
    }
    tokens_.emplace_back(TokenType::END_OF_FILE, "", line_);
    return tokens_;
}

void Lexer::scanToken() {
    char c = advance();

    switch (c) {

        case ' ': case '\r': case '\t': break;
        case '\n': line_++; break;

        case '(': addToken(TokenType::LPAREN); break;
        case ')': addToken(TokenType::RPAREN); break;
        case '{': addToken(TokenType::LBRACE); break;
        case '}': addToken(TokenType::RBRACE); break;
        case ',': addToken(TokenType::COMMA); break;
        case ';': addToken(TokenType::SEMICOLON); break;
        case ':': addToken(TokenType::COLON); break;
        case '.': addToken(TokenType::DOT); break;
        case '+': addToken(TokenType::PLUS); break;
        case '*': addToken(TokenType::STAR); break;
        case '%': addToken(TokenType::PERCENT); break;

        case '-':
            addToken(match('>') ? TokenType::ARROW : TokenType::MINUS);
            break;
        case '=':
            addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
            break;
        case '!':
            addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
            break;
        case '<':
            addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
            break;
        case '>':
            addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
            break;
        case '&':
            if (match('&')) addToken(TokenType::AND);
            else addToken(TokenType::UNKNOWN);
            break;
        case '|':
            if (match('|')) addToken(TokenType::OR);
            else addToken(TokenType::UNKNOWN);
            break;

        case '/':
            if (match('/')) {
        
                while (peek() != '\n' && !isAtEnd()) advance();
            } else {
                addToken(TokenType::SLASH);
            }
            break;

        case '"':
            scanString();
            break;

        default:
            if (std::isdigit(static_cast<unsigned char>(c))) {
                scanNumber();
            } else if (std::isalpha(static_cast<unsigned char>(c)) || c == '_') {
                scanIdentifier();
            } else {
                std::cerr << "[line " << line_ << "] Unexpected character: '" << c << "'\n";
                addToken(TokenType::UNKNOWN);
            }
            break;
    }
}

void Lexer::scanIdentifier() {
    while (std::isalnum(static_cast<unsigned char>(peek())) || peek() == '_') advance();
    std::string text = source_.substr(start_, current - start_);
    auto it = kKeywords.find(text);
    addToken(it != kKeywords.end() ? it->second : TokenType::IDENTIFIER, text);
}

void Lexer::scanNumber() {
    bool isFloat = false;
    while (std::isdigit(static_cast<unsigned char>(peek()))) advance();

    if (peek() == '.' && std::isdigit(static_cast<unsigned char>(peekNext()))) {
        isFloat = true;
        advance(); // consume '.'
        while (std::isdigit(static_cast<unsigned char>(peek()))) advance();
    }

    addToken(isFloat ? TokenType::FLOAT_LITERAL : TokenType::INT_LITERAL);
}

void Lexer::scanString() {
    while (peek() != '"' && !isAtEnd()) {
        if (peek() == '\n') line_++;
        advance();
    }

    if (isAtEnd()) {
        std::cerr << "[line " << line_ << "] Unterminated string.\n";
        return;
    }

    advance();
    std::string value = source_.substr(start_ + 1, current - start_ - 2);
    addToken(TokenType::STRING_LITERAL, value);
}

} 


