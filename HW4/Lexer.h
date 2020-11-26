#ifndef _LEXER_H_
#define _LEXER_H_

#include <ctype.h>
#include <map>
#include "Word.h"
#include "Type.h"
#include "Token.h"
#include "Num.h"
#include "Real.h"
#include "Tag.h"
using namespace std;
class Lexer
{
public:
    int line = 1;
    char peek = ' ';
    Tag *tag = new Tag();
    map<string, Word> words;
    void reserve(Word w)
    {
        words.insert(pair<string, Word>(w.lexeme, w));
    }
    Lexer()
    {
        Word *tmp = new Word("if", tag->IF);
        reserve(*tmp);
        delete tmp;
        tmp = new Word("else", tag->ELSE);
        reserve(*tmp);
        delete tmp;
        tmp =new Word("while", tag->WHILE);
        reserve(*tmp);
        delete tmp;
        tmp =new Word("do", tag->DO);
        reserve(*tmp);
        delete tmp;
        tmp =new Word("break", tag->BREAK);
        reserve(*tmp);
        delete tmp;
        tmp = new Word();
        reserve(*(tmp->True));
        reserve(*(tmp->False));
        Type *type = new Type();
        reserve(*(type->Int));
        reserve(*(type->Char));
        reserve(*(type->Bool));
        reserve(*(type->Float));
    }
    void readch()
    {
        int i = getchar();
        if (i != -1)
            peek = (char)i;
    }
    bool readch(char c)
    {
        readch();
        if (peek != c)
            return false;
        peek = ' ';
        return true;
    }
    Token scan()
    {
        Word *tmp = new Word();
        for (;; readch())
        {
            if (peek == ' ' || peek == '\t')
                continue;
            else if (peek == '\n')

                line = line + 1;
            else
                break;
        }
        switch (peek)
        {
        case '&':
            if (readch('&'))
                return *(tmp->and_);
            else
                return Token('&');
        case '|':
            if (readch('|'))
                return *(tmp->or_);
            else
                return Token('|');
        case '=':
            if (readch('='))
                return *(tmp->eq);
            else
                return Token('=');
        case '!':
            if (readch('='))
                return *(tmp->ne);
            else
                return Token('!');
        case '<':
            if (readch('='))
                return *(tmp->le);
            else
                return Token('<');
        case '>':
            if (readch('='))
                return *(tmp->ge);
            else
                return Token('>');
        }

        if (isdigit(peek))
        {
            int v = 0;
            do
            {
                string tmp_string(1, peek);
                v = 10 * v + stoi(tmp_string);
                readch();
            } while (isdigit(peek));
            if (peek != '.')
                return Num(v);
            float x = v;
            float d = 10;
            for (;;)
            {
                readch();
                if (!isdigit(peek))
                    break;
                string tmp_string(1, peek);
                x = x + stoi(tmp_string) / d;
                d = d * 10;
            }
            return Real(x);
        }

        if (isalpha(peek))
        {
            string b="";
            do
            {
                b+=peek;
                readch();
            } while (isalpha(peek)||isdigit(peek));
            string s = b;

            Word w = (Word)words[s];
            if (!w)
                return w;
            w = Word(s, tag->ID);
            words.insert(pair<string, Word>(s, w));
            return w;
        }
        Token tok(peek);
        peek = ' ';
        return tok;
    }
};

#endif