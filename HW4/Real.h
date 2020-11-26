#ifndef _REAL_H_
#define _REAL_H_
#include <sstream>
#include "Token.h"
using namespace std;
class Real : public Token
{
public:
    float value;
    Tag *tag = new Tag();
    Real(float v) : Token(tag->REAL)
    {
        value = v;
    }
    string toString()
    {
        ostringstream ss;
        ss << value;
        string s(ss.str());
        return s;
    }
};

#endif