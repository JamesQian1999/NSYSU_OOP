#ifndef _TOKEN_H_
#define _TOKEN_H_
#include <sstream>
using namespace std;
class Token
{
public:
    int tag;
    Token(int t)
    {
        tag = t;
    }
    string toString()
    {
        string s;
        stringstream ss;
        ss << tag;
        ss >> s; 
        return s;
    }
};

#endif