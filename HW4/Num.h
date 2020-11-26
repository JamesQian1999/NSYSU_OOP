#ifndef _NUM_H_
#define _NUM_H_
#include <sstream>
#include "Token.h"
#include "Tag.h"
using namespace std;
class Num : public Token
{
public:
    int value;
    Tag *tag = new Tag();
    Num(int v):Token(tag->NUM)
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