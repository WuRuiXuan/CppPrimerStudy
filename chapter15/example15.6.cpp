#include <iostream>

using namespace std;

struct Base {
    Base(): mem(0) {}
    int memfcn();
    protected:
        int mem;
};

struct Derived : Base
{
    Derived(int i): mem(i) {}
    int get_mem() { return mem; }
    int get_base_mem() { return Base::mem; }
    int memfcn(int);    // 隐藏基类中的 memfcn
    protected:
        int mem;        // 隐藏基类中的 mem
};

int main()
{
    Derived d(42);
    cout << d.get_mem() << endl; // 42
    cout << d.get_base_mem() << endl; // 0

    // 名字查找先于类型检查
    Base b;
    d.memfcn(10);       // 调用 Derived::memfcn
    // d.memfcn();      // 错误：基类中的 memfcn 被隐藏了
    d.Base::memfcn();   // 正确：调用 Base::memfcn
}