#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "Lexer.h"
#include "Token.h"

/*
 * create a lexer for a sql like scripting language
 * it will take a basic string and parse it into tokens
 * the tokens will be used by the interpreter to execute commands
 * the lexer will also be used to parse the database file
 */

using namespace std;


vector<Token> Lexer::tokenize() {
    // TODO: implement segments for different statements at ;
    int len = code.length();
    int pos = 0;

    vector<string> keywords = {"add", "insert", "select", "update", "delete", "upsert", "into", "from", "where", "table", "create", "modify", "drop", "describe"};
    vector<string> types = {"string", "char", "uchar", "int", "float", "double", "bool", "uint", "ufloat", "udouble"};
    vector<string> typeMods = {"nullable", "pk"};
    vector<Token> tokens;
    string varChars("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_*:, ");

    while (pos < len) {
        char current = code[pos];
        if (current == ' ' || current == '\n') {
            pos++;
            continue;
        } else if (current == '"') {
            string res("");
            pos++;
            while (code[pos] != '"' && code[pos] != '\n' && pos < len) {
                res += code[pos];
                pos++;
            }

            if (code[pos] != '"') {
                throw runtime_error("Unterminated string @ position " + to_string(pos) + ": \"" + string(1, current) + "\"");
            }
            pos++;
            tokens.emplace_back("variable", res);
        } else if (varChars.find(current) != string::npos) {
            string res("");
            res.append(1, current);
            pos++;
            while (varChars.find(code[pos]) != string::npos && !isspace(code[pos]) && pos < len) {
                res.append(1, code[pos]);
                pos++;
            }

            if (find(keywords.begin(), keywords.end(), res) != keywords.end()) {
                tokens.emplace_back("keyword", res);
            } else if (res[0] == ':') {
                res.clear();
                pos++;
                while (code[pos] != ',' && pos < len) {
                    if (code[pos] != ' ') {
                        res += code[pos];
                    }
                    pos++;
                }
                pos++;

                if (res.length() == 0) continue;

                if (find(types.begin(), types.end(), res) != types.end()) {
                    tokens.emplace_back("type", res);
                } else {
                    throw runtime_error("Invalid type @ position " + to_string(pos) + ": \"" + res + "\"");
                }
            } else {
                throw runtime_error("Invalid identifier @ position " + to_string(pos) + ": \"" + res + "\"");
            }
        } else {
            throw runtime_error("Invalid character @ position " + to_string(pos) + ": \"" + string(1, current) + "\"");
        }
    }

    return tokens;
}