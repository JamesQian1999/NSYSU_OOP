#include <iostream>
#include "Lexer.h"
using namespace std;
void type(int tocken);
int main()
{
    Lexer lexer;
    {
        while (true)
        {
            Token t = lexer.scan();
            int tocken = atoi(t.toString().c_str());
            if (tocken > 255)
                type(tocken);
            else
                cout << "\t(" << (char)tocken << ")" << endl;
        }
    }
}

void type(int tocken)
{
    switch (tocken)
    {
    case Tag::AND:
        cout << "\t(AND)" << endl;
        break;
    case Tag::BASIC:
        cout << "\t(BASIC)" << endl;
        break;
    case Tag::BREAK:
        cout << "\t(BREAK)" << endl;
        break;
    case Tag::DO:
        cout << "\t(DO)" << endl;
        break;
    case Tag::ELSE:
        cout << "\t(ELSE)" << endl;
        break;
    case Tag::EQ:
        cout << "\t(EQ)" << endl;
        break;
    case Tag::FALSE:
        cout << "\t(FALSE)" << endl;
        break;
    case Tag::GE:
        cout << "\t(GE)" << endl;
        break;
    case Tag::ID:
        cout << "\t(ID)" << endl;
        break;
    case Tag::IF:
        cout << "\t(IF)" << endl;
        break;
    case Tag::INDEX:
        cout << "\t(INDEX)" << endl;
        break;
    case Tag::LE:
        cout << "\t(LE)" << endl;
        break;
    case Tag::MINUS:
        cout << "\t(MINUS)" << endl;
        break;
    case Tag::NE:
        cout << "\t(NE)" << endl;
        break;
    case Tag::NUM:
        cout << "\t(NUM)" << endl;
        break;
    case Tag::OR:
        cout << "\t(OR)" << endl;
        break;
    case Tag::REAL:
        cout << "\t(REAL)" << endl;
        break;
    case Tag::TEMP:
        cout << "\t(TEMP)" << endl;
        break;
    case Tag::TRUE:
        cout << "\t(TRUE)" << endl;
        break;
    case Tag::WHILE:
        cout << "\t(WHILE)" << endl;
        break;
    }
}