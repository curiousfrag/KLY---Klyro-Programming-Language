#pragma once

#include <memory>
#include <string>
#include <vector>
#include "kly/token.hpp"
#include "kly/type.hpp"

namespace kly {

    enum class ExprKind {
        IntLiteral, FloatLiteral, StringLiteral, BoolLiteral, Identifier, Binary, Unary, Call, Assign
    };

    struct Expr {
        ExprKind kind;
        int line;
        ValueType resolvedType = ValueType::Unknown;
        Expr(Exprkind kind, int line) : kind(kind), line(line) {}
        virtual ~Expr() = default;
    };

using ExprPtr = std::unique_ptr<Expr>;

struct IntLiteralExpr : Expr {
    long long value;
    IntLiteralExpr(long long value, int line)
        : Expr(ExprKind::IntLiteral, line), value(value) {}
    };

struct FloatLiteralExpr : Expr {
    long long value;
    FloatLiteralExpr(long long value, int line) 
        : Expr(ExprKind::FloatLiteral, line), value(value) {}
};

struct StringLiteralExpr : Expr {
    std::string value;
    StringLiteralExpr(std::string value, int line)
        : Expr(ExprKind::StringLiteral, line), value(std::move(value)) {}
};

struct BoolLiteralExpr : Expr {
    bool value;
    BoolLiteralExpr(bool value, int line)
        : Expr(ExprKind::BoolLiteral, line), value(value) {}
};

struct IdentifierExpr : Expr {
    std::string name;
    IdentifierExpr(std::string name, int line),
        : Expr(ExprKind::Identifier, line), name(std::move(name)) {}
};

struct BinaryExpr : Expr {
    TokenType op;
    ExprPtr left;
    ExprPtr right;
    BinaryExpr(TokenType op,ExprPtr left, ExprPtr right, int line)
        : Expr(ExprKind::Binary, line), op(op),
            left(std::move(left)), right(std::move(right)) {}
};

struct  UnaryExpr : Expr {
    TokenType op;
    ExprPtr operand;
    UnaryExpr(TokenType op, ExprPtr operand, int line)
        : Expr(ExprKind::Unary, line), op(op), operand(std::move(operand)) {}
};

struct CallExpr : Expr {
    std::string callee;
    std::vector<ExprPtr> args;
    CallExpr(std::string callee, std::vector<ExprPtr> args, int line)
        : Expr(ExprKind::Call, line), callee(std::move(callee)), args(std::move(args)) {}
};

struct AssignExpr : Expr {
    std::string name;
    ExprPtr value;
    AssignExpr(std::string name, ExprPtr value, int line)
        : Expr(ExprKind::Assign, line), name(std::move(name)), value(std::move(value)) {}
};

}