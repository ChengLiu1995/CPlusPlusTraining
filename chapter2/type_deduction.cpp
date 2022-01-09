//
// 2.7.decltype.cpp
// chapter 2 language usability
// modern cpp tutorial
//

#include <iostream>
#include <type_traits>

template <typename T, typename U>
auto add2(T x, U y) -> decltype(x + y)
{
    return x + y;
}
template <typename T, typename U>
auto add3(T x, U y)
{
    return x + y;
}
int main()
{
    auto w = add2<int, double>(1, 2.0);
    if (std::is_same<decltype(w), double>::value)
    {
        std::cout << "w is double: ";
    }
    std::cout << w << std::endl;
    // after c++14
    auto q = add3<double, int>(1.0, 2);
    if (std::is_same<decltype(q), double>::value)
    {
        std::cout << "q is double: " << std::endl;
    }
    else
    {
        std::cout << "q is int: " << std::endl;
    }
    auto q1 = add3<int, double>(0.1, 2);
    if (std::is_same<decltype(q1), double>::value)
    {
        std::cout << "q is double: " << std::endl;
    }
    else
    {
        std::cout << "q1 is int: " << std::endl;
    }
    return 0;
}