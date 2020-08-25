#include <iostream>
#include <vector>

#include "src/scan/input.hpp"
#include "src/scan/tokenizer.hpp"

#include "src/parse/parser.hpp"
#include "src/parse/parse_node.hpp"

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
    size_t line_number = 1;
    vector<Token> tokens;
    while (input.next(line)) {
        int failure_index = tokenize(line, tokens);
        if (failure_index != -1) {
            string source = "<stdin>";
            if (is_file) {
                source = argv[1];
            }
            cerr << source << ":" << line_number << ":" << failure_index + 1 << ": unexpected character" << endl;
            cerr << line << endl;
            cerr << string(failure_index, ' ') << "^" << endl;
            if (is_file) {
                return -1;
            }
        }
        ++line_number;
    }

    ParseNode *tree;
    parse(tokens, tree);
}