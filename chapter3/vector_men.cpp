#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // int a = 1;
    // std::cout << "a  : " << &a << std::endl;
    // int b = 2;
    // std::cout << "b  : " << &b << std::endl;
    // int c = 3;
    // std::cout << "b  : " << &c << std::endl;
    // vector<int> vec;
    // vec.push_back(a);
    // int d = 4;
    // vec.push_back(std::move(b));
    // std::cout << "t: " << &(vec[0])<<"-"<< vec[0]<<std::endl;
    // std::cout << "t: " << &(vec[1])<<"-"<< vec[1]<<std::endl;
    double a = 1;
    std::cout << "a  : " << &a << std::endl;
    std::string str = "Hello world1111111111111111111111111111111111111111111111";
    std::cout << "str: " << &str << std::endl;

    std::string str1 = "Hello world1.";
    std::cout << "str: " << &str1 << std::endl;
    std::string str2 = "world1111111111111111111111111111111111111111111111";
    cout << "str_test1占 " << sizeof(str2) << " 个字节" << endl;
    std::cout << "str2: " << &str2 << str2 << std::endl;
    std::vector<std::string> v;
    std::cout << "t: " << &v << std::endl;
    // 将使用 push_back(const T&), 即产生拷贝行为
    v.push_back(str);
    v.push_back(std::move(str2));
    // v.push_back("aaaaaaaaaaaaaaa");
    //  v.push_back("bfffffffffffffffffffffffffffff");
    std::cout << "str2: " << &str2 << str2 << std::endl;
    std::cout << "t: " << &(v[0]) << "-" << v[0] << std::endl;
    std::cout << "t: " << &(v[1]) << "-" << v[1] << std::endl;
    // std::cout << "t: " << &(v[2]) << "-" << v[2] << std::endl;
    // std::cout << "t: " << &(v[3]) << "-" << v[3] << std::endl;
    string *temp = &(v[0]);
    string *temp1 = &(v[1]);
    // std::cout << temp << "--" << *temp << std::endl;
    // std::cout << temp1 << "--" << *temp1 << std::endl;
    // // 将输出 "str: Hello world."
    // std::cout << "str: " << str << std::endl;
    // // 将使用 push_back(const T&&), 不会出现拷贝行为
    // // 而整个字符串会被移动到 vector 中，所以有时候 std::move 会用来减少拷贝出现的开销
    // // 这步操作后, str 中的值会变为空
    // v.push_back(std::move(str));
    // // 将输出 "str: "
    // std::cout << "str: " << str << std::endl;

    return 0;
}