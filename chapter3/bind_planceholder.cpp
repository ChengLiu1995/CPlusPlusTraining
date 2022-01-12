#include <functional>
#include <iostream>
/*
而 std::bind 则是用来绑定函数调用的参数的，它解决的需求是我们有时候可能并不一定能够一次
性获得调用某个函数的全部参数，通过这个函数，我们可以将部分调用参数提前绑定到函数身上成为一
个新的对象，然后在参数齐全后，完成调用。例如：
*/
int foo(int a, int b, int c) {
;
}
int main() {
// 将参数 1,2 绑定到函数 foo 上，但是使用 std::placeholders::_1 来对第一个参数进行占位
auto bindFoo = std::bind(foo, std::placeholders::_1, 1,2);
// 这时调用 bindFoo 时，只需要提供第一个参数即可
bindFoo(1);
}