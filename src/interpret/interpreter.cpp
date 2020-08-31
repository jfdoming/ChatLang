#include "./interpreter.hpp"

#include <iostream>

#include "./environment.hpp"

using namespace std;

int interpret(ASTNode *ast) {
    // We should always have an AST at this point, even for an empty program.
    if (!ast) {
        cerr << "Uh-oh! An internal error occurred while interpreting your program. This is probably a bug..." << endl;
        return -2;
    }

    Environment env{ast};

    // Hard-coded library functions.
    

    Value *result = ast->interpret(env);
    if (result) {
        if (*result) {
            cout << result->str() << endl;
        } else {
            cerr << "Returned an error" << endl;
            return -1;
        }
    }

    return 0;
}