#include <iostream>

// 必须传递左值
template <typename T> void f1(T&);          
// 可以传递左值或右值
template <typename T> void f2(const T&);    
// 可以传递左值或右值，如果传递一个左值，则发生引用折叠：T&& -> T&
template <typename T> void f3(T&&);

// 使用右值引用的函数模板通常以下面的方式来重载
template <typename T> void f(T&&);          // 绑定到非 const 右值
template <typename T> void f(const T&);     // 绑定到左值和 const 右值

int main()
{
    int i = 1;
    const int ci = 2;

    f1(i);      // T 是 int
    f1(ci);     // T 是 const int
    // f1(5);   // 错误：实参必须是一个左值

    f2(i);      // T 是 int
    f2(ci);     // T 是 int
    f2(5);      // T 是 int

    f3(i);      // T 是 int&
    f3(ci);     // T 是 const int&
    f3(42);     // T 是 int
}