#ifndef _TYPE_H_
#define _TYPE_H_
#include "Word.h"

class Type : public Word
{
public:
    int width = 0;
    Type(string s, int tag, int w) : Word(s, tag)
    {
        width = w;
    }
    Word
        *Int = new Type("int", Tag::BASIC, 4),
        *Float = new Type("float", Tag::BASIC, 8),
        *Char = new Type("char", Tag::BASIC, 1),
        *Bool = new Type("bool", Tag::BASIC, 1);
    bool numeric(Word p)
    {
        if ( (p.tag == Type::Char->tag && p.lexeme == Type::Char->lexeme) || (p.tag == Type::Int->tag && p.lexeme == Type::Int->lexeme) || (p.tag == Type::Float->tag && p.lexeme == Type::Float->lexeme))
            return true;
        else
            return false;
    }
};

#endif