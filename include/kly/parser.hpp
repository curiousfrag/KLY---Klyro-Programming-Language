#pragma once

#include <stdexcept>
#include <vector>
#include "kly/token.hpp"
#include "kly/ast_stmt.hpp"

namespace kly {

struct ParseError : std::runtime_error {
    explicit ParseError(const std::string& message) : std::runtime_error(message) {}
};

class Parser {
public: 
    explicit Parser(std::vector<Token> tokens);
    std::vector<StmtPtr> parseProgram();
private: 
    std::vector<Token> tokens_;
    size_t current_ = 0;

    const Token& peek() const;
    const Token& previous() const;
    bool isAtEnd() const;
    const Token& advance();
    bool check(TokenType type) const;
    bool match(std::initializer_list<TokenType> types);
    const Token& consume(TokenType type, const std::string& message);
    ParseError error(const Token& tokken, const std::string& message);

    StmtPtr declaration();
    StmtPtr functionDecl();
    StmtPtr letDecl();
    StmtPtr statement();
    StmtPtr blockStmt();
    StmtPtr ifStmt();
    StmtPtr whileStmt();
    StmtPtr returnStmt();
    StmtPtr exprStmtRule();
    TypeName typeName();

    ExprPtr expression();
    ExprPtr assignment();
    ExprPtr logicOr();
    ExprPtr logicAnd();
    ExprPtr equality();
    ExprPtr comparison();
    ExprPtr term();
    ExprPtr factor();
    ExprPtr unary();
    ExprPtr call();
    ExprPtr primary();
};
}