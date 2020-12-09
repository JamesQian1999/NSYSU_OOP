#include <iostream>
#include <sstream>
using namespace std;

class Form;

struct Bound_form
{
    const Form &f;
    double val;
    Bound_form(const Form &ff, double v) : f(ff), val(v) {}
};

class Form
{
    friend ostream &operator<<(ostream &, const Bound_form &);
    int prc; // precision
    int wdt; // width, 0 means as wide as necessary
    int fmt; // general, scientific, or fixed
public:
    explicit Form(int p = 6):prc(p) // default precision is 6
    {
        fmt = 0; // general format
        wdt = 0; // as wide as necessary
    }
    Bound_form operator()(double d) // make a Bound_form for *this and d
    {
        return Bound_form(*this, d);
    }
    Form &scientific()
    {
        fmt = ios_base ::scientific;
        return *this;
    }
    Form &fixed()
    {
        fmt = ios_base ::fixed;
        return *this;
    }
    Form &general()
    {
        fmt = 0;
        return *this;
    }
    Form &uppercase();
    Form &lowercase();
    Form &precision(int p)
    {
        prc = p;
        return *this;
    }
    Form &width(int w)
    {
        wdt = w;
        return *this;
    } // applies to all types
    Form &fill(char);
    Form &plus(bool b = true);           // explicit plus
    Form &trailing_zeros(bool b = true); // print trailing zeros
};


ostream &operator<<(ostream &os, const Bound_form &bf)
{
    ostringstream s;       // string streams are described in §21.5.3
    s.precision(bf.f.prc);
    s.setf((ios_base::fmtflags)bf.f.fmt, ios_base::floatfield);
    s << bf.val;          // compose string in s
    return os << s.str(); // output s to os
}