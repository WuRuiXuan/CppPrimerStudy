#include <iostream>

using namespace std;

/**
 * 良好的设计
 * 
 * 编译器无法推断 T1，因为它未出现在函数参数列表中
 * 必须指定 T1，T2、T3 可以忽略
 */
template <typename T1, typename T2, typename T3>
T1 sum(T2, T3);

/**
 * 糟糕的设计
 * 
 * 编译器无法推断 T3
 * 必须指定 T3，T3 出现在最右边，因此 T1、T2 也必须指定
 */
template <typename T1, typename T2, typename T3>
T3 alternative_sum(T2, T1);

int main()
{
    long lng;
    int i = 1024;
    // T1 是显式指定的（忽略了 T2、T3），T2 和 T3 是从函数实参类型推断而来的
    auto val2 = sum<long long>(i, lng); // long long sum(int, long)

    // 错误：不能推断前几个模板参数
    // auto val3 = alternative_sum<long long>(i, lng);

    // T3 出现在最右边，因此 T1、T2 也必须指定，不能忽略
    auto val3 = alternative_sum<long long, int, long>(i, lng);
}