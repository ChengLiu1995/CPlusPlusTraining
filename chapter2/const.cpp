#include <iostream>
#include <type_traits>

constexpr int fibonacci(const int n)
{
    return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
    const int len = 9;
    std::cout << fibonacci(len) << std::endl;
    // 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
    std::cout << fibonacci(10) << std::endl;
    return 0;
}