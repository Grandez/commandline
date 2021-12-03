#pragma once

#include <vector>
#include <string>
#include "make_config.h"

using namespace std;

namespace NST {
class sstring : public string {
public:

    sstring();// : string() {}
    sstring(string str);// : string(str) {};
    sstring(const sstring& obj);// : string(obj) {}
    sstring(const char *src);// : string(src) {}
    sstring(char *src);//       : string(src) {}
    sstring(const string& str, size_type pos, size_type n);// : string(str,pos,n) {}

    static sstring concat(const char *sep, ...);
    sstring&   ltrim();
    sstring&   rtrim();
    sstring&   trim();
    sstring&   toUpper();
    sstring&   toLower();

    string  toString();        
    const char*   toChar();
    char*         toArr();
    bool  contains(const char *par);
    bool makeBoolean();

    vector<char *>  tokenize(const char *pat);
    vector<sstring> tokenize(string pat);
	vector<int>     tokenizeNumber(const char* pat);
    sstring         paste(const char *sep, ...);
private:
    void removeQuotes();  
};
}