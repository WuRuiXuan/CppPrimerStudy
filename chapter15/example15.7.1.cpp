#include <iostream>

using namespace std;

class Quote {
    public:
        // 虚析构函数
        virtual ~Quote() = default;
        // 编译器将不会为这个类合成移动操作，而且在它的派生类中也没有合成的移动操作
        // 当我们移动 Quote 对象时，实际使用的是合成的拷贝操作
        // 解决办法：显式地定义移动操作和拷贝操作
        Quote() = default;
        Quote(const Quote&) = default;
        Quote(Quote&&) = default;
        Quote& operator=(const Quote&) = default;
        Quote& operator=(Quote&&) = default;
};

class Bulk_quote : public Quote {

};

class B {
    public:
        B();
        B(const B&) = delete;
};

class D : public B {

};

int main()
{
    Quote *itemP = new Quote;
    delete itemP;               // 调用 Quote 的析构函数
    itemP = new Bulk_quote;
    delete itemP;               // 调用 Bulk_quote 的析构函数

    /**
     * 1. 如果基类中的默认构造函数、拷贝构造函数、拷贝赋值运算符或析构函数是 delete 的或者
     *    不可访问的，则派生类中对应的成员将是 delete 的
     * 2. 如果基类中的析构函数是 delete 的或者不可访问的，则派生类中的合成的默认构造函数、
     *    拷贝构造函数、移动构造函数都是 delete 的
     */
    D d;                        // 正确：使用 B 的默认构造函数
    // D d2(d);                 // 错误：D 的合成拷贝构造函数是 delete 的
    // D d3(std::move(d));      // 错误：隐式地使用 D 的合成拷贝构造函数
}
