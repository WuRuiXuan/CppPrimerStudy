#include <iostream>
#include <vector>
#include <string>

using namespace std;

class StrBlobPtr {
    public:
        // 成员访问运算符
        string& operator*() const;
        string* operator->() const;
    private:
        shared_ptr<vector<string>> check(size_t, const string&) const;
        weak_ptr<vector<string>> wptr;
        size_t curr;        
};

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock(); // vector 还存在吗？
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret; // 否则，返回指向 vector 的 shared_ptr
}

inline string& StrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];          // (*p) 是对象所指的 vector
}

inline string* StrBlobPtr::operator->() const
{
    // 将实际工作委托给解引用运算符
    return & this->operator*();
}

int main()
{
    StrBlobPtr p;               
    *p = "okay";                    // 给 vector 的首元素赋值
    cout << p->size() << endl;      // 打印 4，这是 vector 首元素的大小
    cout << (*p).size() << endl;    // 等价于 p->size()
}