#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template <typename T> int compare(const T& v1, const T& v2)
{
    // if (v1 < v2) return -1;
    // if (v2 < v1) return 1;

    // 即使用于指针也正确的 compare 版本
    if (less<T>()(v1, v2)) return -1;
    if (less<T>()(v2, v1)) return 1;
    return 0;
}

// 错误：U 之前必须加上 class 或 typename
// template <typename T, U> T calc(const T&, const U&);

// 正确：在模板参数列表中，typename 和 class 没有什么不同
template <typename T, class U> T calc(const T&, const U&);

int main()
{
    cout << compare(1, 0) << endl; // T 为 int

    vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};
    cout << compare(vec1, vec2) << endl; // T 为 vector<int>
}

// 非类型模板参数（表示一个值而非一个类型）
template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}

// 正确：inline 说明符跟在模板参数列表之后
template <typename T> inline T min(const T&, const T&);
// 错误：inline 说明符的位置不正确
// inline template <typename T> T min(const T&, const T&);

/**
 * 函数模板的声明和定义一般都放在头文件中
 */