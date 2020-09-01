#include "./interpreter.hpp"

#include <iostream>

#include "./environment.hpp"
#include "../simplify/nodes/print.hpp"

using namespace std;

int interpret(ASTNode *ast) {
    // We should always have an AST at this point, even for an empty program.
    if (!ast) {
        cerr << "Uh-oh! An internal error occurred while interpreting your program. This is probably a bug..." << endl;
        return -2;
    }

    Environment env{ast};

    // Hard-coded library functions.
    auto *print = new PrintNode;
    env.setEffect("print", print->interpret(env));

    Value *result = ast->interpret(env);
    if (result) {
        if (*result) {
            cout << result->str() << endl;
            if (!result->isAutoDelete()) {
                delete result;
            }
        } else {
            cerr << "Returned an error" << endl;
            if (!result->isAutoDelete()) {
                delete result;
            }
            return -1;
        }
    }

    return 0;
}