#include "Tag.h"
#include <ctype.h>
#include <map>
class Lexer
{
public:
    int line = 1;
    char peek = ' ';
    map<string, int> words;
    void reserve(Word w)
    {
        words.put(w.lexeme, w);
        words.insert(pair<string, int>(w.lexeme, w));
    }
    Lexer()
    {
        reserve(new Word("if", Tag.IF));
        reserve(new Word("else", Tag.ELSE));
        reserve(new Word("while", Tag.WHILE));
        reserve(new Word("do", Tag.DO));
        reserve(new Word("break", Tag.BREAK));
        reserve(Word.True);
        reserve(Word.False);
        reserve(Type.Int);
        reserve(Type.Char);
        reserve(Type.Bool);
        reserve(Type.Float);
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

        if (isdigit(peek))
        {
            int v = 0;
            do
            {
                v = 10 * v + stoi(peek);
                readch();
            } while (isdigit(peek));
            if (peek != '.')
                return new Num(v);
            float x = v;
            float d = 10;
            for (;;)
            {
                readch();
                if (!isdigit(peek))
                    break;
                x = x + stoi(peek) / d;
                d = d * 10;
            }
            return new Real(x);
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

            Word w = (Word)words.get(s);
            if (w != NULL)
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