#ifndef _LEXER_H_
#define _LEXER_H_
#include <map>
#include <cstdlib>
#include "Type.h"
#include "Num.h"
#include "Real.h"

class Lexer
{
public:
    int line = 1;
    char peek = ' ';
    Word word;
    Type type;
    map<string, Word> words;
    void reserve(Word w)
    {
        words[w.lexeme] = w;
    }
    Lexer()
    {
        Word *tmp = new Word("if", Tag::IF);
        reserve(*tmp);
        tmp = new Word("else", Tag::ELSE);
        reserve(*tmp);
        tmp = new Word("while", Tag::WHILE);
        reserve(*tmp);
        tmp = new Word("do", Tag::DO);
        reserve(*tmp);
        tmp = new Word("break", Tag::BREAK);
        reserve(*tmp);
        delete tmp;

        word.and_ = new Word("&&", Tag::AND);
        word.or_ = new Word("||", Tag::OR);
        word.eq = new Word("==", Tag::EQ);
        word.ne = new Word("!=", Tag::NE);
        word.le = new Word("<=", Tag::LE);
        word.ge = new Word(">=", Tag::GE);
        word.minus = new Word("minus", Tag::MINUS);
        word.True = new Word("true", Tag::TRUE);
        word.False = new Word("false", Tag::FALSE);
        word.temp = new Word("t", Tag::TEMP);

        reserve(*word.True);
        reserve(*word.False);

        type.Int = new Word("int", Tag::BASIC);
        type.Float = new Type("float", Tag::BASIC, 8);
        type.Char = new Type("char", Tag::BASIC, 1);
        type.Bool = new Type("bool", Tag::BASIC, 1);

        reserve(*type.Int);
        reserve(*type.Char);
        reserve(*type.Bool);
        reserve(*type.Float);
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
                return *word.and_;
            else
                return Token('&');
        case '|':
            if (readch('|'))
                return *word.or_;
            else
                return Token('|');
        case '=':
            if (readch('='))
                return *word.eq;
            else
                return Token('=');
        case '!':
            if (readch('='))
                return *word.ne;
            else
                return Token('!');
        case '<':
            if (readch('='))
                return *word.le;
            else
                return Token('<');
        case '>':
            if (readch('='))
                return *word.ge;
            else
                return Token('>');
        }

        if (isdigit(peek))
        {
            int v = 0;
            do
            {
                v = 10 * v + atoi(&peek);
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
                x = x + atoi(&peek) / d;
                d = d * 10;
            }
            return Real(x);
        }

        if (isalpha(peek))
        {
            string b = "";
            do
            {
                b += peek;
                readch();
            } while (isalpha(peek) || isdigit(peek));
            string s = b;
            Word w = words[s];
            if (!w)
                return w;
            w = Word(s, Tag::ID);
            words[s] = w;
            return w;
        }

        Token tok(peek);
        peek = ' ';
        return tok;
    }
};

#endif