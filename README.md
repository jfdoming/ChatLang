# ChatLang
Welcome to ChatLang! This is a language created by two university students over the course of the `Repl.it` language Jam, for the purpose of exploring an idea called "algebraic effects" (for example, see [this](https://overreacted.io/algebraic-effects-for-the-rest-of-us/) blog post) in a more C-like language. (It was also for the experience of building a language from scratch! 😅)

This document is a work-in-progress, so please feel free to reach out for any questions in the interim.

## Challenges
We decided to tackle this project without any libraries other than the C++ standard library! This meant building a custom tokenizer, grammar format, parser generator and interpreter. This was a huge adventure reliving past ~~trauma~~ experiences in our compilers course, and was an even bigger undertaking because this time, we were embarking on our language creation journey without any starter code.

The biggest challenge we ran into was that it turns out rolling your own language framework takes a lot of effort! This left us with not much time to create the actual language. However, we persevered and the language you see is the result!

## Next steps for ChatLang

After the competition is complete, we hope to add a compiled version of the language. This is partially because we were more experienced at building an optimized compiled language as opposed to an optimized interpreted one, and at any rate, interpreted languages generally perform worse than compiled ones. Alternatively, we may attempt to write a virtual machine and corresponding bytecode format for the language (à la JVM) with the goal of portability and speed together. Either way, we're looking forward to adding new features and getting feedback!

## Project Structure
Most source files are contained inside `src/` (due to constraints on `Repl.it` the entry point had to be in the root directory). The files inside `src/` are organized by function:
 - `src/scan/`: These are files related to scanning/tokenizing the input into tokens for use by the parser.
 - `src/parse/`: These are files related to parsing the token into a parse tree.
 - `src/simplify/`: These are files related to simplifying the parse tree into an AST.
 - `src/interpret/`: These are files related to executing a given AST.

Additionally, you can find the grammar used in the language inside `src/lang.cfg`. How does this grammar get used by the parser? We used the `tools/pgen/` tool (created by [@jfdoming](https://github.com/jfdoming)!) to automatically generate the main parser state machine (`src/parse/parser.cpp`) along with a list of intermediate states used by it (contained in the so-called "NonterminalType" enumeration).