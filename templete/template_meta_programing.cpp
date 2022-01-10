//https://zh.wikipedia.org/wiki/%E6%A8%A1%E6%9D%BF%E8%B6%85%E7%B7%A8%E7%A8%8B
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

template <int N>
struct Factorial
{
    enum
    {
        value = N * Factorial<N - 1>::value
    };
};

template <>
struct Factorial<0>
{
    enum
    {
        value = 1
    };
};

// template <int n>
// int MyFactorial(n)
// {
//     if (n == 0)
//         return 1;
//     return n * MyFactorial<n - 1>;
// }; 

// Factorial<4>::value == 24
// Factorial<0>::value == 1
// void foo()
// {
//     int x = Factorial<4>::value; // == 24
//     int y = Factorial<0>::value; // == 1
// }

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

// void foo1()
// {
//     int x = factorial(4); // == (4 * 3 * 2 * 1 * 1) == 24
//     int y = factorial(0); // == 0! == 1
// }

template <class Derived>
struct base
{
    void interface()
    {
         // ...
         static_cast<Derived*>(this)->implementation();
         // ...
    }
};

struct derived : base<derived>
{
     void implementation();
};

template <int N>
struct Books
{
   enum
    {
        value = N
    };
};

int main(void)
{
    clock_t start,end;
    start = clock();
    for(int i = 0; i < 10000; i++){
        int y = Factorial<12>::value;
    }
    
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC*1000<<"us"<<endl; 

    start = clock();
    for(int i = 0; i < 10000; i++){
        int x = factorial(12);
    }
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC*1000<<"us"<<endl; 

    return 0;
    // start = clock();
    // for(int i = 0; i < 10000; i++){
    //      int y = MyFactorial<12>;
    // }
    // end = clock();
    // cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC*1000<<"us"<<endl; 

}