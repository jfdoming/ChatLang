#include <iostream>
#include <vector>

#include "src/scan/input.hpp"
#include "src/scan/tokenizer.hpp"

#include "src/parse/lr_node.hpp"
#include "src/parse/parser.hpp"

#include "src/simplify/ast_node.hpp"
#include "src/simplify/tree_simplifier.hpp"

#include "src/interpret/interpreter.hpp"

using namespace std;

int main(int argc, char **argv) {
    if (argc > 2) {
        cerr << "May supply at most one argument!" << endl;
        return -1;
    }

    Input input{argc, argv};
    if (!input) {
        if (argc == 2) {
            cerr << "Failed to read file!" << endl;
            return -1;
        }
        cerr << "Failed to read from standard input!" << endl;
        return -1;
    }

    bool is_file = argc == 2;

    string line;
    size_t lineNumber = 1;
    vector<Token> tokens;
    vector<string> lines;
    while (input.next(line)) {
        lines.emplace_back(line);
        int failure_index = tokenize(line, lineNumber - 1, tokens);
        if (failure_index != -1) {
            string source = "<stdin>";
            if (is_file) {
                source = argv[1];
            }
            cerr << source << ":" << lineNumber << ":" << failure_index + 1 << ": unexpected character" << endl;
            cerr << line << endl;
            cerr << string(failure_index, ' ') << "^" << endl;
            if (is_file) {
                return -1;
            }
        }
        tokens.emplace_back(TokenType::NEWLINE, "\n", lineNumber - 1, line.size());
        ++lineNumber;
    }

    LRNode *tree;
    int result = parse(tokens, &lines, tree);
    if (result) {
        return result;
    }

    ASTNode *ast;
    simplify(tree, ast);
    delete tree;

    result = interpret(ast);
    delete ast;
    return result;
}
