#include <iostream>
#include <fstream>
#include <sstream>
#include "kly/lexer.hpp"

std::string readFile(const std::string& path) {
    std::ifstream file(path);
    if (!file) {
        throw std::runtime_error("Could not open file: " + path);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: kly <script.kly>\n";
        return 1;
    }

    std::string source = readFile(argv[1]);
    kly::Lexer lexer(source);
    auto tokens = lexer.scanTokens();

    for (const auto& token : tokens) {
        std::cout << "[line " << token.line << "] "
                  << kly::tokenTypeName(token.type);
        if (!token.lexeme.empty()) {
            std::cout << " '" << token.lexeme << "'";
        }
        std::cout << "\n";
    }

    return 0;
}