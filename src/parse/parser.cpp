// This file was automatically generated; please do not modify it.

#include "./parser.hpp"

#include "./parse_state.hpp"
#include "./nt_types.hpp"

using namespace std;

int parse(const std::vector<Token> &tokens, LRNode *& tree) {
    ParseState state{36, NonterminalType::start};
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

        if (state.cur.isTerminal()) {
            switch (state.state) {
                case 0:
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACE:
                            state.shift(45);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 1:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STAR:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::MINUS:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::PERCENT:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::COMMA:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::SLASH:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::PLUS:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::STRING:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::E0F:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::NUM:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::ID:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 2:
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACK:
                            state.reduce(3, NonterminalType::decllist);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 3:
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACE:
                            state.shift(26);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 4:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                            state.shift(61);
                            break;
                        case TokenType::PLUS:
                            state.shift(66);
                            break;
                        case TokenType::RPAREN:
                            state.shift(1);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 5:
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(49);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 6:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::PERCENT:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::SLASH:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::STAR:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::PLUS:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::fn);
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
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 7:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PERCENT:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::MINUS:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::SLASH:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::PLUS:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::STRING:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::E0F:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::STAR:
                            state.shift(64);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::NUM:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 8:
                    switch (state.cur.getTerminal()) {
                        case TokenType::EQSIGNAL:
                            state.shift(65);
                            break;
                        case TokenType::EQUALS:
                            state.shift(37);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 9:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PLUS:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::STAR:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::MINUS:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::PERCENT:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::COMMA:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::SLASH:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::STRING:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::E0F:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::NUM:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 10:
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::NUM:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::MINUS:
                            state.shift(61);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::PLUS:
                            state.shift(66);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::STRING:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 11:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PERCENT:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::MINUS:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::SLASH:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::PLUS:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::STRING:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::E0F:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::STAR:
                            state.shift(64);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::NUM:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 12:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACE:
                            state.shift(5);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 13:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(6);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 14:
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::NUM:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::MINUS:
                            state.shift(61);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::PLUS:
                            state.shift(66);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::STRING:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 15:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PERCENT:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::MINUS:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::STAR:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::PLUS:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::SLASH:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::COMMA:
                            state.shift(35);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 16:
                    switch (state.cur.getTerminal()) {
                        case TokenType::ID:
                            state.shift(60);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 17:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::RPAREN:
                            state.shift(30);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 18:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACE:
                            state.shift(21);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 19:
                    switch (state.cur.getTerminal()) {
                        case TokenType::RPAREN:
                            state.shift(30);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 20:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PERCENT:
                            state.reduce(1, NonterminalType::exprcat1);
                            break;
                        case TokenType::MINUS:
                            state.reduce(1, NonterminalType::exprcat1);
                            break;
                        case TokenType::SLASH:
                            state.reduce(1, NonterminalType::exprcat1);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::exprcat1);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::exprcat1);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::exprcat1);
                            break;
                        case TokenType::PLUS:
                            state.reduce(1, NonterminalType::exprcat1);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::exprcat1);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::exprcat1);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::exprcat1);
                            break;
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::exprcat1);
                            break;
                        case TokenType::STAR:
                            state.shift(64);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::exprcat1);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::exprcat1);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::exprcat1);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 21:
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(49);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 22:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PLUS:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::STAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::MINUS:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::PERCENT:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::SLASH:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::LPAREN:
                            state.shift(17);
                            break;
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 23:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PLUS:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::STAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::MINUS:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::PERCENT:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::SLASH:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 24:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PLUS:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::STAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::MINUS:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::PERCENT:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::SLASH:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::LPAREN:
                            state.shift(17);
                            break;
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 25:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::MINUS:
                            state.shift(61);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::PLUS:
                            state.shift(66);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 26:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::PERCENT:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::COMMA:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::SLASH:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::STAR:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::PLUS:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::STRING:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::E0F:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::NUM:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::ID:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 27:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PLUS:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::STAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::MINUS:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::PERCENT:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::SLASH:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 28:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 29:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(6);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 30:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STAR:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::MINUS:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::PERCENT:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::COMMA:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::SLASH:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::PLUS:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::STRING:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::E0F:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::NUM:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 31:
                    switch (state.cur.getTerminal()) {
                        case TokenType::EQUALS:
                            state.shift(37);
                            break;
                        case TokenType::EQSIGNAL:
                            state.shift(65);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 32:
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACK:
                            state.reduce(1, NonterminalType::decllist);
                            break;
                        case TokenType::COMMA:
                            state.shift(16);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 33:
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACK:
                            state.shift(18);
                            break;
                        case TokenType::ID:
                            state.shift(60);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 34:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PERCENT:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::MINUS:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::STAR:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::PLUS:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::SLASH:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::COMMA:
                            state.shift(35);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 35:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PLUS:
                            state.reduce(2, NonterminalType::expratom);
                            break;
                        case TokenType::STAR:
                            state.reduce(2, NonterminalType::expratom);
                            break;
                        case TokenType::ID:
                            state.shift(6);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(2, NonterminalType::expratom);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::SLASH:
                            state.reduce(2, NonterminalType::expratom);
                            break;
                        case TokenType::COMMA:
                            state.reduce(2, NonterminalType::expratom);
                            break;
                        case TokenType::E0F:
                            state.reduce(2, NonterminalType::expratom);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(2, NonterminalType::expratom);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(2, NonterminalType::expratom);
                            break;
                        case TokenType::PERCENT:
                            state.reduce(2, NonterminalType::expratom);
                            break;
                        case TokenType::MINUS:
                            state.reduce(2, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 36:
                    switch (state.cur.getTerminal()) {
                        case TokenType::B0F:
                            state.shift(57);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 37:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 38:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PLUS:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::STAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::MINUS:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::PERCENT:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::SLASH:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::LPAREN:
                            state.shift(19);
                            break;
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 39:
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::PLUS:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::STAR:
                            state.shift(29);
                            break;
                        case TokenType::MINUS:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::PERCENT:
                            state.shift(48);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::SLASH:
                            state.shift(56);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 40:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PERCENT:
                            state.reduce(4, NonterminalType::exprcat2);
                            break;
                        case TokenType::MINUS:
                            state.reduce(4, NonterminalType::exprcat2);
                            break;
                        case TokenType::STAR:
                            state.reduce(4, NonterminalType::exprcat2);
                            break;
                        case TokenType::PLUS:
                            state.reduce(4, NonterminalType::exprcat2);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(4, NonterminalType::exprcat2);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(4, NonterminalType::exprcat2);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(4, NonterminalType::exprcat2);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(4, NonterminalType::exprcat2);
                            break;
                        case TokenType::SLASH:
                            state.reduce(4, NonterminalType::exprcat2);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(4, NonterminalType::exprcat2);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(4, NonterminalType::exprcat2);
                            break;
                        case TokenType::COMMA:
                            state.shift(35);
                            break;
                        case TokenType::STRING:
                            state.reduce(4, NonterminalType::exprcat2);
                            break;
                        case TokenType::E0F:
                            state.reduce(4, NonterminalType::exprcat2);
                            break;
                        case TokenType::NUM:
                            state.reduce(4, NonterminalType::exprcat2);
                            break;
                        case TokenType::ID:
                            state.reduce(4, NonterminalType::exprcat2);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 41:
                if (state.cur.isTerminal()) {
                    if (eof) {
                        state.success = true;
                    }
                    state.done = true;
                }
                    break;
                case 42:
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::PLUS:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::NUM:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::MINUS:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::PERCENT:
                            state.shift(48);
                            break;
                        case TokenType::STRING:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::SLASH:
                            state.shift(56);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::STAR:
                            state.shift(29);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 43:
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(49);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 44:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PERCENT:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::MINUS:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::STAR:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::PLUS:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::SLASH:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::COMMA:
                            state.shift(35);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 45:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::PERCENT:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::COMMA:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::SLASH:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::STAR:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::PLUS:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::STRING:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::E0F:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::NUM:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::ID:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 46:
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::PLUS:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::NUM:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::MINUS:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::PERCENT:
                            state.shift(48);
                            break;
                        case TokenType::STRING:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::SLASH:
                            state.shift(56);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::STAR:
                            state.shift(29);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 47:
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
                    break;
                case 48:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(6);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 49:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 50:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::PERCENT:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::COMMA:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::SLASH:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::STAR:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::PLUS:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::STRING:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::E0F:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::NUM:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 51:
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(49);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 52:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PLUS:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::STAR:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::MINUS:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::PERCENT:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::STRING:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::E0F:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::SLASH:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::COMMA:
                            state.shift(35);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::NUM:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 53:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::PERCENT:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::EQSIGNAL:
                            state.reduce(1, NonterminalType::lvalue);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::PLUS:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::STAR:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::EQUALS:
                            state.reduce(1, NonterminalType::lvalue);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::SLASH:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 54:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PLUS:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::STAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::MINUS:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::PERCENT:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::SLASH:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::E0F:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::NUM:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 55:
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.shift(41);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 56:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(6);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 57:
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(49);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 58:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                            state.shift(61);
                            break;
                        case TokenType::PLUS:
                            state.shift(66);
                            break;
                        case TokenType::RPAREN:
                            state.shift(9);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 59:
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACE:
                            state.shift(50);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 60:
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACK:
                            state.reduce(1, NonterminalType::decl);
                            break;
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::decl);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 61:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(6);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 62:
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACK:
                            state.shift(12);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 63:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PERCENT:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::MINUS:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::SLASH:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::LBRACE:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::PLUS:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::SEMICOLON:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::STRING:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::E0F:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::STAR:
                            state.shift(64);
                            break;
                        case TokenType::LBRACK:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::NUM:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 64:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STAR:
                            state.shift(13);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 65:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 66:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(6);
                            break;
                        default:
                            state.fail();
                    }
                    break;
            }
        } else {
            switch (state.state) {
                case 0:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 1:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 2:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 3:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 4:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 5:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::statement:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(25);
                            break;
                        case NonterminalType::proc:
                            state.shiftNT(0);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
                            break;
                        default:
                            state.error();
                    }
                    break;
                case 6:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 7:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 8:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 9:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 10:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 11:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 12:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 13:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(38);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(40);
                            break;
                        default:
                            state.error();
                    }
                    break;
                case 14:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 15:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 16:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::decllist:
                            state.shiftNT(2);
                            break;
                        case NonterminalType::decl:
                            state.shiftNT(32);
                            break;
                        default:
                            state.error();
                    }
                    break;
                case 17:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(4);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        default:
                            state.error();
                    }
                    break;
                case 18:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 19:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(4);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        default:
                            state.error();
                    }
                    break;
                case 20:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 21:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::statement:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(25);
                            break;
                        case NonterminalType::proc:
                            state.shiftNT(3);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
                            break;
                        default:
                            state.error();
                    }
                    break;
                case 22:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 23:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 24:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 25:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 26:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 27:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 28:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(58);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        default:
                            state.error();
                    }
                    break;
                case 29:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprcat2:
                            state.shiftNT(7);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        default:
                            state.error();
                    }
                    break;
                case 30:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 31:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 32:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 33:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::decllist:
                            state.shiftNT(62);
                            break;
                        case NonterminalType::decl:
                            state.shiftNT(32);
                            break;
                        default:
                            state.error();
                    }
                    break;
                case 34:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 35:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::expratom:
                            state.shiftNT(52);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        default:
                            state.error();
                    }
                    break;
                case 36:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 37:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(10);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(8);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        default:
                            state.error();
                    }
                    break;
                case 38:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 39:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 40:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 41:
                    break;
                case 42:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 43:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::statement:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(25);
                            break;
                        case NonterminalType::proc:
                            state.shiftNT(47);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
                            break;
                        default:
                            state.error();
                    }
                    break;
                case 44:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 45:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 46:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 47:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 48:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(11);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        default:
                            state.error();
                    }
                    break;
                case 49:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 50:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 51:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::statement:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(25);
                            break;
                        case NonterminalType::proc:
                            state.shiftNT(59);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
                            break;
                        default:
                            state.error();
                    }
                    break;
                case 52:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 53:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 54:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 55:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 56:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(63);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        default:
                            state.error();
                    }
                    break;
                case 57:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::expratom:
                            state.shiftNT(34);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::statement:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(25);
                            break;
                        case NonterminalType::proc:
                            state.shiftNT(55);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
                            break;
                        default:
                            state.error();
                    }
                    break;
                case 58:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 59:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 60:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 61:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(22);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(42);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        default:
                            state.error();
                    }
                    break;
                case 62:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 63:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 64:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.error();
                    }
                    break;
                case 65:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(14);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        default:
                            state.error();
                    }
                    break;
                case 66:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(22);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(46);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(15);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        default:
                            state.error();
                    }
                    break;
                default:
                    state.error();
            }
        }
    }

    if (!state.success) {
        return -1;
    }
    
    state.storeResult(tree);

    return 0;
}
