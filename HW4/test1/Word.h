#ifndef _WORD_H_
#define _WORD_H_
#include "Token.h"
#include "Tag.h"

class Word : public Token
{

public:
    string lexeme = "";
    Word() : Token() {}
    Word(string s, int tag) : Token(tag)
    {
        lexeme = s;
    }

    Word *and_, *or_, *eq, *ne, *le, *ge, *minus, *True, *False, *temp;

    string toString()
    {
        return lexeme;
    }

    bool operator !()
    {
        if(lexeme=="" && !tag)
            return true;
        return false;
    }
};


#endif