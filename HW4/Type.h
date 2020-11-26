#ifndef _TYPE_H_
#define _TYPE_H_
#include "Word.h"
#include "Tag.h"
using namespace std;
class Type : public Word
{
public:
    int width = 0;
    Type():Word(){};
    Type(string s, int tag, int w) : Word(s, tag)
    {
        width = w;
    }
    Tag *tag = new Tag();
    Type *Int = new Type("int", tag_->BASIC, 4);
    Type *Float = new Type("float", tag_->BASIC, 8);
    Type *Char = new Type("char", tag_->BASIC, 1);
    Type *Bool = new Type("bool", tag_->BASIC, 1);

    bool numeric(Type p)
    {
        if (p == *Char || p == *Int || p == *Float)
            return true;
        else
            return false;
    }

    Type max(Type p1, Type p2)
    {
        if (!numeric(p1) || !numeric(p2))
            return {};
        else if (p1 == *Float || p2 == *Float)
            return *Float;
        else if (p1 == *Int || p2 == *Int)
            return *Int;
        else
            return *Char;
    }

    bool operator!=(Type const p1)
    {
        if(p1.width == this->width && p1.tag == this->tag && p1.lexeme == this->lexeme) 
            return false;
        return true;
    }
    bool operator==(Type const p1)
    {
        if(p1.width == this->width && p1.tag == this->tag && p1.lexeme == this->lexeme) 
            return true;
        return false;
    }
};

#endif