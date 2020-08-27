# ChatLang
Welcome to ChatLang! This is a language created by two university students over the course of the `Repl.it` language Jam, for the purpose of exploring an idea called "algebraic effects" (for example, see [this](https://overreacted.io/algebraic-effects-for-the-rest-of-us/) blog post) in a more C-like language. (It was also for the experience of building a language from scratch! 😅)

This document is a work-in-progress, so please feel free to reach out for any questions in the interim.

## Project Structure
Most source files are contained inside `src/` (due to constraints on `Repl.it` the entry point had to be in the root directory). The files inside `src/` are organized by function:
 - `src/scan/`: These are files related to scanning/tokenizing the input into tokens for use by the parser.
 - `src/parse/`: These are files related to parsing the token into a parse tree.
 - `src/simplify/`: These are files related to simplifying the parse tree into an AST.
 - `src/execute/`: These are files related to executing a given AST.

Additionally, you can find the grammar used in the language inside `src/lang.cfg`. How does this grammar get used by the parser? We used the `tools/pgen/` tool (created by [@jfdoming](https://github.com/jfdoming)!) to automatically generate the main parser state machine (`src/parse/parser.cpp`) along with a list of intermediate states used by it (contained in the so-called "NonterminalType" enumeration).