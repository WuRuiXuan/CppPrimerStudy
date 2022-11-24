#include <iostream>
#include <string>

using namespace std;

/**
 * 可变参数模板
 * Args 是一个模板参数包；rest 是一个函数参数包
 * Args 表示零个或多个模板类型参数
 * rest 表示零个或多个函数参数
 */
template <typename T, typename... Args>
void foo(const T& t, const Args& ... rest)
{
    cout << sizeof...(Args) << endl;    // 类型参数的数目
    cout << sizeof...(rest) << endl;    // 函数参数的数目
}

int main()
{
    int i = 0; double d = 3.14; string s = "how now brown cow";
    foo(i, s, 42, d);       // 包中有3个参数
    foo(s, 42, "hi");       // 包中有2个参数
    foo(d, s);              // 包中有1个参数
    foo("hi");              // 空包
}