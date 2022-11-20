#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

// 对于 StrBlob 中的友元声明来说，此前置声明是必要的
class StrBlobPtr;
class StrBlob {
    friend class StrBlobPtr;
    public:
        StrBlob();
        StrBlob(initializer_list<string>);
        // 返回指向首元素和尾后元素的 StrBlobPtr
        StrBlobPtr begin();
        StrBlobPtr end();
    private:
        shared_ptr<vector<string>> data;
};

// 对于访问一个不存在元素的尝试，StrBlobPtr 抛出一个异常
class StrBlobPtr {
    public:
        StrBlobPtr();
        StrBlobPtr(StrBlob &, size_t);
        string& deref() const;
        StrBlobPtr& incr(); // 前缀递增
    private:
        // 若检查成功，check 返回一个指向 vector 的 shared_ptr
        shared_ptr<vector<string>> check(size_t, const string&) const;
        // 保存一个 weak_ptr，意味着底层 vector 可能会被销毁
        weak_ptr<vector<string>> wptr;
        size_t curr; // 在数组中的当前位置
};

inline StrBlobPtr::StrBlobPtr(): curr(0) {}

inline StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz = 0): 
                    wptr(a.data), curr(sz) {}

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock(); // vector 还存在吗？
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret; // 否则，返回指向 vector 的 shared_ptr
}

inline string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr]; // (*p) 是对象所指向的 vector
}

// 前缀递增：返回递增后的对象的引用
inline StrBlobPtr& StrBlobPtr::incr()
{
    // 如果 curr 已经指向容器的尾后位置，就不能递增它
    check(curr, "increment past end of StrBlobPtr");
    ++curr; // 推进当前位置
    return *this;
}

inline StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}

inline StrBlob::StrBlob(initializer_list<string> il): 
                data(make_shared<vector<string>>(il)) {}

inline StrBlobPtr StrBlob::begin() 
{ 
    return StrBlobPtr(*this); 
}

inline StrBlobPtr StrBlob::end() 
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

int main()
{
    StrBlob str_blob({"a", "b", "c"});
    StrBlobPtr ptr = str_blob.begin();
    for (int i = 0; i < 3; ++i) {
        cout << ptr.deref() << " ";
        ptr.incr();
    }
    cout << endl;
}