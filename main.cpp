#include "tuple.h"

#include <string>
#include <iostream>

int main(const int argc, const char* argv[])
{
    Tuple<int> i1;
    Tuple<int, int> i2;
    Tuple<int, int, int> i3;
    Tuple<int, int, int, int> i4;
    Tuple<int, int, int, int, int> i5;
    Tuple<int, int, int, int, int, int> i6;

    Tuple<int, float, double, char, std::string> tup1(1, 1.0f, 1.0, '1', "1");
    Tuple<int, float, double, char, std::string> tup2(::make_tuple(2, 2.0f, 2.0, '2', std::string("2")));

    std::cout << tup1.get<0>() << " " << tup1.get<1>() << " " << tup1.get<2>() << " " << tup1.get<3>() << " " << tup1.get<4>() << std::endl;
    std::cout << tup2.get<0>() << " " << tup2.get<1>() << " " << tup2.get<2>() << " " << tup2.get<3>() << " " << tup2.get<4>() << std::endl;

    tup1.set<0>(10);
    tup1.set<4>(std::string("10"));

    std::cout << tup1.get<0>() << " " << tup1.get<1>() << " " << tup1.get<2>() << " " << tup1.get<3>() << " " << tup1.get<4>() << std::endl;

    /* not yet supported 
    if(tup1 == tup2)
    {
        std::cout << "WTF!?" << std::endl;
    }
    */

    return 0;
}
