#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main()
{
    string s("Hello World!!!");
    // 转换成大写形式
    for (auto &c : s) // 对于 s 中的每个字符（注意：c 是引用）
        c = toupper(c);
    cout << s << endl;
}