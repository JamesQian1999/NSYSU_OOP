#ifndef _WORD_H_
#define _WORD_H_
#include "Token.h"
#include "Tag.h"

class Word : public Token
{

public:
    string lexeme = "";
    Word(string s, int tag):Token(tag)
    {
        lexeme = s;
    }
    string toString()
    {
        return lexeme;
    }
    const static Word 
        *and_   = new Word("&&", Tag::AND),
        *or_    = new Word("||", Tag::OR),
        *eq     = new Word("==", Tag::EQ),
        *ne     = new Word("!=", Tag::NE),
        *le     = new Word("<=", Tag::LE),
        *ge     = new Word(">=", Tag::GE),
        *minus  = new Word("minus", Tag::MINUS),
        *True   = new Word("true", Tag::TRUE),
        *False  = new Word("false", Tag::FALSE),
        *temp   = new Word("t", Tag::TEMP);
};

#endif