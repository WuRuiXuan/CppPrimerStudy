#include <iostream>

int main()
{
    // auto i = 0, *p = &i; // 正确：i 是整数、p 是整型指针
    // auto sz = 0, pi = 3.14; // 错误： sz 和 pi 的类型不一致

    int i = 0, &r = i;
    auto a = r; // a 是一个整数（r 是 i 的别名，而 i 是一个整数）
    
    const int ci = i, &cr = ci;
    auto b = ci; // b 是一个整数（ci 的顶层 const 特性被忽略掉了）
    auto c = cr; // c 是一个整数（cr 是 ci 的别名，ci 本身是一个顶层 const）
    auto d = &i; // d 是一个整型指针（整数的地址就是指向整数的指针）
    auto e = &ci; // e 是一个指向整数常量的指针（对常量对象取地址是一种底层 const）

    const auto f = ci; // ci 的推演类型是 int，f 是 const int

    auto &g = ci; // g 是一个整型常量引用，绑定到 ci
    // auto &h = 42; // 错误：不能为非常量引用绑定字面值
    const auto &j = 42; // 正确：可以为常量引用绑定字面值

    auto k = ci, &l = i; // k 是整数，l 是整型引用
    auto &m = ci, *p = &ci; // m 是对整型常量的引用，p 是指向整型常量的指针
    // 错误：i 的类型是 int 而 &ci 的类型是 const int
    // auto &n = i, *p2 = &ci;
}