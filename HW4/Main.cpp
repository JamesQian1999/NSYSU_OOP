#include <iostream>
#include "Lexer.h"
using namespace std;
int main()
{
    Lexer lexer;
    {
        int count = 1;
        while (true)
        {
            Token t = lexer.scan(count++);
            int tocken = atoi(t.toString().c_str());
            if (tocken > 255)
                type(tocken);
            else
                cout << "\t(" << (char)tocken << ")" << endl;
        }
    }
}