#include <iostream>

// 第一个版本，可以比较任意两个类型
template <typename T> int compare(const T&, const T&);

// 第二个版本，处理字符串字面常量
template<size_t N, size_t M>
int compare(const char (&)[N], const char (&)[M]);

/**
 * 第二个版本的特例化版本
 * 
 * <> 为原模板的所有模板参数提供实参
 * const char* const &   指向 const char 的 const 指针的引用
 * 一个特例化版本本质上是一个实例，而非函数名的一个重载版本
 * 特例化版本丢失：原模板的一个实例具有相同的模板实参集合
 */
template <>
int compare(const char* const &p1, const char* const &p2)
{
    return strcmp(p1, p2);
}

int main()
{
    const char *p1 = "hi", *p2 = "mom";
    compare(p1, p2);        // 调用第一个版本（第二个版本无法将指针转换为数组的引用）
    compare("hi", "mom");   // 调用第二个版本
}