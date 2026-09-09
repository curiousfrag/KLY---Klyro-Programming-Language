#include "Kly/lexer.hpp"
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

lexer::lexerr(std::string source) : source_(std::move(source)) {}

}