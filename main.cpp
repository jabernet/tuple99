#include "tuple.h"

#include <string>
#include <iostream>

struct Printer
{
    void operator() (int i) const
    {
        std::cout << i << " ";
    }
};

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

    tup1.set<0>(Tuple<int, int>::Element<0>::type(10));
    tup1.set<4>(std::string("10"));

    std::cout << tup1.get<0>() << " " << tup1.get<1>() << " " << tup1.get<2>() << " " << tup1.get<3>() << " " << tup1.get<4>() << std::endl;

    if(tup1 == tup2)
    {
        std::cout << "WTF!?" << std::endl;
    }

    if (tup1 != tup1)
    {
        std::cout << "WTF!?" << std::endl;
    }

    if (!IsTuple<Tuple<int, float, double, char, std::string> >::value)
    {
        std::cout << "isTuple failed" << std::endl;
    }

    if (IsTuple<int>::value)
    {
        std::cout << "isTuple failed" << std::endl;
    }

    tup1 = tup2;

    make_tuple(1, 2, 3, 4).forEach(Printer());
    std::cout << std::endl;

    if (make_tuple(1) != Tuple<int>(1))
    {
        std::cout << "eq1 failed" << std::endl;
    }
    else
    {
        std::cout << make_tuple(1) << std::endl;
    }
    if (make_tuple(1,2) != Tuple<int, int>(1,2))
    {
        std::cout << "eq2 failed" << std::endl;
    }
    else
    {
        std::cout << make_tuple(1,2) << std::endl;
    }
    if (make_tuple(1, 2, 3) != Tuple<int, int, int>(1, 2, 3))
    {
        std::cout << "eq3 failed" << std::endl;
    }
    else
    {
        std::cout << make_tuple(1,2,3) << std::endl;
    }
    if (make_tuple(1, 2, 3, 4) != Tuple<int, int, int, int>(1, 2, 3, 4))
    {
        std::cout << "eq4 failed" << std::endl;
    }
    else
    {
        std::cout << make_tuple(1,2,3,4) << std::endl;
    }
    if (make_tuple(1, 2, 3, 4, 5) != Tuple<int, int, int, int, int>(1, 2, 3, 4, 5))
    {
        std::cout << "eq5 failed" << std::endl;
    }
    else
    {
        std::cout << make_tuple(1,2,3,4,5) << std::endl;
    }
    if (make_tuple(1, 2, 3, 4, 5, 6) != Tuple<int, int, int, int, int, int>(1, 2, 3, 4, 5, 6))
    {
        std::cout << "eq6 failed" << std::endl;
    }
    else
    {
        std::cout << make_tuple(1,2,3,4,5,6) << std::endl;
    }

    return 0;
}
