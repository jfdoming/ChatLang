// This file was automatically generated; please do not modify it.

#include "./parser.hpp"

#include "./parse_state.hpp"
#include "./nt_types.hpp"

using namespace std;

int parse(const std::vector<Token> &tokens, LRNode *& tree) {
    ParseState state{36, NonterminalType::start};
    while (!state.done) {
        bool eof = false;
        if (!state.peeked) {
            if (state.curPos >= tokens.size()) {
                if (!eof) {
                    state.cur = {TokenType::E0F, ""};
                    eof = true;
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
                        case TokenType::SEMICOLON:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::LPAREN:
                        case TokenType::COMMA:
                        case TokenType::SLASH:
                        case TokenType::LBRACE:
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
                        case TokenType::RPAREN:
                            state.shift(1);
                            break;
                        case TokenType::MINUS:
                            state.shift(61);
                            break;
                        case TokenType::PLUS:
                            state.shift(66);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 5:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
                        case TokenType::RBRACE:
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(49);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 6:
                    switch (state.cur.getTerminal()) {
                        case TokenType::SEMICOLON:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::STAR:
                        case TokenType::RPAREN:
                        case TokenType::PERCENT:
                        case TokenType::MINUS:
                        case TokenType::SLASH:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 7:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STAR:
                            state.shift(64);
                            break;
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::SEMICOLON:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 8:
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
                case 9:
                    switch (state.cur.getTerminal()) {
                        case TokenType::SEMICOLON:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::LBRACK:
                        case TokenType::RPAREN:
                        case TokenType::LBRACE:
                        case TokenType::LPAREN:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::STAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 10:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PLUS:
                            state.shift(66);
                            break;
                        case TokenType::LBRACE:
                        case TokenType::LPAREN:
                        case TokenType::STRING:
                        case TokenType::LBRACK:
                        case TokenType::SEMICOLON:
                        case TokenType::E0F:
                        case TokenType::RPAREN:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::MINUS:
                            state.shift(61);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 11:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STAR:
                            state.shift(64);
                            break;
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::SEMICOLON:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::RPAREN:
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
                        case TokenType::ID:
                            state.shift(6);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 14:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PLUS:
                            state.shift(66);
                            break;
                        case TokenType::LBRACE:
                        case TokenType::LPAREN:
                        case TokenType::STRING:
                        case TokenType::LBRACK:
                        case TokenType::SEMICOLON:
                        case TokenType::E0F:
                        case TokenType::RPAREN:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::MINUS:
                            state.shift(61);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 15:
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.shift(35);
                            break;
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::LBRACK:
                        case TokenType::SEMICOLON:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
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
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
                        case TokenType::RPAREN:
                            state.shift(30);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
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
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::RPAREN:
                            state.shift(30);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 20:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STAR:
                            state.shift(64);
                            break;
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::SEMICOLON:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::exprcat1);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 21:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
                        case TokenType::RBRACE:
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(49);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 22:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LPAREN:
                            state.shift(17);
                            break;
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::E0F:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::STRING:
                        case TokenType::SEMICOLON:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 23:
                    switch (state.cur.getTerminal()) {
                        case TokenType::SEMICOLON:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::LBRACK:
                        case TokenType::RPAREN:
                        case TokenType::LBRACE:
                        case TokenType::LPAREN:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::STAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 24:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LPAREN:
                            state.shift(17);
                            break;
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::E0F:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::STRING:
                        case TokenType::SEMICOLON:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 25:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PLUS:
                            state.shift(66);
                            break;
                        case TokenType::SEMICOLON:
                        case TokenType::STRING:
                        case TokenType::NUM:
                        case TokenType::ID:
                        case TokenType::LBRACK:
                        case TokenType::E0F:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::MINUS:
                            state.shift(61);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 26:
                    switch (state.cur.getTerminal()) {
                        case TokenType::SEMICOLON:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::STAR:
                        case TokenType::RPAREN:
                        case TokenType::PERCENT:
                        case TokenType::MINUS:
                        case TokenType::SLASH:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::COMMA:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 27:
                    switch (state.cur.getTerminal()) {
                        case TokenType::SEMICOLON:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::LBRACK:
                        case TokenType::RPAREN:
                        case TokenType::LBRACE:
                        case TokenType::LPAREN:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::STAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 28:
                    switch (state.cur.getTerminal()) {
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
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
                        default:
                            state.fail();
                    }
                    break;
                case 29:
                    switch (state.cur.getTerminal()) {
                        case TokenType::ID:
                            state.shift(6);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 30:
                    switch (state.cur.getTerminal()) {
                        case TokenType::SEMICOLON:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::LPAREN:
                        case TokenType::COMMA:
                        case TokenType::SLASH:
                        case TokenType::LBRACE:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 31:
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
                case 32:
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.shift(16);
                            break;
                        case TokenType::RBRACK:
                            state.reduce(1, NonterminalType::decllist);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 33:
                    switch (state.cur.getTerminal()) {
                        case TokenType::ID:
                            state.shift(60);
                            break;
                        case TokenType::RBRACK:
                            state.shift(18);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 34:
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.shift(35);
                            break;
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::LBRACK:
                        case TokenType::SEMICOLON:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 35:
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
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::RPAREN:
                        case TokenType::SEMICOLON:
                        case TokenType::STAR:
                        case TokenType::PLUS:
                        case TokenType::RBRACE:
                        case TokenType::COMMA:
                        case TokenType::SLASH:
                        case TokenType::E0F:
                            state.reduce(2, NonterminalType::expratom);
                            break;
                        case TokenType::ID:
                            state.shift(6);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
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
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
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
                        default:
                            state.fail();
                    }
                    break;
                case 38:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LPAREN:
                            state.shift(19);
                            break;
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::E0F:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::STRING:
                        case TokenType::SEMICOLON:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 39:
                    switch (state.cur.getTerminal()) {
                        case TokenType::SLASH:
                            state.shift(56);
                            break;
                        case TokenType::PERCENT:
                            state.shift(48);
                            break;
                        case TokenType::LBRACK:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::STRING:
                        case TokenType::MINUS:
                        case TokenType::SEMICOLON:
                        case TokenType::E0F:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::NUM:
                        case TokenType::ID:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        case TokenType::STAR:
                            state.shift(29);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 40:
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.shift(35);
                            break;
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::LBRACK:
                        case TokenType::SEMICOLON:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                            state.reduce(4, NonterminalType::exprcat2);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 41:
                    if (state.cur.isTerminal()) {
                        state.reduce(3, NonterminalType::start);
                    }
                    break;
                case 42:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STAR:
                            state.shift(29);
                            break;
                        case TokenType::SLASH:
                            state.shift(56);
                            break;
                        case TokenType::LBRACK:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::STRING:
                        case TokenType::MINUS:
                        case TokenType::SEMICOLON:
                        case TokenType::E0F:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::NUM:
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::PERCENT:
                            state.shift(48);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 43:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
                        case TokenType::RBRACE:
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(49);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 44:
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.shift(35);
                            break;
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::LBRACK:
                        case TokenType::SEMICOLON:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 45:
                    switch (state.cur.getTerminal()) {
                        case TokenType::SEMICOLON:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::STAR:
                        case TokenType::RPAREN:
                        case TokenType::PERCENT:
                        case TokenType::MINUS:
                        case TokenType::SLASH:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::COMMA:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 46:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STAR:
                            state.shift(29);
                            break;
                        case TokenType::SLASH:
                            state.shift(56);
                            break;
                        case TokenType::LBRACK:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::STRING:
                        case TokenType::MINUS:
                        case TokenType::SEMICOLON:
                        case TokenType::E0F:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::NUM:
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::PERCENT:
                            state.shift(48);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 47:
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                        case TokenType::RBRACE:
                            state.reduce(2, NonterminalType::proc);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 48:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
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
                        case TokenType::RBRACE:
                        case TokenType::SEMICOLON:
                        case TokenType::E0F:
                        case TokenType::NUM:
                        case TokenType::ID:
                        case TokenType::LBRACK:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::STRING:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 50:
                    switch (state.cur.getTerminal()) {
                        case TokenType::SEMICOLON:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::STAR:
                        case TokenType::RPAREN:
                        case TokenType::PERCENT:
                        case TokenType::MINUS:
                        case TokenType::SLASH:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::COMMA:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 51:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
                        case TokenType::RBRACE:
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(49);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 52:
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.shift(35);
                            break;
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::LBRACE:
                        case TokenType::LPAREN:
                        case TokenType::SLASH:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::SEMICOLON:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 53:
                    switch (state.cur.getTerminal()) {
                        case TokenType::EQUALS:
                        case TokenType::EQSIGNAL:
                            state.reduce(1, NonterminalType::lvalue);
                            break;
                        case TokenType::E0F:
                        case TokenType::COMMA:
                        case TokenType::SLASH:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::STAR:
                        case TokenType::PLUS:
                        case TokenType::RBRACE:
                        case TokenType::LBRACK:
                        case TokenType::STRING:
                        case TokenType::PERCENT:
                        case TokenType::MINUS:
                        case TokenType::NUM:
                        case TokenType::ID:
                        case TokenType::RPAREN:
                        case TokenType::SEMICOLON:
                            state.reduce(1, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 54:
                    switch (state.cur.getTerminal()) {
                        case TokenType::SEMICOLON:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::LBRACK:
                        case TokenType::RPAREN:
                        case TokenType::LBRACE:
                        case TokenType::LPAREN:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::STAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
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
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
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
                        default:
                            state.fail();
                    }
                    break;
                case 57:
                    switch (state.cur.getTerminal()) {
                        case TokenType::SEMICOLON:
                            state.shift(49);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
                        case TokenType::RBRACE:
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 58:
                    switch (state.cur.getTerminal()) {
                        case TokenType::RPAREN:
                            state.shift(9);
                            break;
                        case TokenType::MINUS:
                            state.shift(61);
                            break;
                        case TokenType::PLUS:
                            state.shift(66);
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
                        case TokenType::COMMA:
                        case TokenType::RBRACK:
                            state.reduce(1, NonterminalType::decl);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 61:
                    switch (state.cur.getTerminal()) {
                        case TokenType::ID:
                            state.shift(6);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
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
                        case TokenType::STAR:
                            state.shift(64);
                            break;
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::SEMICOLON:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::RPAREN:
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
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::ID:
                            state.shift(53);
                            break;
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
                        default:
                            state.fail();
                    }
                    break;
                case 66:
                    switch (state.cur.getTerminal()) {
                        case TokenType::ID:
                            state.shift(6);
                            break;
                        case TokenType::NUM:
                            state.shift(54);
                            break;
                        case TokenType::LBRACK:
                            state.shift(33);
                            break;
                        case TokenType::STRING:
                            state.shift(27);
                            break;
                        case TokenType::LBRACE:
                            state.shift(51);
                            break;
                        case TokenType::LPAREN:
                            state.shift(28);
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
                            state.fail();
                    }
                    break;
                case 1:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 2:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 3:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 4:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 5:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
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
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::proc:
                            state.shiftNT(0);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 6:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 7:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 8:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 9:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 10:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 11:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 12:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 13:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::expratom:
                            state.shiftNT(40);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(38);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 14:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 15:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 16:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::decl:
                            state.shiftNT(32);
                            break;
                        case NonterminalType::decllist:
                            state.shiftNT(2);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 17:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(4);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 18:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 19:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(4);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 20:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 21:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
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
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(25);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        case NonterminalType::proc:
                            state.shiftNT(3);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 22:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 23:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 24:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 25:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 26:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 27:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 28:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(58);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 29:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(7);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 30:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 31:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 32:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 33:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::decl:
                            state.shiftNT(32);
                            break;
                        case NonterminalType::decllist:
                            state.shiftNT(62);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 34:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 35:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(52);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 36:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 37:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(8);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(10);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 38:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 39:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 40:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 41:
                    break;
                case 42:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 43:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
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
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(25);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        case NonterminalType::proc:
                            state.shiftNT(47);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 44:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 45:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 46:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 47:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 48:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(11);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 49:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 50:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 51:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
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
                        case NonterminalType::proc:
                            state.shiftNT(59);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(25);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 52:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 53:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 54:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 55:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 56:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(63);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 57:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::statement:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(34);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
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
                        default:
                            state.fail();
                    }
                    break;
                case 58:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 59:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 60:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 61:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(42);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(22);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 62:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 63:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 64:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 65:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::lvalue:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(14);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 66:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(15);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(46);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(22);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(23);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                default:
                    state.error();
            }
        }
    }

    return state.storeResult(tree);
}
