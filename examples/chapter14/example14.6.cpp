#include <iostream>
#include <vector>
#include <string>

using namespace std;

class StrBlobPtr {
    public:
        // 前置运算符
        StrBlobPtr& operator++();
        StrBlobPtr& operator--();
        // 后置运算符
        StrBlobPtr operator++(int);
        StrBlobPtr operator--(int);
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

// 前置版本：返回递增/递减对象的引用
StrBlobPtr& StrBlobPtr::operator++()
{
    // 如果 curr 已经指向了容器的尾后位置，则无法递增它
    check(curr, "increment past end of StrBlobPtr");
    ++curr;                     // 将 curr 在当前状态下向前移动一个元素
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
    // 如果 curr 是0，则继续递减它将产生一个无效下标
    --curr;                     // 将 curr 在当前状态下向后移动一个元素
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

// 后置版本：递增/递减对象的值但是返回原值
StrBlobPtr StrBlobPtr::operator++(int)
{
    // 此处无须检查有效性，调用前置递增运算时才需要检查
    StrBlobPtr ret = *this;     // 记录当前的值
    ++*this;                    // 向前移动一个元素，前置++需要检查递增的有效性
    return ret;                 // 返回之前记录的状态
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    // 此处无须检查有效性，调用前置递减运算时才需要检查
    StrBlobPtr ret = *this;     // 记录当前的值
    --*this;                    // 向后移动一个元素，前置--需要检查递减的有效性
    return ret;                 // 返回之前记录的状态
}

int main()
{
    StrBlobPtr p;
    p.operator++(0);            // 调用后置版本的 operator++
    p.operator++();             // 调用前置版本的 operator++
}