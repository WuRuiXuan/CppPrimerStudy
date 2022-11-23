#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename T> T fobj(T, T); // 实参被拷贝
template <typename T> T fref(const T&, const T&); // 引用

template <typename T> int compare(const T& v1, const T& v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

// 实参类型可以不同，但必须兼容
template <typename A, typename B>
int flexibleCompare(const A& v1, const B& v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int main()
{
    string s1("a value");
    const string s2("another value");

    fobj(s1, s2);   // 调用 fobj(string, string); const 被忽略
    fref(s1, s2);   // 调用 fref(const string&, const string&); 将 s1 转换为 const

    int a[10], b[42];
    fobj(a, b);     // 数组转换为指针，调用 f(int*, int*)
    // fref(a, b);  // 错误：数组类型不匹配
    /**
     * 如果形参是一个引用，则数组不会转换为指针
     */

    long lng;
    // compare(lng, 1024); // 错误：不能实例化 compare(long, int)
    flexibleCompare(lng, 1024); // 正确：调用 flexibleCompare(long, int)

    /**
     * 如果函数参数类型不是模板参数，则对实参进行正常的类型转换
     * 如果函数参数类型是模板参数，则能够自动类型转换的只有 const 转换和数组或函数到指针的转换
     */
}