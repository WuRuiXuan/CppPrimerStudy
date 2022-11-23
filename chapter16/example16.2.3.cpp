#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 尾置返回允许我们在参数列表之后声明返回类型
template <typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
    // 处理序列
    return *beg; // 返回序列中一个元素的引用
}

/**
 * remove_reference
 * 
 * 如果 decltype(*beg) 是一个指针或引用，比如 X& 或 X&&
 * 则 remove_reference<decltype(*beg)>::type 类型为 X
 * 
 * 如果 decltype(*beg) 不是一个指针或引用
 * 则 remove_reference<decltype(*beg)>::type 类型为 decltype(*beg)
 */
template <typename It>
auto fcn2(It beg, It end) -> typename remove_reference<decltype(*beg)>::type
{
    return *beg;
}