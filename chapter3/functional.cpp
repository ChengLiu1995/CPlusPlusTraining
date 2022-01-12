#include <functional>
#include <iostream>
/*
https://stackoverflow.com/questions/4113365/what-does-mean-in-c/4113390#4113390
'->' Introducer for the return type of a local lambda expression:
*/
int foo(int para){
    return para;
}

int main(){
    std::function<int(int)> func = foo;
    int important = 0;
    std::function<int(int)> func2 = [&](int value)->int{
        return 1 + value + important;
    };
    std::cout << func(10) << std::endl;
    std::cout << func2(10) << std::endl;        

}