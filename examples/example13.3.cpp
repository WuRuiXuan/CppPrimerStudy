#include <iostream>
#include <string>

using namespace std;

class HasPtr {
    friend void swap(HasPtr&, HasPtr&);
    public:
        HasPtr(const string&);
        HasPtr(const HasPtr&);
        HasPtr& operator= (const HasPtr&);
        HasPtr& operator= (const string&);
        HasPtr& operator= (HasPtr);
        string& operator* ();
        ~HasPtr();
    private:
        string *ps;
        int i;
};

HasPtr::HasPtr(const string& s): ps(new string(s)), i(0) {}

HasPtr::HasPtr(const HasPtr& p): ps(new string(*p.ps)), i(p.i) {}

inline HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    auto newps = new string(*rhs.ps);
    delete ps;
    ps = newps;
    i = rhs.i;
    return *this;
}

inline HasPtr& HasPtr::operator=(const string& str)
{
    auto newps = new string(str);
    delete ps;
    ps = newps;
    return *this;
}

// 注意 rhs 是按值传递的，意味着 HasPtr 的拷贝构造函数
// 将右侧运算对象中的 string 拷贝到 rhs
inline HasPtr& HasPtr::operator=(HasPtr rhs)
{
    // 交换左侧运算对象和局部变量 rhs 的内容
    swap(*this, rhs);       // rhs 现在指向本对象曾经使用的内存
    return *this;           // rhs 被销毁，从而 delete 了 rhs 中的指针
}

inline string& HasPtr::operator*() { return *ps; }

inline HasPtr::~HasPtr() { delete ps; }

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);       // 交换指针，而不是 string 数据
    swap(lhs.i, rhs.i);         // 交换 int 成员
}