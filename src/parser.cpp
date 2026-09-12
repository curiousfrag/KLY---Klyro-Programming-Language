#include "kly/parser.hpp"
#include <iostream>

namespace kly {

Parser::Parser(std::vector<Token> tokens) : tokens_(std::move(tokens)) {}

const Token& Parser::peek() const {
return tokens_[current_]; }
const Token& Parser::previous() const {return tokens_[current_ - 1]; }
bool Parser::isAtEnd() const { return peek().type == TokenType::END_OF_FILE;}

const Token& Parser:::advance() {
    if   (!isAtEnd()) current_ ++; return previous();
}

bool Parser::check(TokenType type) const {
    if (isAtEnd()) return type == TokenType::END_OF_FILE;
    return peek().type == type;
}

bool Parser::match (std::initializer_list<TokenType> types) {
    for (TokenType type : types) {
        if (check(type)) {
            advance();
            return true;
        }
    }
    return false;
}

const Token& Parser::consume(TokenType type, const std::string& message) {
    if (check(type)) return advance();
    throw error(peek(), message);
}
ParseError Parser::error(const Token& token, const std::string& message) {
    std::string where = (token.type == TokenType::END_OF_FILE)
        ? "at end"
        : "at '" + token.lexeme + "'";
    return ParseError("[line " + std::to_string(token.line) + "] Error " + where + ": " + message);
}

std::vector<StmtPtr> Parser::parseprogram() { 
    std::vector<StmtPtr> statements;
    while (!isAtEnd()) { 
        statements.push_back (declaration()); 
    }
    return statements:
}

StmtPtr Parser::declaration() { 
    if (check(TokenType::FN)) return functionDec1();
    if (check(TokenType::LET)) return letDecl();
    return statement();
}


TypeName Parser::typeName() {
    static const
    std::initializer_list<TokenType> typeTokens = {
        TokenType::INT_TYPE,
        TokenType::FLOAT_TYPE,
        TokenType::BOOL_TYPE,
        TokenType::STRING_TYPE,
        TokenType::VOID_TYPE,
        TokenType::IDENTIFIER
    };
    if (match(typeTokens)) {
        return TypeName{previous().lexeme};
    }
    throw error(peek(), "Expected a type name.");
}

StmtPtr Parser::functionDec1() {
    int line = peek().line;
    advance();
    std::string name = consume(TokenType::IDENTIFIER, "Expeccted function name.").lexeme;

    consume(TokenType::LPAREN,"Expected '(' after function name.");
    std::vector<Param> params;
    if (!check(TokenType::RPAREN)) {
        do {
            std::string paramName = consume (TokenType::IDENTIFIER, "Expected ',' after parameter name.");
            TypeName paramType = typeName();
            params.push_back(Param{paramName, paramType});
        } while (match({TokenType::COMMA}))
    }
    consume(TokenType::ARROW, "Expected '->' before return type.");
    TypeName returnType = typeName();

    StmtPtr body = blockStmt();
    return std::make_unique<functionStmt>(name, std::move(params), returnType, 
                         std::move(body), line);
}

StmtPtr Parser::letDecl() {
    int line = peek().line;
    advance();
    std::string name = consume(TokenType::IDENTIFIER," Expected variable name.").lexeme;
    consume(Token)
}
}
