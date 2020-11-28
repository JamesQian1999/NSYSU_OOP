#ifndef _LEXER_H_
#define _LEXER_H_
#include "Type.h"

class Lexer
{
public:
    int line = 1;
    char peek = ' ';
    Hashtable words = new Hashtable();
    void reserve(Word w)
    {
        words.put(w.lexeme, w);
    }
    Lexer()
    {
        Word *tmp =new  Word("if", Tag::IF);
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
        reserve(*Word::True);
        reserve(Word.False);
        reserve(Type.Int);
        reserve(Type.Char);
        reserve(Type.Bool);
        reserve(Type.Float);
    }
    void readch()
    {
        int i = System.in.read();
        if (i != -1)
            peek = (char)i;
        else
        //throw new IOException("End of file reached");
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
                return Word.and;
            else
                return new Token('&');
        case '|':
            if (readch('|'))
                return Word.or ;
            else
                return new Token('|');
        case '=':
            if (readch('='))
                return Word.eq;
            else
                return new Token('=');
        case '!':
            if (readch('='))
                return Word.ne;
            else
                return new Token('!');
        case '<':
            if (readch('='))
                return Word.le;
            else
                return new Token('<');
        case '>':
            if (readch('='))
                return Word.ge;
            else
                return new Token('>');
        }

        if (Character.isDigit(peek))
        {
            int v = 0;
            do
            {
                v = 10 * v + Character.digit(peek, 10);
                readch();
            } while (Character.isDigit(peek));
            if (peek != '.')
                return new Num(v);
            float x = v;
            float d = 10;
            for (;;)
            {
                readch();
                if (!Character.isDigit(peek))
                    break;
                x = x + Character.digit(peek, 10) / d;
                d = d * 10;
            }
            return new Real(x);
        }

        if (Character.isLetter(peek))
        {
            StringBuffer b = new StringBuffer();
            do
            {
                b.append(peek);
                readch();
            } while (Character.isLetterOrDigit(peek));
            String s = b.toString();
            Word w = (Word)words.get(s);
            if (w != null)
                return w;
            w = new Word(s, Tag.ID);
            words.put(s, w);
            return w;
        }

        Token tok = new Token(peek);
        peek = ' ';
        return tok;
    }
};

#endif