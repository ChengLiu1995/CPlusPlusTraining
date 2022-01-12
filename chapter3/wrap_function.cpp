#include <iostream>
#include <memory>  // std::make_unique
#include <utility> // std::move

using namespace std;
using foo = void(int);

void fuctional(foo f)
{
    f(1);
}
void lambda_expression_capture()
{
    auto important = std::make_unique<int>(1);
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int
    {
        return x + y + v1 + (*v2);
    };
    std::cout << add(3, 4) << std::endl;
}
int main(void)
{
    auto f = [](int value)
    {
        std::cout << value << std::endl;
    };
    fuctional(f);
    f(1);
    lambda_expression_capture();
    return 0;
}