#include <iostream>

int main()
{
    int i = 42;
    const int &r1 = i; // 允许将 const int& 绑定到一个普通 int 对象上
    const int &r2 = 42; // 正确：r1 是一个常量引用
    const int &r3 = r1 * 2; // 正确：r3 是一个常量引用
    // int &r4 = r1 * 2; // 错误：r4 是一个普通的非常量引用
    int j = r1 * 2;
}