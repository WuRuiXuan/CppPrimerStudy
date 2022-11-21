#include <iostream>

using namespace std;

class Base {
    friend class Pal;
    public:
        void pub_mem();
        size_t size() const { return n; }
    protected:
        int prot_mem;
        size_t n;
    private:
        char priv_mem;
};

class Sneaky : public Base {
    friend void clobber(Sneaky&);       // 能访问 Sneaky::prot_mem
    friend void clobber(Base&);         // 不能访问 Base::prot_mem
    int j;                              // j 默认是 private
};

class Pal {
    public:
        int f(Base b) { return b.prot_mem; }    // 正确：Pal 是 Base 的友元
        // int f2(Sneaky s) { return s.j; }     // 错误：Pal 不是 Sneaky 的友元
        // 对基类的访问权限由基类本身控制，即使对于派生类的基类部分也是如此
        int f3(Sneaky s) { return s.prot_mem; } // 正确：Pal 是 Base 的友元
};

class D2 : public Pal {
    public:
        // int mem(Base b) { return b.prot_mem; }  // 错误：友元关系不能继承
};

class Derived : private Base {
    // 使用了私有继承，继承的成员 size 和 n 在默认情况下是 Derived 的私有成员
    // 使用 using 声明语句来改变这些成员的可访问性
    // 派生类只能为它可以访问的成员提供 using 声明
    public:
        // 保持对象尺寸相关的成员的访问级别
        using Base::size;
    protected:
        using Base::n;
};

/**
 * struct 与 class 的主要区别：
 * struct   成员访问说明符、派生访问说明符默认为 public
 * class    成员访问说明符、派生访问说明符默认为 private
 */
struct D3 : Base { };       // 默认 public 继承
class D4 : Base { };        // 默认 private 继承

// 正确：clobber 能访问 Sneaky 对象的 private 和 protected 成员
void clobber(Sneaky &s) { s.j = s.prot_mem = 0; }
// 错误：clobber 不能访问 Base 的 protected 成员
// void clobber(Base &b) { b.prot_mem = 0; }

struct Pub_Derv : public Base {
    // 正确：派生类能访问 protected 成员
    int f() { return prot_mem; }
    // 错误：private 成员对于派生类来说是不可访问的
    // char g() { return priv_mem; }
};

struct Priv_Derv : private Base {
    // private 不影响派生类的访问权限
    int f1() const { return prot_mem; }
};

struct Derived_from_Public : public Pub_Derv {
    // 正确：Base::prot_mem 在 Pub_Derv 中仍然是 protected 的
    int use_base() { return prot_mem; }
};

struct Derived_from_Private : public Priv_Derv {
    // 错误：Base::prot_mem 在 Priv_Derv 中是 private 的
    // int use_base() { return prot_mem; }
};

int main()
{
    // 派生访问说明符
    Pub_Derv d1;            // 继承自 Base 的成员是 public 的
    Priv_Derv d2;           // 继承自 Base 的成员是 private 的
    d1.pub_mem();           // 正确：pub_mem 在派生类中是 public 的
    // d2.pub_mem();        // 错误：pub_mem 在派生类中是 private 的
}