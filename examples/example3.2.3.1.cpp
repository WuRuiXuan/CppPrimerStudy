#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string s("Hello World!!!");
    // punct_cnt 的类型和 s.size 的返回类型一样
    decltype(s.size()) punct_cnt = 0;
    // 统计 s 中标点符号的数量
    for (auto c : s) // 对于 s 中的每个字符
        if (ispunct(c)) // 如果该字符是标点符号
            ++punct_cnt; // 将标点符号的计数值加 1
    cout << punct_cnt << " punctuation characters in " << s << endl;
}