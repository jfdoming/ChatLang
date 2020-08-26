// This file was automatically generated; please do not modify it.

#include "./parser.hpp"

#include "./parse_state.hpp"
#include "./nt_types.hpp"

using namespace std;

int parse(const std::vector<Token> &tokens, ParseNode *& tree) {
    ParseState state{17, NonterminalType::start};
    stack<LRNode *> stack;
    stack.push(new LRNode{17});
    bool eofHit = false;
    while (!state.done) {
        bool eof = false;
        if (!state.peeked) {
            if (state.curPos >= tokens.size()) {
                if (eofHit) {
                    eof = true;
                } else {
                    state.cur = {TokenType::E0F, ""};
                    eofHit = true;
                }
            } else {
                state.cur = {tokens[state.curPos].type, tokens[state.curPos].lexeme};
                ++state.curPos;
            }
        }
        state.peeked = false;

        switch (state.state) {
            case 0:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACE:
                            state.shift(26);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 1:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::ID:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::NUM:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::STRING:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::E0F:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 2:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACK:
                            state.reduce(3, NonterminalType::decllist);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 3:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(23);
                            break;
                        case TokenType::STRING:
                            state.shift(20);
                            break;
                        case TokenType::LBRACK:
                            state.shift(38);
                            break;
                        case TokenType::LPAREN:
                            state.shift(24);
                            break;
                        case TokenType::LBRACE:
                            state.shift(12);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::NUM:
                            state.shift(16);
                            break;
                        case TokenType::ID:
                            state.shift(9);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::lvalue:
                            state.shiftNT(11);

                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(14);

                            break;
                        case NonterminalType::fn:
                            state.shiftNT(22);

                            break;
                        case NonterminalType::proc:
                            state.shiftNT(0);

                            break;
                        case NonterminalType::expr:
                            state.shiftNT(27);

                            break;
                        case NonterminalType::statement:
                            state.shiftNT(15);

                            break;
                        default:
                            state.error();
                    }
                }
                break;
            case 4:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACE:
                            state.shift(1);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 5:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::ID:
                            state.shift(34);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::decllist:
                            state.shiftNT(2);

                            break;
                        case NonterminalType::decl:
                            state.shiftNT(19);

                            break;
                        default:
                            state.error();
                    }
                }
                break;
            case 6:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::RPAREN:
                            state.shift(42);
                            break;
                        case TokenType::COMMA:
                            state.shift(39);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 7:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::STRING:
                            state.shift(20);
                            break;
                        case TokenType::NUM:
                            state.shift(16);
                            break;
                        case TokenType::ID:
                            state.shift(33);
                            break;
                        case TokenType::LBRACK:
                            state.shift(38);
                            break;
                        case TokenType::LPAREN:
                            state.shift(24);
                            break;
                        case TokenType::LBRACE:
                            state.shift(12);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fncall:
                            state.shiftNT(14);

                            break;
                        case NonterminalType::fn:
                            state.shiftNT(31);

                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(11);

                            break;
                        case NonterminalType::expr:
                            state.shiftNT(41);

                            break;
                        default:
                            state.error();
                    }
                }
                break;
            case 8:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::NUM:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::E0F:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::STRING:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 9:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::EQUALS:
                            state.reduce(1, NonterminalType::lvalue);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 10:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACE:
                            state.shift(3);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 11:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::EQUALS:
                            state.shift(7);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 12:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(23);
                            break;
                        case TokenType::STRING:
                            state.shift(20);
                            break;
                        case TokenType::LBRACK:
                            state.shift(38);
                            break;
                        case TokenType::LPAREN:
                            state.shift(24);
                            break;
                        case TokenType::LBRACE:
                            state.shift(12);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::NUM:
                            state.shift(16);
                            break;
                        case TokenType::ID:
                            state.shift(9);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::lvalue:
                            state.shiftNT(11);

                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(14);

                            break;
                        case NonterminalType::fn:
                            state.shiftNT(22);

                            break;
                        case NonterminalType::proc:
                            state.shiftNT(35);

                            break;
                        case NonterminalType::expr:
                            state.shiftNT(27);

                            break;
                        case NonterminalType::statement:
                            state.shiftNT(15);

                            break;
                        default:
                            state.error();
                    }
                }
                break;
            case 13:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::NUM:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::STRING:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::E0F:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 14:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 15:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::STRING:
                            state.shift(20);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(23);
                            break;
                        case TokenType::LBRACK:
                            state.shift(38);
                            break;
                        case TokenType::LPAREN:
                            state.shift(24);
                            break;
                        case TokenType::LBRACE:
                            state.shift(12);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::NUM:
                            state.shift(16);
                            break;
                        case TokenType::ID:
                            state.shift(9);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::lvalue:
                            state.shiftNT(11);

                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(14);

                            break;
                        case NonterminalType::fn:
                            state.shiftNT(22);

                            break;
                        case NonterminalType::proc:
                            state.shiftNT(28);

                            break;
                        case NonterminalType::expr:
                            state.shiftNT(27);

                            break;
                        case NonterminalType::statement:
                            state.shiftNT(15);

                            break;
                        default:
                            state.error();
                    }
                }
                break;
            case 16:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 17:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::B0F:
                            state.shift(18);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 18:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(23);
                            break;
                        case TokenType::STRING:
                            state.shift(20);
                            break;
                        case TokenType::LBRACK:
                            state.shift(38);
                            break;
                        case TokenType::LPAREN:
                            state.shift(24);
                            break;
                        case TokenType::LBRACE:
                            state.shift(12);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::ID:
                            state.shift(9);
                            break;
                        case TokenType::NUM:
                            state.shift(16);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::lvalue:
                            state.shiftNT(11);

                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(14);

                            break;
                        case NonterminalType::fn:
                            state.shiftNT(22);

                            break;
                        case NonterminalType::proc:
                            state.shiftNT(21);

                            break;
                        case NonterminalType::expr:
                            state.shiftNT(27);

                            break;
                        case NonterminalType::statement:
                            state.shiftNT(15);

                            break;
                        default:
                            state.error();
                    }
                }
                break;
            case 19:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACK:
                            state.reduce(1, NonterminalType::decllist);
                            break;
                        case TokenType::COMMA:
                            state.shift(5);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 20:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 21:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.shift(25);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 22:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::LPAREN:
                            state.shift(37);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 23:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 24:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::STRING:
                            state.shift(20);
                            break;
                        case TokenType::NUM:
                            state.shift(16);
                            break;
                        case TokenType::ID:
                            state.shift(33);
                            break;
                        case TokenType::LBRACK:
                            state.shift(36);
                            break;
                        case TokenType::LBRACE:
                            state.shift(12);
                            break;
                        case TokenType::LPAREN:
                            state.shift(24);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fncall:
                            state.shiftNT(14);

                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(11);

                            break;
                        case NonterminalType::fn:
                            state.shiftNT(31);

                            break;
                        case NonterminalType::expr:
                            state.shiftNT(43);

                            break;
                        default:
                            state.error();
                    }
                }
                break;
            case 25:
                if (state.cur.isTerminal()) {
                    if (eof) {
                        state.success = true;
                    }
                    state.done = true;
                }
                break;
            case 26:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::ID:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::NUM:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::STRING:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::E0F:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 27:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::COMMA:
                            state.shift(39);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 28:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACE:
                            state.reduce(2, NonterminalType::proc);
                            break;
                        case TokenType::E0F:
                            state.reduce(2, NonterminalType::proc);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 29:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(23);
                            break;
                        case TokenType::STRING:
                            state.shift(20);
                            break;
                        case TokenType::LBRACK:
                            state.shift(38);
                            break;
                        case TokenType::LPAREN:
                            state.shift(24);
                            break;
                        case TokenType::LBRACE:
                            state.shift(12);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::ID:
                            state.shift(9);
                            break;
                        case TokenType::NUM:
                            state.shift(16);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::lvalue:
                            state.shiftNT(11);

                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(14);

                            break;
                        case NonterminalType::fn:
                            state.shiftNT(22);

                            break;
                        case NonterminalType::proc:
                            state.shiftNT(4);

                            break;
                        case NonterminalType::expr:
                            state.shiftNT(27);

                            break;
                        case NonterminalType::statement:
                            state.shiftNT(15);

                            break;
                        default:
                            state.error();
                    }
                }
                break;
            case 30:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACE:
                            state.shift(29);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 31:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::LPAREN:
                            state.shift(37);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 32:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACK:
                            state.shift(10);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 33:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::EQUALS:
                            state.reduce(1, NonterminalType::lvalue);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 34:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::decl);
                            break;
                        case TokenType::RBRACK:
                            state.reduce(1, NonterminalType::decl);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 35:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACE:
                            state.shift(13);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 36:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACK:
                            state.shift(30);
                            break;
                        case TokenType::ID:
                            state.shift(34);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::decllist:
                            state.shiftNT(32);

                            break;
                        case NonterminalType::decl:
                            state.shiftNT(19);

                            break;
                        default:
                            state.error();
                    }
                }
                break;
            case 37:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::ID:
                            state.shift(9);
                            break;
                        case TokenType::NUM:
                            state.shift(16);
                            break;
                        case TokenType::RPAREN:
                            state.shift(8);
                            break;
                        case TokenType::LBRACK:
                            state.shift(38);
                            break;
                        case TokenType::STRING:
                            state.shift(20);
                            break;
                        case TokenType::LBRACE:
                            state.shift(12);
                            break;
                        case TokenType::LPAREN:
                            state.shift(24);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::lvalue:
                            state.shiftNT(11);

                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(14);

                            break;
                        case NonterminalType::expr:
                            state.shiftNT(6);

                            break;
                        case NonterminalType::fn:
                            state.shiftNT(22);

                            break;
                        default:
                            state.error();
                    }
                }
                break;
            case 38:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACK:
                            state.shift(30);
                            break;
                        case TokenType::ID:
                            state.shift(34);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::decllist:
                            state.shiftNT(32);

                            break;
                        case NonterminalType::decl:
                            state.shiftNT(19);

                            break;
                        default:
                            state.error();
                    }
                }
                break;
            case 39:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(2, NonterminalType::expr);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(2, NonterminalType::expr);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(2, NonterminalType::expr);
                            break;
                        case TokenType::ID:
                            state.shift(9);
                            break;
                        case TokenType::NUM:
                            state.shift(16);
                            break;
                        case TokenType::LBRACK:
                            state.shift(38);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(2, NonterminalType::expr);
                            break;
                        case TokenType::STRING:
                            state.shift(20);
                            break;
                        case TokenType::COMMA:
                            state.reduce(2, NonterminalType::expr);
                            break;
                        case TokenType::LBRACE:
                            state.shift(12);
                            break;
                        case TokenType::LPAREN:
                            state.shift(24);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::lvalue:
                            state.shiftNT(11);

                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(14);

                            break;
                        case NonterminalType::fn:
                            state.shiftNT(22);

                            break;
                        case NonterminalType::expr:
                            state.shiftNT(44);

                            break;
                        default:
                            state.error();
                    }
                }
                break;
            case 40:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::NUM:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::STRING:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::COMMA:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 41:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::NUM:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::STRING:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::COMMA:
                            state.shift(39);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 42:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::ID:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::NUM:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::E0F:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::STRING:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 43:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.shift(39);
                            break;
                        case TokenType::RPAREN:
                            state.shift(40);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            case 44:
                if (state.cur.isTerminal()) {
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::NUM:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::STRING:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::COMMA:
                            state.shift(39);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                } else {
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                }
                break;
            default:
                state.error();
        }
    }

    if (!state.success) {
        return -1;
    }
    // Build parse tree from LRNode tree.
    // TODO augment LRNode class with ParseNode nodes for efficiency.

    return 0;
}
