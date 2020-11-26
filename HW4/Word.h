#ifndef _WORD_H_
#define _WORD_H_
#include "Token.h"
#include "Tag.h"
using namespace std;
class Word : public Token
{
public:
    string lexeme= "";
    Tag *tag_ = new Tag();
    Word *and_ = new Word("&&", tag_->AND);
    Word *or_ = new Word("||", tag_->OR);
    Word *eq = new Word("==", tag_->EQ);
    Word *ne = new Word("!=", tag_->NE);
    Word *le = new Word("<=", tag_->LE);
    Word *ge = new Word(">=", tag_->GE);
    Word *minus = new Word("minus", tag_->MINUS);
    Word *True = new Word("true", tag_->TRUE);
    Word *False = new Word("false", tag_->FALSE);
    Word *temp = new Word("t", tag_->TEMP);

    Word():Token(){};
    Word(string s , int tag):Token(tag)
    {
        lexeme = s;
    };
    string toString()
    {
        return lexeme;
    };
    bool operator!()
    {
        if(this->tag && this->lexeme != "") 
            return false;
        return true;
    }
};

#endif