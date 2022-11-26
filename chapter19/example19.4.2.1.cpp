#include <iostream>
#include <string>

using namespace std;

class Screen {
    friend void test();
    public:
        typedef string::size_type pos;
        char get_cursor() const { return contents[cursor]; }
        char get() const;
        char get(pos ht, pos wd) const;
        // data 是一个静态成员，返回一个成员指针
        static const string Screen::*data()
        { return &Screen::contents; }
    private:
        string contents;
        pos cursor;
        pos height, width;
};

void test()
{
    /**
     * 数据成员指针
     * pdata 可以指向一个常量（非常量）Screen 对象的 string 成员
     * 只可以读不可以写
     */
    const string Screen::*pdata = &Screen::contents;
    auto pdata2 = &Screen::contents;

    Screen myScreen, *pScreen = &myScreen;
    // .* 解引用 pdata 以获得 myScreen 对象的 contents 成员
    auto s1 = myScreen.*pdata;
    // ->* 解引用 pdata 以获得 pScreen 所指对象的 contents 成员
    auto s2 = pScreen->*pdata;

    // data() 返回一个指向 Screen 类的 contents 成员的指针
    const string Screen::*pdata3 = Screen::data();

    /**
     * 函数成员指针
     * 要指定目标函数的返回类型和形参列表
     */
    auto pmf = &Screen::get_cursor;

    char (Screen::*pmf2)(Screen::pos, Screen::pos) const;
    pmf2 = &Screen::get;
    // 错误：非成员函数 p 不能使用 const 限定符
    // char Screen::*p(Screen::pos, Screen::pos) const;

    // 通过 pScreen 所指的对象调用 pmf 所指的函数
    char c1 = (pScreen->*pmf)();
    // 通过 myScreen 对象将实参 0, 0 传给含有两个形参的 get 函数
    char c2 = (myScreen.*pmf2)(0, 0);

    // 使用类型别名，让含有成员指针的代码更易读
    using Action = char (Screen::*)(Screen::pos, Screen::pos) const;
    Action get = &Screen::get;          // get 指向 Screen 的 get 成员
    // action 接受一个 Screen 的引用，和一个指向 Screen 成员函数的指针
    Screen& action(Screen&, Action = &Screen::get);

    action(myScreen);                   // 使用默认实参
    action(myScreen, get);              // 使用之前定义的变量 get
    action(myScreen, &Screen::get);     // 显式地传入地址
}