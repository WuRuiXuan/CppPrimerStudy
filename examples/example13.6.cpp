#include <string>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

class Foo {
    public:
        Foo() = default;
        Foo(const Foo&); // 拷贝构造函数
        Foo& operator=(const Foo&) &; // 引用限定符：只能向可修改的左值赋值
        Foo sorted() &&;            // 可用于可改变的右值
        Foo sorted() const &;       // 可用于任何类型的 Foo
        // 其他成员定义，但 Foo 未定义移动构造函数
    private:
        vector<int> data;
};

Foo x;
Foo y(x);               // 拷贝构造函数；x 是一个左值
Foo z(std::move(x));    // 拷贝构造函数，因为未定义移动构造函数

inline Foo &Foo::operator=(const Foo &rhs) &
{
    // 执行将 rhs 赋予本对象所需的工作
    return *this;
}

// 本对象为右值，因此可以原址排序
inline Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    return *this;
}

// 本对象是 const 或是一个左值，哪种情况我们都不能对其进行原址排序
inline Foo Foo::sorted() const & {
    Foo ret(*this);                         // 拷贝一个副本
    sort(ret.data.begin(), ret.data.end()); // 排序副本
    return ret;                             // 返回副本
}

class HasPtr {
    public:
        // 移动构造函数
        HasPtr(HasPtr&&) noexcept;
        // 赋值运算符既是移动赋值运算符，也是拷贝赋值运算符
        HasPtr& operator=(HasPtr);
    private:
        string *ps;
        int i;
};

inline HasPtr::HasPtr(HasPtr&& p) noexcept : ps(p.ps), i(p.i) { p.ps = 0; }

inline HasPtr& HasPtr::operator=(HasPtr rhs) { swap(*this, rhs); return *this; }