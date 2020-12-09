#include <iostream>
#include "Form.h"

using std::cout;
using std::endl;

Form gen4(4); // general format, precision is 4

void f(double d)
{
    Form sci8 = gen4;
    sci8.scientific().precision(8); // scientific format, precision 8
    Form fix8 = gen4;
    fix8.fixed().precision(8);      // fixed format, precision 8
    cout << "default\t= " << d << endl
         << "gen4\t= " << gen4(d) << endl
         << "sci8\t= " << sci8(d) << endl
         << "fix8\t= " << fix8(d) << endl
         << "default\t= " << d << endl;
}

int main()
{
    f(1234.56789);
    f(12.3456789);

    return 0;
}