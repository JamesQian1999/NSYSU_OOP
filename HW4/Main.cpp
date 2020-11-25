#include <iostream>
#include "Lexer.h"
#include "Token.h"
using namespace std;
int main()
{
    Lexer lexer = new Lexer();
    while (true)
    {
        Token t = lexer.scan();
        cout<<t.toString()<<endl;
    }
}
