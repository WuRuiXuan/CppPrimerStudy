#include <iostream>
#include <string>

using namespace std;

string::size_type find_char(const string &, char, string::size_type &);

int main()
{
    string s = "hello";
    decltype(s.size()) ctr;
    auto index = find_char(s, 'o', ctr);
    cout << "index: " << index << " occurs: " << ctr << endl;
}

// 返回 s 中 c 第一次出现的位置索引
// 引用形参 occurs 负责统计 c 出现的总次数
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size(); // 第一次出现的位置（如果有的话）
    occurs = 0; // 设置表示出现次数的形参的值
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i; // 记录 c 第一次出现的位置
            ++occurs; // 将出现的次数加 1
        }
    }
    return ret; // 出现次数通过 occurs 隐式地返回
}