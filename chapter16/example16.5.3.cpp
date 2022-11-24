#include <memory>

// 原始的、最通用的版本
template <class T> struct remove_reference
{
    typedef T type;
};

// 部分特例化版本，将用于左值引用和右值引用
template <class T> struct remove_reference<T&> // 左值引用
{
    typedef T type;
};

template <class T> struct remove_reference<T&&> // 右值引用
{
    typedef T type;
};

int main()
{
    int i;
    // 使用原始模板
    remove_reference<decltype(42)>::type a;
    // 使用左值版本
    remove_reference<decltype(i)>::type b;
    // 使用右值版本
    remove_reference<decltype(std::move(i))>::type c;
}