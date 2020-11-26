#ifndef _WORD_H_
#define _WORD_H_
#include "Token.h"
#include "Tag.h"
using namespace std;
class Word : public Token
{
public:
    string lexeme= "";
    //Word  *eq, *ne, *le, *ge, *minus, *True, *False, *temp, *and_, *or_;
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
    Word():Token()
    {
    };
    Word(string s , int tag):Token(tag)
    {
        lexeme = s;
        /*
        Tag *tag_ = new Tag();
        and_ = new Word("&&", tag_->AND);
        or_ = new Word("||", tag_->OR);
        eq = new Word("==", tag_->EQ);
        ne = new Word("!=", tag_->NE);
        le = new Word("<=", tag_->LE);
        ge = new Word(">=", tag_->GE);
        minus = new Word("minus", tag_->MINUS);
        True = new Word("true", tag_->TRUE);
        False = new Word("false", tag_->FALSE);
        temp = new Word("t", tag_->TEMP);*/
    };
    string toString()
    {
        return lexeme;
    };
};

#endif