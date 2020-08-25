// This file was automatically generated; please do not modify it.

#include "./parser.hpp"

#include <stack>

#include "./lr_node.hpp"
#include "./nt_types.hpp"

using namespace std;

int parse(const std::vector<Token> &tokens, ParseNode *& tree) {
    size_t state = 17;
    size_t count = 0;
    stack<LRNode *> stack;
    stack.push(new LRNode{17});
    bool peeked = true;
    bool eofHit = false;
    bool success = false;
    bool done = false;
    LRNode cur{TokenType::B0F, ""};
    LRNode *newParent = nullptr;
    size_t curPos = 0;
    while (!done) {
        bool eof = false;
        if (!peeked) {
            if (curPos >= tokens.size()) {
                if (eofHit) {
                    eof = true;
                } else {
                    cur = {TokenType::E0F, ""};
                    eofHit = true;
                }
            } else {
                cur = {tokens[curPos].type, tokens[curPos].lexeme};
                ++curPos;
            }
        }
        peeked = false;

        switch (state) {
            case 0:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::RBRACE:
                            state = 26;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 1:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::COMMA:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 5; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::LPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 5; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::LBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 5; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 5; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 5; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::ID:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 5; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::NUM:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 5; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::RPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 5; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::LBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 5; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::STRING:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 5; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 5; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 2:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::RBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::decllist};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::decllist};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 3:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::proc};
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::proc};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            state = 23;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::STRING:
                            state = 20;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACK:
                            state = 38;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LPAREN:
                            state = 24;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACE:
                            state = 12;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::proc};
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::proc};
                            }

                            break;
                        case TokenType::NUM:
                            state = 16;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::ID:
                            state = 9;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        case NonterminalType::lvalue:
                            state = 11;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::fncall:
                            state = 14;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::fn:
                            state = 22;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::proc:
                            state = 0;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::expr:
                            state = 27;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::statement:
                            state = 15;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 4:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::RBRACE:
                            state = 1;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 5:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::ID:
                            state = 34;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        case NonterminalType::decllist:
                            state = 2;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::decl:
                            state = 19;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 6:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::RPAREN:
                            state = 42;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::COMMA:
                            state = 39;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 7:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::STRING:
                            state = 20;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::NUM:
                            state = 16;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::ID:
                            state = 33;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACK:
                            state = 38;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LPAREN:
                            state = 24;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACE:
                            state = 12;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        case NonterminalType::fncall:
                            state = 14;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::fn:
                            state = 31;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::lvalue:
                            state = 11;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::expr:
                            state = 41;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 8:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::COMMA:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::LBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::LPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::ID:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::NUM:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::RPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::LBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::STRING:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 9:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::COMMA:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::LPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::LBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::NUM:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::ID:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::RPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::EQUALS:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::lvalue};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::lvalue};
                            }

                            break;
                        case TokenType::STRING:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::LBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 10:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::LBRACE:
                            state = 3;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 11:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::EQUALS:
                            state = 7;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 12:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::proc};
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::proc};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            state = 23;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::STRING:
                            state = 20;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACK:
                            state = 38;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LPAREN:
                            state = 24;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACE:
                            state = 12;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::proc};
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::proc};
                            }

                            break;
                        case TokenType::NUM:
                            state = 16;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::ID:
                            state = 9;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        case NonterminalType::lvalue:
                            state = 11;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::fncall:
                            state = 14;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::fn:
                            state = 22;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::proc:
                            state = 35;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::expr:
                            state = 27;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::statement:
                            state = 15;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 13:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::COMMA:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::LPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::LBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::ID:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::NUM:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::RPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::LBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::STRING:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 14:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::NUM:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::ID:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::RPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::STRING:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::COMMA:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 15:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::proc};
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::proc};
                            }

                            break;
                        case TokenType::STRING:
                            state = 20;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::SEMICOLON:
                            state = 23;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACK:
                            state = 38;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LPAREN:
                            state = 24;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACE:
                            state = 12;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::proc};
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::proc};
                            }

                            break;
                        case TokenType::NUM:
                            state = 16;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::ID:
                            state = 9;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        case NonterminalType::lvalue:
                            state = 11;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::fncall:
                            state = 14;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::fn:
                            state = 22;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::proc:
                            state = 28;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::expr:
                            state = 27;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::statement:
                            state = 15;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 16:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::NUM:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::ID:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::RPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::STRING:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::COMMA:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 17:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::B0F:
                            state = 18;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 18:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::proc};
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::proc};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            state = 23;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::STRING:
                            state = 20;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACK:
                            state = 38;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LPAREN:
                            state = 24;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACE:
                            state = 12;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::proc};
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::proc};
                            }

                            break;
                        case TokenType::ID:
                            state = 9;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::NUM:
                            state = 16;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        case NonterminalType::lvalue:
                            state = 11;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::fncall:
                            state = 14;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::fn:
                            state = 22;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::proc:
                            state = 21;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::expr:
                            state = 27;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::statement:
                            state = 15;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 19:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::RBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::decllist};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::decllist};
                            }

                            break;
                        case TokenType::COMMA:
                            state = 5;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 20:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::NUM:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::ID:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::RPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::STRING:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::COMMA:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 21:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::E0F:
                            state = 25;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 22:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::NUM:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::ID:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::RPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::STRING:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LPAREN:
                            state = 37;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::COMMA:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 23:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::SEMICOLON:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::statement};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::statement};
                            }

                            break;
                        case TokenType::LBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::statement};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::statement};
                            }

                            break;
                        case TokenType::LPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::statement};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::statement};
                            }

                            break;
                        case TokenType::ID:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::statement};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::statement};
                            }

                            break;
                        case TokenType::NUM:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::statement};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::statement};
                            }

                            break;
                        case TokenType::LBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::statement};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::statement};
                            }

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::statement};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::statement};
                            }

                            break;
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::statement};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::statement};
                            }

                            break;
                        case TokenType::STRING:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::statement};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::statement};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 24:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::STRING:
                            state = 20;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::NUM:
                            state = 16;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::ID:
                            state = 33;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACK:
                            state = 36;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACE:
                            state = 12;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LPAREN:
                            state = 24;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        case NonterminalType::fncall:
                            state = 14;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::lvalue:
                            state = 11;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::fn:
                            state = 31;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::expr:
                            state = 43;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 25:
                if (cur.isTerminal()) {
                    if (eof) {
                        success = true;
                    }
                    done = true;
                }
                break;
            case 26:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::COMMA:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 6; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::LPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 6; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::LBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 6; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 6; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 6; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::ID:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 6; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::NUM:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 6; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::RPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 6; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::LBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 6; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::STRING:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 6; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 6; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 27:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::SEMICOLON:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::statement};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::statement};
                            }

                            break;
                        case TokenType::STRING:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::statement};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::statement};
                            }

                            break;
                        case TokenType::NUM:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::statement};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::statement};
                            }

                            break;
                        case TokenType::ID:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::statement};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::statement};
                            }

                            break;
                        case TokenType::LBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::statement};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::statement};
                            }

                            break;
                        case TokenType::LPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::statement};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::statement};
                            }

                            break;
                        case TokenType::COMMA:
                            state = 39;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::statement};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::statement};
                            }

                            break;
                        case TokenType::LBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::statement};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::statement};
                            }

                            break;
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::statement};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::statement};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 28:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::proc};
                            for (size_t i = 0; i < 2; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::proc};
                            }

                            break;
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::proc};
                            for (size_t i = 0; i < 2; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::proc};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 29:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::proc};
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::proc};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            state = 23;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::STRING:
                            state = 20;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACK:
                            state = 38;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LPAREN:
                            state = 24;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACE:
                            state = 12;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::proc};
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::proc};
                            }

                            break;
                        case TokenType::ID:
                            state = 9;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::NUM:
                            state = 16;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        case NonterminalType::lvalue:
                            state = 11;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::fncall:
                            state = 14;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::fn:
                            state = 22;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::proc:
                            state = 4;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::expr:
                            state = 27;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::statement:
                            state = 15;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 30:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::LBRACE:
                            state = 29;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 31:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::NUM:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::ID:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::RPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::STRING:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LPAREN:
                            state = 37;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::COMMA:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 32:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::RBRACK:
                            state = 10;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 33:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::COMMA:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::LPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::LBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::ID:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::NUM:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::EQUALS:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::lvalue};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::lvalue};
                            }

                            break;
                        case TokenType::RPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::LBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::STRING:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fn};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fn};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 34:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::COMMA:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::decl};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::decl};
                            }

                            break;
                        case TokenType::RBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::decl};
                            for (size_t i = 0; i < 1; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::decl};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 35:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::RBRACE:
                            state = 13;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 36:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::RBRACK:
                            state = 30;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::ID:
                            state = 34;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        case NonterminalType::decllist:
                            state = 32;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::decl:
                            state = 19;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 37:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::ID:
                            state = 9;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::NUM:
                            state = 16;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::RPAREN:
                            state = 8;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACK:
                            state = 38;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::STRING:
                            state = 20;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACE:
                            state = 12;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LPAREN:
                            state = 24;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        case NonterminalType::lvalue:
                            state = 11;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::fncall:
                            state = 14;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::expr:
                            state = 6;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::fn:
                            state = 22;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 38:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::RBRACK:
                            state = 30;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::ID:
                            state = 34;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        case NonterminalType::decllist:
                            state = 32;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::decl:
                            state = 19;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 39:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 2; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 2; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::RPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 2; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::ID:
                            state = 9;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::NUM:
                            state = 16;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LBRACK:
                            state = 38;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 2; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::STRING:
                            state = 20;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::COMMA:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 2; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LBRACE:
                            state = 12;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::LPAREN:
                            state = 24;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        case NonterminalType::lvalue:
                            state = 11;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::fncall:
                            state = 14;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::fn:
                            state = 22;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case NonterminalType::expr:
                            state = 44;
                            peeked = true;
                            cur = *(stack.top());
                            delete stack.top();
                            stack.pop();
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 40:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::NUM:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::ID:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::RPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::STRING:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::COMMA:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 41:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::NUM:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::ID:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::RPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::STRING:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::COMMA:
                            state = 39;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 42:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::COMMA:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 4; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::LBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 4; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::LPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 4; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 4; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 4; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::ID:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 4; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::NUM:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 4; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::RPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 4; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::LBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 4; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 4; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        case TokenType::STRING:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::fncall};
                            for (size_t i = 0; i < 4; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::fncall};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 43:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::COMMA:
                            state = 39;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::RPAREN:
                            state = 40;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            case 44:
                if (cur.isTerminal()) {
                    switch (cur.getTerminal()) {
                        case TokenType::E0F:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::SEMICOLON:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::NUM:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::ID:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::RPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::STRING:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LPAREN:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::COMMA:
                            state = 39;
                            stack.push(new LRNode{cur.getTerminal(), cur.getLexeme()});
                            stack.push(new LRNode{state});
                            ++count;

                            break;
                        case TokenType::RBRACE:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        case TokenType::LBRACK:
                            peeked = true;
                            newParent = new LRNode{NonterminalType::expr};
                            for (size_t i = 0; i < 3; ++i) {
                                if (stack.size() < 2) {
                                    cerr << "ERROR at " << count << endl;
                                    break;
                                }
                                delete stack.top(); // Delete state node.
                                stack.pop(); // Pop deleted state.
                                auto *child = stack.top();
                                newParent->addChild(child);
                                stack.pop(); // Pop vocabulary.
                            }
                            state = stack.top()->getState();
                            stack.push(newParent);

                            if (!stack.top()->isState() && !stack.top()->isTerminal() && stack.top()->getNonterminal() == NonterminalType::start) {
                                // Success!
                                success = true;
                                done = true;
                            } else {
                                stack.push(new LRNode{cur});
                                cur = {NonterminalType::expr};
                            }

                            break;
                        default:
                            cerr << "Misplaced token:" << state << cur.getTerminal().str() << endl;
                            done = true;
                    }
                } else {
                    switch (cur.getNonterminal()) {
                        default:
                            cerr << "Code 2-" << state << ": internal error" << endl;
                            done = true;
                    }
                }
                break;
            default:
                cerr << "Code 0-" << state << ": internal error" << endl;
                done = true;
        }
    }

    if (!success) {
        return -1;
    }
    // Build parse tree from LRNode tree.
    // TODO augment LRNode class with ParseNode nodes for efficiency.

    return 0;
}
