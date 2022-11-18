#include <iostream>
#include <string>

using namespace std;

class HasPtr {
    public:
        HasPtr(const string &);
        ~HasPtr();
        string* getPs();
    private:
        string *ps;
        int i;
};

HasPtr f(HasPtr);

inline HasPtr::HasPtr(const string &s = string()): ps(new string(s)), i(0) {}

inline HasPtr::~HasPtr() 
{
    cout << "delete ps" << endl;
    delete ps; 
}

inline string* HasPtr::getPs() { return ps; }

HasPtr f(HasPtr hp)     // HasPtr 是传值参数，所以将被拷贝
{
    HasPtr ret = hp;    // 拷贝给定的 HashPtr
    // 处理 ret
    return ret;         // ret 和 hp 被销毁
}

int main()
{
    HasPtr p("some values");
    f(p);           // 当 f 结束时，p.ps 指向的内存被释放
    HasPtr q(p);    // 现在 p 和 q 都指向无效内存
}