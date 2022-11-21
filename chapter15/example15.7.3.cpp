#include <iostream>

using namespace std;

class Base { };

class D : public Base {
    // 默认情况下，基类地默认构造函数初始化对象的基类部分
    // 要想使用拷贝或移动构造函数，我们必须在构造函数初始值列表中显式地调用该构造函数
    D(const D& d): Base(d) { }          // 拷贝基类成员
    D(D&& d): Base(std::move(d)) { }    // 移动基类成员

    // 很可能是不正确的定义
    // D 的基类部分是使用 Base 的默认构造函数来初始化的
    // D 的成员部分则是从其他对象拷贝得来的
    D(const D& d) { }

    // Base::operator=(const Base&) 不会被自动调用
    D& operator=(const D& rhs)
    {
        Base::operator=(rhs);           // 为基类部分赋值
        // 为派生类的成员赋值，处理自赋值、释放已有资源等情况
        return *this;
    }

    // Base::~Base 被自动调用执行
    ~D() { /* 清除派生类成员的操作 */ }

    /**
     * 如果构造函数或析构函数调用了某个虚函数，则我们应该执行与构造函数或析构函数
     * 所属类型相对应的虚函数版本
     */
};
