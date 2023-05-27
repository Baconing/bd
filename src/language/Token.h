//
// Created by bacon on 5/26/23.
//
#include <string>

#ifndef BACONDB_TOKEN_H
#define BACONDB_TOKEN_H

using namespace std;

class Token {
    public:
        string type;
        string value;
        Token(string type, string value) {
            this->type = type;
            this->value = value;
        }
};


#endif //BACONDB_TOKEN_H
