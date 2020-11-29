#include <iostream>
#include "Lexer.h"
using namespace std;
int main()
{
    Lexer lexer;
    {
        while (true)
        {
            Token t = lexer.scan();
            cout<<t.toString()<<endl;
        }
    }
}
