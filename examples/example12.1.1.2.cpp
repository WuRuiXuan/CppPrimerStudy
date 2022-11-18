#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class StrBlob {
    public:
        typedef vector<string>::size_type size_type;
        StrBlob(): data(make_shared<vector<string>>()) {};
        StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {};
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        // 添加和删除元素
        void push_back(const string &t) { data->push_back(t); }
        void pop_back();
        // 元素访问
        string& front();
        string& back();
        const string& front() const;
        const string& back() const;
    private:
        shared_ptr<vector<string>> data;
        // 如果 data[i] 不合法，抛出一个异常
        void check(size_type i, const string &msg) const;
};

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

string& StrBlob::front()
{
    // 如果 vector 为空，check 会抛出一个异常
    check(0, "font on empty StrBlob");
    return data->front();
}

const string& StrBlob::front() const
{
    check(0, "font on empty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

const string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

int main()
{
    // const 对象中 data 数据成员所指 vector 仍然可以改变
	const StrBlob s1({"aaa", "bbb", "ccc"});
	cout << s1.front() << endl;
	cout << s1.back() << endl;
}