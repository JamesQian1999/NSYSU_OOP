#include <iostream>
#include <map>
#include "boost/variant.hpp" 
using namespace std;
int main()
{
    map <std::string, boost::variant<int, string>>;
    return 0;
}