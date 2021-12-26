// This file was automatically generated; please do not modify it.

#include "./parser.hpp"

#include "./parse_state.hpp"
#include "./nt_types.hpp"

using namespace std;

int parse(const std::vector<Token> &tokens, std::vector<std::string> *lines, LRNode *& tree) {
    ParseState state{80, NonterminalType::start, lines};
    while (!state.done) {
        bool eof = false;
        if (!state.peeked) {
            if (state.curPos >= tokens.size()) {
                if (!eof) {
                    state.cur = Token{TokenType::E0F, "", 0, 0};
                    eof = true;
                }
            } else {
                state.cur = tokens[state.curPos];
                ++state.curPos;
            }
        }
        state.peeked = false;

        if (state.cur.isTerminal()) {
            switch (state.state) {
                case 0:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::NEWLINE:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::PERCENT:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::LPAREN:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 1:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::NEWLINE:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::PERCENT:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::LPAREN:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 2:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::NEWLINE:
                        case TokenType::STARSTAR:
                        case TokenType::SEMICOLON:
                            state.reduce(4, NonterminalType::exprpar);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(4, NonterminalType::exprparopt);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 3:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::ID:
                            state.shift(7);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::LBRACK:
                            state.shift(64);
                            break;
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 4:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::NEWLINE:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::PERCENT:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 5:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        case TokenType::RBRACE:
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::ID:
                            state.shift(66);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::NEWLINE:
                            state.shift(38);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(32);
                            break;
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::LBRACK:
                            state.shift(64);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 6:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::NEWLINE:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::PERCENT:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 7:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::EQUALS:
                            state.shift(76);
                            break;
                        case TokenType::EQSIGNAL:
                            state.shift(25);
                            break;
                        case TokenType::LPAREN:
                            state.shift(24);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 8:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::STARSTAR:
                            state.shift(46);
                            break;
                        case TokenType::SEMICOLON:
                        case TokenType::NEWLINE:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::STAR:
                            state.reduce(1, NonterminalType::exprcat1);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 9:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::RPAREN:
                            state.shift(2);
                            break;
                        case TokenType::PLUS:
                            state.shift(86);
                            break;
                        case TokenType::MINUS:
                            state.shift(45);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 10:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::COMMA:
                            state.shift(71);
                            break;
                        case TokenType::SLASH:
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 11:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::STARSTAR:
                            state.shift(46);
                            break;
                        case TokenType::SEMICOLON:
                        case TokenType::NEWLINE:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::STAR:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 12:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::STAR:
                            state.shift(78);
                            break;
                        case TokenType::PERCENT:
                            state.shift(70);
                            break;
                        case TokenType::SLASH:
                            state.shift(22);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::SEMICOLON:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 13:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.shift(24);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 14:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.shift(3);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 15:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 16:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.shift(85);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 17:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.shift(85);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 18:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::COMMA:
                            state.shift(91);
                            break;
                        case TokenType::SLASH:
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 19:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::RBRACK:
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::decllist);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 20:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LBRACE:
                            state.shift(29);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 21:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::RBRACK:
                        case TokenType::COMMA:
                            state.reduce(3, NonterminalType::decllist);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 22:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::ID:
                            state.shift(13);
                            break;
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::LBRACK:
                            state.shift(39);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 23:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LBRACE:
                        case TokenType::NUM:
                        case TokenType::MINUS:
                        case TokenType::E0F:
                        case TokenType::NEWLINE:
                        case TokenType::SEMICOLON:
                        case TokenType::LPAREN:
                        case TokenType::ID:
                        case TokenType::LBRACK:
                        case TokenType::STRING:
                        case TokenType::RBRACE:
                            state.reduce(2, NonterminalType::statement);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 24:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::RPAREN:
                            state.shift(77);
                            break;
                        case TokenType::ID:
                            state.shift(59);
                            break;
                        case TokenType::LBRACK:
                            state.shift(64);
                            break;
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 25:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::LBRACK:
                            state.shift(39);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::ID:
                            state.shift(7);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 26:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::MINUS:
                            state.shift(45);
                            break;
                        case TokenType::PLUS:
                            state.shift(86);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(88);
                            break;
                        case TokenType::NEWLINE:
                            state.shift(89);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 27:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::RPAREN:
                            state.shift(77);
                            break;
                        case TokenType::ID:
                            state.shift(59);
                            break;
                        case TokenType::LBRACK:
                            state.shift(64);
                            break;
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 28:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::RBRACE:
                            state.shift(47);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 29:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        case TokenType::RBRACE:
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::ID:
                            state.shift(66);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::NEWLINE:
                            state.shift(38);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(32);
                            break;
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::LBRACK:
                            state.shift(64);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 30:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::STAR:
                            state.shift(78);
                            break;
                        case TokenType::SLASH:
                            state.shift(22);
                            break;
                        case TokenType::PERCENT:
                            state.shift(70);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::SEMICOLON:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 31:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        case TokenType::RBRACE:
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::ID:
                            state.shift(66);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::NEWLINE:
                            state.shift(38);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(32);
                            break;
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::LBRACK:
                            state.shift(64);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 32:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LBRACE:
                        case TokenType::NUM:
                        case TokenType::MINUS:
                        case TokenType::E0F:
                        case TokenType::NEWLINE:
                        case TokenType::SEMICOLON:
                        case TokenType::LPAREN:
                        case TokenType::ID:
                        case TokenType::LBRACK:
                        case TokenType::STRING:
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 33:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::ID:
                            state.shift(21);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 34:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::RBRACE:
                            state.shift(1);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 35:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::RPAREN:
                            state.shift(4);
                            break;
                        case TokenType::PLUS:
                            state.shift(86);
                            break;
                        case TokenType::MINUS:
                            state.shift(45);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 36:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 37:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 38:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LBRACE:
                        case TokenType::NUM:
                        case TokenType::MINUS:
                        case TokenType::E0F:
                        case TokenType::NEWLINE:
                        case TokenType::SEMICOLON:
                        case TokenType::LPAREN:
                        case TokenType::ID:
                        case TokenType::LBRACK:
                        case TokenType::STRING:
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 39:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::ID:
                            state.shift(19);
                            break;
                        case TokenType::RBRACK:
                            state.shift(20);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 40:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LBRACE:
                        case TokenType::NUM:
                        case TokenType::MINUS:
                        case TokenType::E0F:
                        case TokenType::NEWLINE:
                        case TokenType::SEMICOLON:
                        case TokenType::LPAREN:
                        case TokenType::ID:
                        case TokenType::LBRACK:
                        case TokenType::STRING:
                        case TokenType::RBRACE:
                            state.reduce(2, NonterminalType::statement);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 41:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::STAR:
                            state.shift(78);
                            break;
                        case TokenType::SLASH:
                            state.shift(22);
                            break;
                        case TokenType::PERCENT:
                            state.shift(70);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::SEMICOLON:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 42:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::RBRACK:
                            state.shift(68);
                            break;
                        case TokenType::COMMA:
                            state.shift(33);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 43:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::NEWLINE:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::exprcat3);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 44:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        case TokenType::RBRACE:
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::ID:
                            state.shift(66);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(32);
                            break;
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::LBRACK:
                            state.shift(64);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::NEWLINE:
                            state.shift(38);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 45:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        case TokenType::LBRACK:
                            state.shift(64);
                            break;
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::ID:
                            state.shift(13);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 46:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::ID:
                            state.shift(49);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::LBRACK:
                            state.shift(39);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 47:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::NEWLINE:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::PERCENT:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::LPAREN:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 48:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::STARSTAR:
                            state.shift(46);
                            break;
                        case TokenType::SEMICOLON:
                        case TokenType::NEWLINE:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::STAR:
                            state.reduce(1, NonterminalType::exprcat1);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 49:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.shift(24);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 50:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 51:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::PLUS:
                            state.shift(86);
                            break;
                        case TokenType::RPAREN:
                            state.shift(84);
                            break;
                        case TokenType::MINUS:
                            state.shift(45);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 52:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::SEMICOLON:
                            state.shift(40);
                            break;
                        case TokenType::NEWLINE:
                            state.shift(23);
                            break;
                        case TokenType::STARSTAR:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 53:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::COMMA:
                            state.shift(91);
                            break;
                        case TokenType::SLASH:
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 54:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::E0F:
                            state.shift(87);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 55:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::RBRACE:
                            state.shift(0);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 56:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::STARSTAR:
                            state.shift(46);
                            break;
                        case TokenType::SEMICOLON:
                        case TokenType::NEWLINE:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::STAR:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 57:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(2, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 58:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::STAR:
                            state.shift(78);
                            break;
                        case TokenType::SLASH:
                            state.shift(22);
                            break;
                        case TokenType::PERCENT:
                            state.shift(70);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::SEMICOLON:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 59:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.shift(27);
                            break;
                        case TokenType::EQSIGNAL:
                            state.shift(25);
                            break;
                        case TokenType::EQUALS:
                            state.shift(76);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 60:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::NUM:
                            state.shift(57);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 61:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::STAR:
                            state.shift(78);
                            break;
                        case TokenType::SLASH:
                            state.shift(22);
                            break;
                        case TokenType::PERCENT:
                            state.shift(70);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::SEMICOLON:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 62:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.shift(85);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 63:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::E0F:
                        case TokenType::RBRACE:
                            state.reduce(2, NonterminalType::proc);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 64:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::ID:
                            state.shift(19);
                            break;
                        case TokenType::RBRACK:
                            state.shift(20);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 65:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::PLUS:
                            state.shift(86);
                            break;
                        case TokenType::MINUS:
                            state.shift(45);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::SEMICOLON:
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 66:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::EQUALS:
                            state.shift(76);
                            break;
                        case TokenType::EQSIGNAL:
                            state.shift(25);
                            break;
                        case TokenType::LPAREN:
                            state.shift(24);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 67:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::COMMA:
                            state.shift(71);
                            break;
                        case TokenType::SLASH:
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 68:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LBRACE:
                            state.shift(5);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 69:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.shift(85);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 70:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        case TokenType::ID:
                            state.shift(13);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::LBRACK:
                            state.shift(39);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 71:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        case TokenType::ID:
                            state.shift(79);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::LBRACK:
                            state.shift(39);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::STARSTAR:
                        case TokenType::SEMICOLON:
                            state.reduce(2, NonterminalType::exprcat3);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 72:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        case TokenType::RBRACE:
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::ID:
                            state.shift(66);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(32);
                            break;
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::LBRACK:
                            state.shift(64);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::NEWLINE:
                            state.shift(38);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 73:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::PLUS:
                            state.shift(86);
                            break;
                        case TokenType::MINUS:
                            state.shift(45);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::SEMICOLON:
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 74:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.shift(83);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 75:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::NEWLINE:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(3, NonterminalType::exprcat3);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 76:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::LBRACK:
                            state.shift(39);
                            break;
                        case TokenType::ID:
                            state.shift(59);
                            break;
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 77:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::NEWLINE:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::PERCENT:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 78:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        case TokenType::ID:
                            state.shift(13);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::LBRACK:
                            state.shift(39);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 79:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.shift(27);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 80:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::B0F:
                            state.shift(44);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 81:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::NEWLINE:
                            state.shift(23);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(40);
                            break;
                        case TokenType::STARSTAR:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 82:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::STARSTAR:
                            state.shift(46);
                            break;
                        case TokenType::SEMICOLON:
                        case TokenType::NEWLINE:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::STAR:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 83:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::ID:
                            state.shift(7);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::LBRACK:
                            state.shift(64);
                            break;
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 84:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.reduce(4, NonterminalType::exprparopt);
                            break;
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::NEWLINE:
                        case TokenType::STARSTAR:
                        case TokenType::SEMICOLON:
                            state.reduce(4, NonterminalType::exprpar);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 85:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::RPAREN:
                            state.shift(94);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::ID:
                            state.shift(7);
                            break;
                        case TokenType::LBRACK:
                            state.shift(64);
                            break;
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 86:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        case TokenType::LBRACK:
                            state.shift(64);
                            break;
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::ID:
                            state.shift(13);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 87:
                    if (state.cur.isTerminal()) {
                        state.reduce(3, NonterminalType::start);
                    }
                    break;
                case 88:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LBRACE:
                        case TokenType::NUM:
                        case TokenType::MINUS:
                        case TokenType::E0F:
                        case TokenType::NEWLINE:
                        case TokenType::SEMICOLON:
                        case TokenType::LPAREN:
                        case TokenType::ID:
                        case TokenType::LBRACK:
                        case TokenType::STRING:
                        case TokenType::RBRACE:
                            state.reduce(2, NonterminalType::statement);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 89:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LBRACE:
                        case TokenType::NUM:
                        case TokenType::MINUS:
                        case TokenType::E0F:
                        case TokenType::NEWLINE:
                        case TokenType::SEMICOLON:
                        case TokenType::LPAREN:
                        case TokenType::ID:
                        case TokenType::LBRACK:
                        case TokenType::STRING:
                        case TokenType::RBRACE:
                            state.reduce(2, NonterminalType::statement);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 90:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::COMMA:
                            state.shift(71);
                            break;
                        case TokenType::SLASH:
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(3, NonterminalType::exprcat2);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 91:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LBRACE:
                            state.shift(31);
                            break;
                        case TokenType::MINUS:
                            state.shift(60);
                            break;
                        case TokenType::LBRACK:
                            state.shift(39);
                            break;
                        case TokenType::STRING:
                            state.shift(50);
                            break;
                        case TokenType::ID:
                            state.shift(79);
                            break;
                        case TokenType::LPAREN:
                            state.reduce(0, NonterminalType::exprparopt);
                            break;
                        case TokenType::NUM:
                            state.shift(36);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::STARSTAR:
                        case TokenType::SEMICOLON:
                            state.reduce(2, NonterminalType::exprcat3);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 92:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::PERCENT:
                            state.shift(70);
                            break;
                        case TokenType::STAR:
                            state.shift(78);
                            break;
                        case TokenType::SLASH:
                            state.shift(22);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::SEMICOLON:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::expr);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 93:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::LPAREN:
                            state.shift(85);
                            break;
                        case TokenType::NEWLINE:
                        case TokenType::RPAREN:
                        case TokenType::PLUS:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 94:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::NEWLINE:
                        case TokenType::MINUS:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::STAR:
                        case TokenType::PERCENT:
                        case TokenType::SEMICOLON:
                        case TokenType::STARSTAR:
                        case TokenType::SLASH:
                        case TokenType::COMMA:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 95:
                    switch (state.cur.getTerminal().type) {
                        case TokenType::RPAREN:
                            state.shift(6);
                            break;
                        case TokenType::PLUS:
                            state.shift(86);
                            break;
                        case TokenType::MINUS:
                            state.shift(45);
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
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(16);
                            break;
                        case NonterminalType::exprpar:
                            state.shiftNT(15);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(14);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(51);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(30);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(8);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(18);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(43);
                            break;
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
                        case NonterminalType::exprpar:
                            state.shiftNT(52);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(74);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(26);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(41);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(48);
                            break;
                        case NonterminalType::statement:
                            state.shiftNT(72);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(53);
                            break;
                        case NonterminalType::proc:
                            state.shiftNT(55);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(69);
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
                        default:
                            state.fail();
                    }
                    break;
                case 17:
                    switch (state.cur.getNonterminal()) {
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
                        default:
                            state.fail();
                    }
                    break;
                case 22:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(17);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(14);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(56);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(10);
                            break;
                        case NonterminalType::exprpar:
                            state.shiftNT(15);
                            break;
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
                        case NonterminalType::expratom:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::exprpar:
                            state.shiftNT(15);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(16);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(35);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(8);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(74);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(18);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(30);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 25:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::exprpar:
                            state.shiftNT(15);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(14);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(16);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(65);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(8);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(18);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(30);
                            break;
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
                        case NonterminalType::expratom:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::exprpar:
                            state.shiftNT(15);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(16);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(35);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(8);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(74);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(18);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(30);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 28:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 29:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprpar:
                            state.shiftNT(52);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(69);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(53);
                            break;
                        case NonterminalType::statement:
                            state.shiftNT(72);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::proc:
                            state.shiftNT(34);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(74);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(48);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(41);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(26);
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
                        case NonterminalType::exprpar:
                            state.shiftNT(81);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(26);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(92);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(53);
                            break;
                        case NonterminalType::statement:
                            state.shiftNT(72);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::proc:
                            state.shiftNT(28);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(74);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(93);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(48);
                            break;
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
                        case NonterminalType::decllist:
                            state.shiftNT(42);
                            break;
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
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 42:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 43:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 44:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprpar:
                            state.shiftNT(52);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(26);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(41);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(53);
                            break;
                        case NonterminalType::statement:
                            state.shiftNT(72);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(74);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(48);
                            break;
                        case NonterminalType::proc:
                            state.shiftNT(54);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(69);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 45:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprpar:
                            state.shiftNT(15);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(62);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(58);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(14);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(8);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(10);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 46:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprparopt:
                            state.shiftNT(14);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(17);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::exprpar:
                            state.shiftNT(15);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(90);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
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
                        default:
                            state.fail();
                    }
                    break;
                case 57:
                    switch (state.cur.getNonterminal()) {
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
                        case NonterminalType::decllist:
                            state.shiftNT(42);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 65:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 66:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 67:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 68:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 69:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 70:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(17);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(14);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(82);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(10);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::exprpar:
                            state.shiftNT(15);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 71:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprpar:
                            state.shiftNT(15);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(16);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(14);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(75);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 72:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprcat3:
                            state.shiftNT(67);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(74);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(48);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(26);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(61);
                            break;
                        case NonterminalType::statement:
                            state.shiftNT(72);
                            break;
                        case NonterminalType::exprpar:
                            state.shiftNT(52);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::proc:
                            state.shiftNT(63);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(69);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 73:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 74:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 75:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 76:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprpar:
                            state.shiftNT(15);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(14);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(16);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(73);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(8);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(18);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(30);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 77:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 78:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(17);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(11);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(14);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(10);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::exprpar:
                            state.shiftNT(15);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 79:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 80:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 81:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 82:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 83:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(16);
                            break;
                        case NonterminalType::exprpar:
                            state.shiftNT(15);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(14);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(8);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(18);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(30);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(9);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(43);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 84:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 85:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fn:
                            state.shiftNT(16);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::exprpar:
                            state.shiftNT(15);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(14);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(95);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(8);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(18);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(30);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 86:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprpar:
                            state.shiftNT(15);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(93);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(12);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(8);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(10);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(43);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(14);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 87:
                    break;
                case 88:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 89:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 90:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 91:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprpar:
                            state.shiftNT(15);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(37);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(16);
                            break;
                        case NonterminalType::exprparopt:
                            state.shiftNT(14);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(75);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 92:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 93:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 94:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 95:
                    switch (state.cur.getNonterminal()) {
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
