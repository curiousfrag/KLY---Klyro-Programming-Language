#pragma once 

#include <memory>
#include <string>
#include <vector>
#include "kly/ast_expr.hpp"

namespace kly {

enum class StmtKind {
    Let, ExprStmt, Block, If, While, Retrun, Function
};

struct Stmt {
    StmtKind kind;
    int line;
    Stmt(StmtKind kind, int line) : kind(kind), line(line) {}
    virtual ~Stmt() = default;
};

    using StmtPtr = std::unique_ptr<stmt>;

struct TypeName {
    std::string name;
};

struct LetStmt : Stmt {
    std::string name;
        TypeName type;
        ExprPtr initializer;
        LetStmt(std::string name, TypeName type, ExprPtr initializer, int line)
            : Stmt(StmtKind::Let, line), name(std::move(name)),
            type(std::move(type)), initializer(std::move(initializer)) {}
};

struct ExprStmt : Stmt {
    ExprPtr expr;
    ExprStmt(ExprPtr expr,int line) : Stmt(StmtKind::ExprStmt, line), expr(std::move(expr)) {}
};

struct BlockStmt : Stmt {
    std::vector<StmtPtr> statements;
    BlockStmt(std::vector<StmtPtr> statements, int line)
        : Stmt(StmtKind::Block, line), statements(std::move(statements)) {}
};

struct IfStmt : Stmt {
    ExprPtr condition;
    StmtPtr thenBranch;
    StmtPtr elseBranch;
    IfStmt(ExprPtr condition, StmtPtr thenBranch, StmtPtr elseBranch, int line)
        : Stmt(StmtKind::If, line), condition(stf::move(condition)), thenBranch(std::move(thenBranch)), elseBranch(std::move(elseBranch)) {}
};

struct WhileStmt : Stmt {
    ExprPtr condition;
    StmtPtr body;
    WhileStmt(Exprptr condition,StmtPtr body, int line) 
        : Stmt(StmtKind::While, line), condition(std::move(condition)), body(std::move(body)) {}
};

struct ReturnStmt : Stmt {
    ExprPtr value;
    ReturnStmt(ExprPtr value, int line) : Stmt(StmtKind::Retrun, line), value(std::move(value)) {}
};

struct Param {
    std::string name;
    TypeName type;
};

struct FunctionStmt : Stmt {
    std::string name;
    std::vector<param> params;
    TypeName returnType;
    StmtPtr body;
    FunctionStmt(std::string name, std::vector<param> params, TypeName returnType, StmtPtr body, int line) : Stmt(StmtKind::Function, line), name(std::move(name)), params(std::move(params)), returnType(std::move(returnType)) {}
};

}