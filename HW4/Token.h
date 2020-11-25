#ifndef _TOKEN_H_
#define _TOKEN_H_
using namespace std;
class Token
{
public:
    int tag;
    Token(){};
    Token(int t)
    {
        tag = t;
    };
    string toString()
    {
        return "" + (char)tag;
    };
};

#endif