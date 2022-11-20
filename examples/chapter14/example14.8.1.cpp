#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct absInt
{
    // 函数调用运算符
    int operator()(int val) const {
        return val < 0 ? -val : val;
    }
};

class PrintString {
    public:
        PrintString(ostream&, char);
        void operator()(const string&) const;
    private:
        ostream& os;            // 用于写入的目的流
        char sep;               // 用于将不同输出隔开的字符
};

inline PrintString::PrintString(ostream& o = cout, char c = ' '):
            os(o), sep(c) {}

inline void PrintString::operator() (const string& s) const { os << s << sep; }

class ShorterString {
    public:
        bool operator()(const string&, const string&) const;
};

inline bool ShorterString::operator() (const string& s1, const string& s2) const
{
    return s1.size() < s2.size();
}

class SizeComp {
    public:
        SizeComp(size_t n): sz(n) {}    // 该形参对应捕获的变量
        // 该调用运算符的返回类型、形参和函数体都与 lambda 一致
        bool operator()(const string& s) const;
    private:
        size_t sz;                      // 该数据成员对应通过值捕获的变量
};

inline bool SizeComp::operator()(const string& s) const
{
    return s.size() >= sz;
}

int main()
{
    int i = -42;
    absInt absObj;              // 含有函数调用运算符的对象
    int ui = absObj(i);         // 将 i 传递给 abdObj.operator()
    cout << ui << endl;
    cout << endl;

    vector<string> vs{"hello", "world"};
    for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));
    cout << endl;

    vector<string> words{"bbb", "cccc", "aa"};
    // stable_sort(words.begin(), words.end(), 
    //             [] (const string &a, const string &b)
    //                 { return a.size() < b.size(); });
    stable_sort(words.begin(), words.end(), ShorterString());
    for_each(words.begin(), words.end(), PrintString(cout, '\n'));
    cout << endl;

    // 获得第一个指向满足条件元素的迭代器
    size_t sz = 4;
    // auto wc = find_if(words.begin(), words.end(),
    //             [sz](const string &a)
    //                 { return a.size() >= sz; });
    auto wc = find_if(words.begin(), words.end(), SizeComp(sz));
    cout << *wc << endl;
}