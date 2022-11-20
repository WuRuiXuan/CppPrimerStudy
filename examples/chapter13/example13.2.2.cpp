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
        size_t *use;    // 用来记录有多少个对象共享 *ps 的成员
};

// 构造函数分配新的 string 和新的计数器，将计数器置为1
HasPtr::HasPtr(const string& s): 
            ps(new string(s)), i(0), use(new size_t(1)) {}

// 指针行为的拷贝构造函数
// 拷贝构造函数拷贝所有三个数据成员，并递增计数器
HasPtr::HasPtr(const HasPtr& p): ps(p.ps), i(p.i), use(p.use) { ++*use; }

// 指针行为的拷贝赋值运算符
inline HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    ++*rhs.use;         // 递增右侧运算对象的引用计数
    if (--*use == 0) {  // 然后递减本对象的引用计数
        delete ps;      // 如果没有其他用户
        delete use;     // 释放本对象分配的成员
    }
    ps = rhs.ps;        // 将数据从 rhs 拷贝到本对象
    i = rhs.i;
    use = rhs.use;
    return *this;       // 返回本对象
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

inline HasPtr::~HasPtr()
{
    if (--*use == 0) {      // 如果引用计数变为0
        delete ps;          // 释放 string 内存
        delete use;         // 释放计数器内存
    }
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