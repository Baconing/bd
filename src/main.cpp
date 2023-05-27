#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "language/Lexer.h"
#include "language/Token.h"

#define DBFILE "database.bt"

using namespace std;

int main() {
//    fstream file(DBFILE);
//
//
//    file << "asd" << endl;
//    file.close();
//
//    string line;
//    while (getline(file, line)) {
//        cout << line << endl;
//    }
//    file.close();
//
//    string asd;
//    cout << "helo: ";
//    getline(cin, asd);
//
//    cout << asd;
//
//    return 0;

    string code;
    getline(cin, code);
    Lexer l = Lexer(code);
    vector<Token> tokens = l.tokenize();

    stringstream ss;
    for (const auto &item: tokens) {
        ss << item.type << " " << item.value << endl;
    }
    cout << ss.str();

    return 0;
}
