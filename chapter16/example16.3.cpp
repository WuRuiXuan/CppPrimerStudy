#include <iostream>
#include <sstream>

using namespace std;

// 打印任何我们不能处理的类型
template <typename T> string debug_rep(const T& t)
{
    ostringstream ret;
    ret << t;
    return ret.str();
}

// 打印指针的值，后跟指针指向的对象
template <typename T> string debug_rep(T* p)
{
    ostringstream ret;
    ret << "pointer: " << p;            // 打印指针本身的值
    if (p)
        ret << " " << debug_rep(*p);    // 打印 p 指向的值
    else
        ret << " null pointer";         // 或指出 p 为空
    return ret.str();                   // 返回 ret 绑定的 string 的一个副本
}

// 打印双引号包围的 string
string debug_rep(const string& s)
{
    return '"' + s + '"';
}

// 将 C 风格字符串指针和字符串字面量按 string 处理
string debug_rep(char* p)
{
    return debug_rep(string(p));
}

string debug_rep(const char* p)
{
    return debug_rep(string(p));
}

int main()
{
    string s("hi");
    cout << debug_rep(s) << endl;       // debug_rep(const T&) T 为 string*
    cout << debug_rep(&s) << endl;      // debug_rep(T*) T 为 string
    // 多个重载模板提供同样好的匹配，编译器选择最特例化的版本
    const string* sp = &s;
    cout << debug_rep(sp) << endl;      // debug_rep(const T&) T 为 string*

    // 一个非函数模板和一个函数模板提供同样好的匹配，编译器选择非模板版本
    cout << debug_rep(s) << endl;       // debug_rep(const string&)

    /**
     * debug_rep(const T&)      T 为 char[10]
     * debug_rep(T*)            T 为 const char 发生转换 char[] -> char* 精确匹配
     * debug_rep(const string&) 发生转换 const string -> const char*
     */
    cout << debug_rep("hi world!") << endl;
}