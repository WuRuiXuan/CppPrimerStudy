#include <iostream>
#include <string>

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

HasPtr::HasPtr(const string& str): ps(new string(str)), i(0) {}

// 值行为的拷贝构造函数
HasPtr::HasPtr(const HasPtr& htr): ps(new string(*htr.ps)), i(0) {}

// 值行为的拷贝赋值运算符
inline HasPtr& HasPtr::operator=(const HasPtr& htr)
{
    auto newps = new string(*htr.ps);
    delete ps;
    ps = newps;
    i = htr.i;
    return *this;
}

// 值行为的拷贝赋值运算符
inline HasPtr& HasPtr::operator=(const string& str)
{
    auto newps = new string(str);
    delete ps;
    ps = newps;
    return *this;
}

inline string& HasPtr::operator*()
{
    return *ps;
}

inline HasPtr::~HasPtr()
{
    delete ps;
}

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