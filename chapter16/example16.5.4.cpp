#include <iostream>

using namespace std;

template <typename T> struct Foo {
    Foo(const T &t = T()): mem(t) { }
    void Bar() { }
    T mem;
};

// 特例化 Foo<int> 的成员 Bar
template <>
void Foo<int>::Bar()
{
    // 进行应用于 int 的特例化处理
}

int main()
{
    Foo<string> fs;         
    fs.Bar();               // 使用原始版本 Foo<string>::Bar()

    Foo<int> fi;
    fi.Bar();               // 使用特例化版本 Foo<int>::Bar()
}