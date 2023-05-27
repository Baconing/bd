#ifndef BACONDB_LEXER_H
#define BACONDB_LEXER_H

#include <string>
#include <vector>
#include "Token.h"

using namespace std;

class Lexer {
    private:
        string code;
    public:
        Lexer(string code) {
            this->code = code;
        }

        vector<Token> tokenize();

        void setCode(string code) {
            this->code = code;
        }
        string getCode() {
            return this->code;
        }
};

#endif //BACONDB_LEXER_H
