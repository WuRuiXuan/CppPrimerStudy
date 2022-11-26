#include <iostream>
#include <string>

using namespace std;

struct Base1 {
    Base1() = default;
    Base1(const string&);
    Base1(shared_ptr<int>);
};

struct Base2 {
    Base2() = default;
    Base2(const string&);
    Base2(int);
};

// 错误：D1 试图从两个基类中都继承 D1::D1(const string&)
struct D1: public Base1, public Base2 {
    using Base1::Base1;         // 从 Base1 继承构造函数
    using Base2::Base2;         // 从 Base2 继承构造函数
};

struct D2: public Base1, public Base2 {
    using Base1::Base1;
    using Base2::Base2;
    // D2 必须自定义一个接受 string 的构造函数
    D2(const string &s): Base1(s), Base2(s) { }
    D2() = default;             // 一旦 D2 定义了它自己的构造函数，则必须出现
};
