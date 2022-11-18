#include <iostream>
#include <string>
#include <memory>

using namespace std;

class HasPtr {
    public:
        HasPtr(const string&);
        // 拷贝构造函数
        HasPtr(const HasPtr&);
        // 拷贝赋值运算符
        HasPtr& operator= (const HasPtr&);
        HasPtr& operator= (const string&);
        // 解引用运算符
        string& operator* ();
        // 析构函数
        ~HasPtr();
    private:
        string *ps;
        int i;
};

HasPtr::HasPtr(const string& str): 
            ps(new string(str)), i(0) {}

// 指针行为的拷贝构造函数
HasPtr::HasPtr(const HasPtr& htr): ps(htr.ps), i(0) {}

// 指针行为的拷贝赋值运算符
inline HasPtr& HasPtr::operator=(const HasPtr& htr)
{
    ps = htr.ps;
    i = htr.i;
    return *this;
}

// 指针行为的拷贝赋值运算符
inline HasPtr& HasPtr::operator=(const string& str)
{
    *ps = str;
    return *this;
}

inline string& HasPtr::operator*()
{
    return *ps;
}

inline HasPtr::~HasPtr() { delete ps; }

int main()
{
	HasPtr h1("Hello world"); // 构造函数
	HasPtr h2(h1); // 拷贝构造函数
	HasPtr h3 = h1; // 赋值运算符
 
	cout << *h1 << endl;
	cout << *h2 << endl;
	cout << *h3 << endl;
    cout << endl;
 
	h2 = "Nihao";
	h3 = "Shijie";
 
	cout << *h1 << endl;
	cout << *h2 << endl;
	cout << *h3 << endl;
 
	return 0;
}