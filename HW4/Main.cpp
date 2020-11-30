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
            int tocken = atoi(t.toString().c_str());
            if (tocken > 255)
                type(tocken);
            else
                cout << "\t(" << (char)tocken << ")" << endl;
        }
    }
}