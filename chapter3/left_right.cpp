#include <iostream>
#include <string>
using namespace std;
// class Foo {
// const char*&& right = "this is a rvalue"; // 此处字符串字面量为右值
// public:
// void bar() {
// right = "still rvalue"; // 此处字符串字面量为右值
// }
// };

// void reference(std::string &str)
// {
//     std::cout << " 左值" << std::endl;
// }
// void reference(std::string &&str)
// {
//     std::cout << " 右值" << std::endl;
// }
void reference(int &v)
{
    std::cout << " 左值" << std::endl;
}
void reference(int &&v)
{
    std::cout << " 右值" << std::endl;
}
template <typename T>
void pass(T &&v)
{
    std::cout << " 普通传参:";
    reference(v); // 始终调用 reference(int&)
}
// void increase(int &v)
// {
//     v++;
// }
// void foo()
// {
//     double s = 1;
//     increase(s);
// }

#include <iostream>
class A
{
public:
    int *pointer;
    A() : pointer(new int(1))
    {
        std::cout << " 构造" << pointer << std::endl;
    }
    A(A &a) : pointer(new int(*a.pointer))
    {
        std::cout << " 拷贝" << pointer << std::endl;
    } // 无意义的对象拷贝
    A(A &&a) : pointer(a.pointer)
    {
        a.pointer = nullptr;
        std::cout << " 移动" << pointer << std::endl;
    }
    ~A()
    {
        std::cout << " 析构" << pointer << std::endl;
        delete pointer;
    }
};
// 防止编译器优化
A return_rvalue(bool test)
{
    A a, b;
    if (test)
        return a; // 等价于 static_cast<A&&>(a);
    else
        return b; // 等价于 static_cast<A&&>(b);
}
int main()
{
    const char *const &left = "this is an lvalue"; // 此处字符串字面量为左值
    const string &left1 = "this is an lvalue";     //const强行延长右值时间
    std::cout << left << std::endl;
    // std::cout<<left1<<std::endl;
    std::string lv1 = "string,";
    std::string &&rv1 = std::move(lv1);
    std::cout << rv1 << std::endl;
    rv1 = "a";
    std::cout << rv1 << std::endl;
    std::string &&rv2 = "string2,"; //rv2 虽然引用了一个右值，但由于它是一个引用，所以 rv2 依然是一个左值
    std::cout << rv2 << std::endl;
    const std::string &lv2 = lv1 + lv1;
    const int &b = std::move(1); // 合法, 常量左引用允许引用右值
    A obj = return_rvalue(false);
    std::cout << "obj:" << std::endl;
    std::cout << obj.pointer << std::endl;
    std::cout << *obj.pointer << std::endl;

    std::cout << " 传递右值:" << std::endl;
    pass(1); // 1 是右值, 但输出是左值
    std::cout << " 传递左值:" << std::endl;
    int l = 1;
    pass(l); // l 是左值, 输出左值
}