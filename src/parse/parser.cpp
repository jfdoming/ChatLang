// This file was automatically generated; please do not modify it.

#include "./parser.hpp"

#include "./parse_state.hpp"
#include "./nt_types.hpp"

using namespace std;

int parse(const std::vector<Token> &tokens, LRNode *& tree) {
    ParseState state{47, NonterminalType::start};
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
                            state.shift(9);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 1:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::ID:
                            state.shift(54);
                            break;
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::RBRACE:
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(33);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        case TokenType::LBRACK:
                            state.shift(35);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 2:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STARSTAR:
                        case TokenType::PLUS:
                        case TokenType::STAR:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::COMMA:
                        case TokenType::E0F:
                        case TokenType::ID:
                        case TokenType::RBRACE:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::SEMICOLON:
                        case TokenType::STRING:
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 3:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STARSTAR:
                        case TokenType::SLASH:
                        case TokenType::LBRACE:
                        case TokenType::LPAREN:
                        case TokenType::STAR:
                        case TokenType::PLUS:
                        case TokenType::STRING:
                        case TokenType::RPAREN:
                        case TokenType::SEMICOLON:
                        case TokenType::COMMA:
                        case TokenType::E0F:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::RBRACE:
                        case TokenType::LBRACK:
                            state.reduce(3, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 4:
                    switch (state.cur.getTerminal()) {
                        case TokenType::EQUALS:
                            state.shift(64);
                            break;
                        case TokenType::EQSIGNAL:
                            state.shift(63);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 5:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LPAREN:
                            state.shift(8);
                            break;
                        case TokenType::LBRACK:
                        case TokenType::NUM:
                        case TokenType::ID:
                        case TokenType::E0F:
                        case TokenType::SEMICOLON:
                        case TokenType::RPAREN:
                        case TokenType::STRING:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::STARSTAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::COMMA:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::STAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 6:
                    switch (state.cur.getTerminal()) {
                        case TokenType::SLASH:
                            state.shift(60);
                            break;
                        case TokenType::LBRACK:
                        case TokenType::LBRACE:
                        case TokenType::LPAREN:
                        case TokenType::MINUS:
                        case TokenType::STRING:
                        case TokenType::SEMICOLON:
                        case TokenType::E0F:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::NUM:
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::STAR:
                            state.shift(58);
                            break;
                        case TokenType::PERCENT:
                            state.shift(22);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 7:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::PLUS:
                        case TokenType::STARSTAR:
                        case TokenType::COMMA:
                        case TokenType::E0F:
                        case TokenType::ID:
                        case TokenType::RBRACE:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::SEMICOLON:
                        case TokenType::STRING:
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::exprcat3);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 8:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        case TokenType::LBRACK:
                            state.shift(35);
                            break;
                        case TokenType::RPAREN:
                            state.shift(11);
                            break;
                        case TokenType::ID:
                            state.shift(76);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 9:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STARSTAR:
                        case TokenType::PLUS:
                        case TokenType::STAR:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::COMMA:
                        case TokenType::E0F:
                        case TokenType::ID:
                        case TokenType::RBRACE:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::SEMICOLON:
                        case TokenType::STRING:
                        case TokenType::RPAREN:
                            state.reduce(5, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 10:
                    switch (state.cur.getTerminal()) {
                        case TokenType::RPAREN:
                            state.shift(53);
                            break;
                        case TokenType::MINUS:
                            state.shift(40);
                            break;
                        case TokenType::PLUS:
                            state.shift(75);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 11:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::LPAREN:
                        case TokenType::STAR:
                        case TokenType::PLUS:
                        case TokenType::STARSTAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::COMMA:
                        case TokenType::E0F:
                        case TokenType::ID:
                        case TokenType::RBRACE:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::SEMICOLON:
                        case TokenType::STRING:
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 12:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PLUS:
                            state.shift(75);
                            break;
                        case TokenType::LBRACK:
                        case TokenType::STRING:
                        case TokenType::LBRACE:
                        case TokenType::LPAREN:
                        case TokenType::SEMICOLON:
                        case TokenType::E0F:
                        case TokenType::RPAREN:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::MINUS:
                            state.shift(40);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 13:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PLUS:
                            state.shift(75);
                            break;
                        case TokenType::LBRACK:
                        case TokenType::STRING:
                        case TokenType::LBRACE:
                        case TokenType::LPAREN:
                        case TokenType::SEMICOLON:
                        case TokenType::E0F:
                        case TokenType::RPAREN:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::RBRACE:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::MINUS:
                            state.shift(40);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 14:
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.shift(28);
                            break;
                        case TokenType::STAR:
                        case TokenType::PLUS:
                        case TokenType::RBRACE:
                        case TokenType::LBRACK:
                        case TokenType::RPAREN:
                        case TokenType::SEMICOLON:
                        case TokenType::STRING:
                        case TokenType::STARSTAR:
                        case TokenType::NUM:
                        case TokenType::ID:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::E0F:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                            state.reduce(3, NonterminalType::exprcat2);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 15:
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACK:
                            state.reduce(3, NonterminalType::decllist);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 16:
                    switch (state.cur.getTerminal()) {
                        case TokenType::SEMICOLON:
                            state.shift(33);
                            break;
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::RBRACE:
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        case TokenType::LBRACK:
                            state.shift(35);
                            break;
                        case TokenType::ID:
                            state.shift(54);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 17:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::LBRACK:
                            state.shift(35);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::RPAREN:
                            state.shift(55);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        case TokenType::ID:
                            state.shift(76);
                            break;
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 18:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STARSTAR:
                            state.shift(70);
                            break;
                        case TokenType::LBRACK:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::SEMICOLON:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::STAR:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 19:
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACE:
                            state.shift(2);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 20:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STARSTAR:
                            state.shift(70);
                            break;
                        case TokenType::LBRACK:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::SEMICOLON:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::STAR:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 21:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STARSTAR:
                        case TokenType::SLASH:
                        case TokenType::LBRACE:
                        case TokenType::LPAREN:
                        case TokenType::STAR:
                        case TokenType::PLUS:
                        case TokenType::STRING:
                        case TokenType::RPAREN:
                        case TokenType::SEMICOLON:
                        case TokenType::COMMA:
                        case TokenType::E0F:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::RBRACE:
                        case TokenType::LBRACK:
                            state.reduce(2, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 22:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACK:
                            state.shift(51);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        case TokenType::ID:
                            state.shift(73);
                            break;
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 23:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::LBRACK:
                            state.shift(35);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        case TokenType::RPAREN:
                            state.shift(55);
                            break;
                        case TokenType::ID:
                            state.shift(76);
                            break;
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 24:
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.shift(28);
                            break;
                        case TokenType::STAR:
                        case TokenType::PLUS:
                        case TokenType::RBRACE:
                        case TokenType::LBRACK:
                        case TokenType::RPAREN:
                        case TokenType::SEMICOLON:
                        case TokenType::STRING:
                        case TokenType::STARSTAR:
                        case TokenType::NUM:
                        case TokenType::ID:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::E0F:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 25:
                    switch (state.cur.getTerminal()) {
                        case TokenType::RPAREN:
                            state.shift(3);
                            break;
                        case TokenType::MINUS:
                            state.shift(40);
                            break;
                        case TokenType::PLUS:
                            state.shift(75);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 26:
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.shift(28);
                            break;
                        case TokenType::STAR:
                        case TokenType::PLUS:
                        case TokenType::RBRACE:
                        case TokenType::LBRACK:
                        case TokenType::RPAREN:
                        case TokenType::SEMICOLON:
                        case TokenType::STRING:
                        case TokenType::STARSTAR:
                        case TokenType::NUM:
                        case TokenType::ID:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::E0F:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 27:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STARSTAR:
                            state.shift(70);
                            break;
                        case TokenType::LBRACK:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::SEMICOLON:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::STAR:
                            state.reduce(1, NonterminalType::exprcat1);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 28:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        case TokenType::PERCENT:
                        case TokenType::RPAREN:
                        case TokenType::SEMICOLON:
                        case TokenType::STAR:
                        case TokenType::STARSTAR:
                        case TokenType::PLUS:
                        case TokenType::RBRACE:
                        case TokenType::COMMA:
                        case TokenType::SLASH:
                        case TokenType::E0F:
                            state.reduce(2, NonterminalType::exprcat3);
                            break;
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::ID:
                            state.shift(48);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        case TokenType::LBRACK:
                            state.shift(35);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 29:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STARSTAR:
                        case TokenType::SLASH:
                        case TokenType::LBRACE:
                        case TokenType::LPAREN:
                        case TokenType::STAR:
                        case TokenType::PLUS:
                        case TokenType::STRING:
                        case TokenType::RPAREN:
                        case TokenType::SEMICOLON:
                        case TokenType::COMMA:
                        case TokenType::E0F:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::RBRACE:
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 30:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACE:
                            state.shift(1);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 31:
                    switch (state.cur.getTerminal()) {
                        case TokenType::SEMICOLON:
                            state.shift(33);
                            break;
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::RBRACE:
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        case TokenType::ID:
                            state.shift(54);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        case TokenType::LBRACK:
                            state.shift(35);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 32:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LPAREN:
                            state.shift(37);
                            break;
                        case TokenType::LBRACK:
                        case TokenType::NUM:
                        case TokenType::ID:
                        case TokenType::E0F:
                        case TokenType::SEMICOLON:
                        case TokenType::RPAREN:
                        case TokenType::STRING:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::STARSTAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::COMMA:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::STAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 33:
                    switch (state.cur.getTerminal()) {
                        case TokenType::SEMICOLON:
                        case TokenType::LBRACK:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::NUM:
                        case TokenType::ID:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::MINUS:
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 34:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STARSTAR:
                        case TokenType::PLUS:
                        case TokenType::STAR:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::COMMA:
                        case TokenType::E0F:
                        case TokenType::ID:
                        case TokenType::RBRACE:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::SEMICOLON:
                        case TokenType::STRING:
                        case TokenType::RPAREN:
                            state.reduce(6, NonterminalType::fn);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 35:
                    switch (state.cur.getTerminal()) {
                        case TokenType::ID:
                            state.shift(46);
                            break;
                        case TokenType::RBRACK:
                            state.shift(72);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 36:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::LPAREN:
                        case TokenType::STAR:
                        case TokenType::PLUS:
                        case TokenType::STARSTAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::COMMA:
                        case TokenType::E0F:
                        case TokenType::ID:
                        case TokenType::RBRACE:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::SEMICOLON:
                        case TokenType::STRING:
                        case TokenType::RPAREN:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 37:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::ID:
                            state.shift(76);
                            break;
                        case TokenType::LBRACK:
                            state.shift(35);
                            break;
                        case TokenType::RPAREN:
                            state.shift(11);
                            break;
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 38:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::ID:
                            state.shift(54);
                            break;
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::RBRACE:
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(33);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        case TokenType::LBRACK:
                            state.shift(35);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 39:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::PLUS:
                        case TokenType::STARSTAR:
                        case TokenType::COMMA:
                        case TokenType::E0F:
                        case TokenType::ID:
                        case TokenType::RBRACE:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::SEMICOLON:
                        case TokenType::STRING:
                        case TokenType::RPAREN:
                            state.reduce(1, NonterminalType::exprcat3);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 40:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        case TokenType::ID:
                            state.shift(73);
                            break;
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::LBRACK:
                            state.shift(51);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 41:
                    switch (state.cur.getTerminal()) {
                        case TokenType::NUM:
                            state.shift(21);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 42:
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACE:
                            state.shift(34);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 43:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STARSTAR:
                        case TokenType::SLASH:
                        case TokenType::LBRACE:
                        case TokenType::LPAREN:
                        case TokenType::STAR:
                        case TokenType::PLUS:
                        case TokenType::STRING:
                        case TokenType::RPAREN:
                        case TokenType::SEMICOLON:
                        case TokenType::COMMA:
                        case TokenType::E0F:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::RBRACE:
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 44:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                            state.shift(40);
                            break;
                        case TokenType::RPAREN:
                            state.shift(36);
                            break;
                        case TokenType::PLUS:
                            state.shift(75);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 45:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::ID:
                            state.shift(54);
                            break;
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::RBRACE:
                        case TokenType::E0F:
                            state.reduce(0, NonterminalType::proc);
                            break;
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        case TokenType::SEMICOLON:
                            state.shift(33);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        case TokenType::LBRACK:
                            state.shift(35);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 46:
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                        case TokenType::RBRACK:
                            state.reduce(1, NonterminalType::decl);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 47:
                    switch (state.cur.getTerminal()) {
                        case TokenType::B0F:
                            state.shift(45);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 48:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LPAREN:
                            state.shift(23);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 49:
                    switch (state.cur.getTerminal()) {
                        case TokenType::STARSTAR:
                            state.shift(70);
                            break;
                        case TokenType::LBRACK:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::E0F:
                        case TokenType::STRING:
                        case TokenType::SEMICOLON:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::SLASH:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::STAR:
                            state.reduce(3, NonterminalType::exprcat1);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 50:
                    switch (state.cur.getTerminal()) {
                        case TokenType::SLASH:
                            state.shift(60);
                            break;
                        case TokenType::PERCENT:
                            state.shift(22);
                            break;
                        case TokenType::LBRACK:
                        case TokenType::LBRACE:
                        case TokenType::LPAREN:
                        case TokenType::MINUS:
                        case TokenType::STRING:
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
                            state.shift(58);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 51:
                    switch (state.cur.getTerminal()) {
                        case TokenType::ID:
                            state.shift(46);
                            break;
                        case TokenType::RBRACK:
                            state.shift(72);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 52:
                    if (state.cur.isTerminal()) {
                        state.reduce(3, NonterminalType::start);
                    }
                    break;
                case 53:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::LPAREN:
                        case TokenType::STAR:
                        case TokenType::PLUS:
                        case TokenType::STARSTAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::COMMA:
                        case TokenType::E0F:
                        case TokenType::ID:
                        case TokenType::RBRACE:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::SEMICOLON:
                        case TokenType::STRING:
                        case TokenType::RPAREN:
                            state.reduce(4, NonterminalType::fncall);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 54:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LPAREN:
                            state.shift(23);
                            break;
                        case TokenType::EQSIGNAL:
                        case TokenType::EQUALS:
                            state.reduce(1, NonterminalType::lvalue);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 55:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::LPAREN:
                        case TokenType::STAR:
                        case TokenType::PLUS:
                        case TokenType::STARSTAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::COMMA:
                        case TokenType::E0F:
                        case TokenType::ID:
                        case TokenType::RBRACE:
                        case TokenType::NUM:
                        case TokenType::LBRACK:
                        case TokenType::SEMICOLON:
                        case TokenType::STRING:
                        case TokenType::RPAREN:
                            state.reduce(3, NonterminalType::fncall);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 56:
                    switch (state.cur.getTerminal()) {
                        case TokenType::EQSIGNAL:
                            state.shift(63);
                            break;
                        case TokenType::EQUALS:
                            state.shift(64);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 57:
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.shift(74);
                            break;
                        case TokenType::RBRACK:
                            state.reduce(1, NonterminalType::decllist);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 58:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACK:
                            state.shift(51);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        case TokenType::ID:
                            state.shift(73);
                            break;
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 59:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::STARSTAR:
                        case TokenType::SLASH:
                        case TokenType::LBRACE:
                        case TokenType::LPAREN:
                        case TokenType::STAR:
                        case TokenType::PLUS:
                        case TokenType::STRING:
                        case TokenType::RPAREN:
                        case TokenType::SEMICOLON:
                        case TokenType::COMMA:
                        case TokenType::E0F:
                        case TokenType::ID:
                        case TokenType::NUM:
                        case TokenType::RBRACE:
                        case TokenType::LBRACK:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 60:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACK:
                            state.shift(51);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        case TokenType::ID:
                            state.shift(73);
                            break;
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 61:
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                            state.shift(52);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 62:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::LBRACK:
                            state.shift(35);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::ID:
                            state.shift(76);
                            break;
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 63:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        case TokenType::LBRACK:
                            state.shift(35);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::ID:
                            state.shift(76);
                            break;
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 64:
                    switch (state.cur.getTerminal()) {
                        case TokenType::ID:
                            state.shift(76);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        case TokenType::LBRACK:
                            state.shift(35);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 65:
                    switch (state.cur.getTerminal()) {
                        case TokenType::PLUS:
                            state.shift(75);
                            break;
                        case TokenType::SEMICOLON:
                        case TokenType::LBRACK:
                        case TokenType::STRING:
                        case TokenType::NUM:
                        case TokenType::ID:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::E0F:
                        case TokenType::RBRACE:
                            state.reduce(1, NonterminalType::statement);
                            break;
                        case TokenType::MINUS:
                            state.shift(40);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 66:
                    switch (state.cur.getTerminal()) {
                        case TokenType::COMMA:
                            state.shift(28);
                            break;
                        case TokenType::STAR:
                        case TokenType::PLUS:
                        case TokenType::RBRACE:
                        case TokenType::LBRACK:
                        case TokenType::RPAREN:
                        case TokenType::SEMICOLON:
                        case TokenType::STRING:
                        case TokenType::STARSTAR:
                        case TokenType::NUM:
                        case TokenType::ID:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::E0F:
                        case TokenType::LPAREN:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                            state.reduce(1, NonterminalType::exprcat2);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 67:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LPAREN:
                            state.shift(8);
                            break;
                        case TokenType::LBRACK:
                        case TokenType::NUM:
                        case TokenType::ID:
                        case TokenType::E0F:
                        case TokenType::SEMICOLON:
                        case TokenType::RPAREN:
                        case TokenType::STRING:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::STARSTAR:
                        case TokenType::MINUS:
                        case TokenType::PERCENT:
                        case TokenType::COMMA:
                        case TokenType::LBRACE:
                        case TokenType::SLASH:
                        case TokenType::STAR:
                            state.reduce(1, NonterminalType::expratom);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 68:
                    switch (state.cur.getTerminal()) {
                        case TokenType::RBRACK:
                            state.shift(30);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 69:
                    switch (state.cur.getTerminal()) {
                        case TokenType::SLASH:
                            state.shift(60);
                            break;
                        case TokenType::LBRACK:
                        case TokenType::LBRACE:
                        case TokenType::LPAREN:
                        case TokenType::MINUS:
                        case TokenType::STRING:
                        case TokenType::SEMICOLON:
                        case TokenType::E0F:
                        case TokenType::RBRACE:
                        case TokenType::PLUS:
                        case TokenType::RPAREN:
                        case TokenType::NUM:
                        case TokenType::ID:
                            state.reduce(3, NonterminalType::expr);
                            break;
                        case TokenType::STAR:
                            state.shift(58);
                            break;
                        case TokenType::PERCENT:
                            state.shift(22);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 70:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        case TokenType::LBRACK:
                            state.shift(51);
                            break;
                        case TokenType::ID:
                            state.shift(73);
                            break;
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 71:
                    switch (state.cur.getTerminal()) {
                        case TokenType::E0F:
                        case TokenType::RBRACE:
                            state.reduce(2, NonterminalType::proc);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 72:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LBRACE:
                            state.shift(16);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 73:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LPAREN:
                            state.shift(17);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 74:
                    switch (state.cur.getTerminal()) {
                        case TokenType::ID:
                            state.shift(46);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 75:
                    switch (state.cur.getTerminal()) {
                        case TokenType::MINUS:
                            state.shift(41);
                            break;
                        case TokenType::LBRACK:
                            state.shift(51);
                            break;
                        case TokenType::STRING:
                            state.shift(43);
                            break;
                        case TokenType::LBRACE:
                            state.shift(38);
                            break;
                        case TokenType::ID:
                            state.shift(73);
                            break;
                        case TokenType::LPAREN:
                            state.shift(62);
                            break;
                        case TokenType::NUM:
                            state.shift(29);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 76:
                    switch (state.cur.getTerminal()) {
                        case TokenType::LPAREN:
                            state.shift(17);
                            break;
                        case TokenType::EQSIGNAL:
                        case TokenType::EQUALS:
                            state.reduce(1, NonterminalType::lvalue);
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
                        case NonterminalType::exprcat3:
                            state.shiftNT(66);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(65);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(50);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(32);
                            break;
                        case NonterminalType::proc:
                            state.shiftNT(42);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(27);
                            break;
                        case NonterminalType::statement:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(56);
                            break;
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
                        case NonterminalType::fn:
                            state.shiftNT(32);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(66);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(50);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(10);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(56);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(27);
                            break;
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
                        case NonterminalType::lvalue:
                            state.shiftNT(56);
                            break;
                        case NonterminalType::statement:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(65);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(50);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(32);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(66);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(27);
                            break;
                        case NonterminalType::proc:
                            state.shiftNT(0);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 17:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fn:
                            state.shiftNT(32);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(66);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(27);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(56);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(50);
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
                        case NonterminalType::exprcat3:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(20);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(67);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 23:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fn:
                            state.shiftNT(32);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(66);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(44);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(27);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(56);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(50);
                            break;
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
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(5);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(7);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 29:
                    switch (state.cur.getNonterminal()) {
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
                        case NonterminalType::lvalue:
                            state.shiftNT(56);
                            break;
                        case NonterminalType::statement:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(65);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(50);
                            break;
                        case NonterminalType::proc:
                            state.shiftNT(71);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(32);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(66);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(27);
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
                        case NonterminalType::decllist:
                            state.shiftNT(68);
                            break;
                        case NonterminalType::decl:
                            state.shiftNT(57);
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
                        case NonterminalType::fn:
                            state.shiftNT(32);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(66);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(56);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(10);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(50);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(27);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 38:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::exprcat3:
                            state.shiftNT(66);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(65);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(50);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(32);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(27);
                            break;
                        case NonterminalType::statement:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(56);
                            break;
                        case NonterminalType::proc:
                            state.shiftNT(19);
                            break;
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
                        case NonterminalType::exprcat2:
                            state.shiftNT(27);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(32);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(6);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(26);
                            break;
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
                        default:
                            state.fail();
                    }
                    break;
                case 45:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::proc:
                            state.shiftNT(61);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(66);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(65);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(50);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(32);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(27);
                            break;
                        case NonterminalType::statement:
                            state.shiftNT(31);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(56);
                            break;
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
                        case NonterminalType::decl:
                            state.shiftNT(57);
                            break;
                        case NonterminalType::decllist:
                            state.shiftNT(68);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 52:
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
                        case NonterminalType::exprcat3:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(18);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(67);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
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
                        case NonterminalType::exprcat3:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(49);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(67);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
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
                        case NonterminalType::exprcat3:
                            state.shiftNT(26);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(67);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(25);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(27);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(56);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(50);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 63:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fn:
                            state.shiftNT(67);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(26);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(12);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(27);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(56);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(50);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 64:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::fn:
                            state.shiftNT(67);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(26);
                            break;
                        case NonterminalType::expr:
                            state.shiftNT(13);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(27);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
                        case NonterminalType::lvalue:
                            state.shiftNT(4);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(50);
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
                        case NonterminalType::fn:
                            state.shiftNT(67);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
                        case NonterminalType::expratom:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(14);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 71:
                    switch (state.cur.getNonterminal()) {
                        default:
                            state.fail();
                    }
                    break;
                case 72:
                    switch (state.cur.getNonterminal()) {
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
                        case NonterminalType::decl:
                            state.shiftNT(57);
                            break;
                        case NonterminalType::decllist:
                            state.shiftNT(15);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 75:
                    switch (state.cur.getNonterminal()) {
                        case NonterminalType::expratom:
                            state.shiftNT(39);
                            break;
                        case NonterminalType::exprcat2:
                            state.shiftNT(27);
                            break;
                        case NonterminalType::exprcat1:
                            state.shiftNT(69);
                            break;
                        case NonterminalType::exprcat3:
                            state.shiftNT(24);
                            break;
                        case NonterminalType::fncall:
                            state.shiftNT(59);
                            break;
                        case NonterminalType::fn:
                            state.shiftNT(32);
                            break;
                        default:
                            state.fail();
                    }
                    break;
                case 76:
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
