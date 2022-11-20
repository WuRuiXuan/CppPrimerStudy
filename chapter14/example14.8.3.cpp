#include <iostream>
#include <map>
#include <functional>
#include "../resources/Sales_data.h"

using namespace std;

// 普通函数
int add(int i, int j) { return i + j; }
// lambda，其产生一个未命名的函数对象类
auto mod = [](int i, int j) { return i % j; };
// 函数对象类
struct Divide {
    int operator()(int denominator, int divisor)
    {
        return denominator / divisor;
    }
};

// 有重载函数则使用函数指针或 lambda 来消除二义性
// Sales_data add(const Sales_data&, const Sales_data&);

int main()
{
    // 构建函数表，其中函数接受两个 int、返回一个 int
    map<string, int(*)(int, int)> binops;
    // 正确：add 是一个指向正确类型函数的指针
    binops.insert({"+", add});
    // binops.insert({"%", mod});              // 错误：mod 不是一个函数指针

    function<int(int, int)> f1 = add;       // 函数指针
    function<int(int, int)> f2 = Divide();  // 函数对象类的对象
    function<int(int, int)> f3 = [](int i, int j) { return i * j; }; // lambda

    cout << f1(4, 2) << endl;           // 打印 6
    cout << f2(4, 2) << endl;           // 打印 2
    cout << f3(4, 2) << endl;           // 打印 8

    // 其中的元素可以是函数指针、函数对象或者 lambda
    map<string, function<int(int, int)>> binops2 = {
        {"+", add},                                     // 函数指针
        {"-", minus<int>()},                            // 标准库函数对象
        {"/", Divide()},                                // 用户定义的函数对象
        {"*", [](int i, int j) { return i * j; }},      // 未命名的 lambda
        {"%", mod}                                      // 命名了的 lambda 对象
    };

    binops2["+"](10, 5);    // 调用 add(10, 5)
    binops2["-"](10, 5);    // 使用 minus<int> 对象的调用运算符
    binops2["/"](10, 5);    // 使用 Divide 对象的调用运算符
    binops2["*"](10, 5);    // 调用 lambda 函数对象
    binops2["%"](10, 5);    // 调用 lambda 函数对象
}