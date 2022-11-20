#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main()
{
    string s("some string");

    // if (s.begin() != s.end()) { // 确保 s 非空
    //     auto it = s.begin(); // it 表示 s 的第一个字符
    //     *it = toupper(*it); // 将当前字符改写成大写形式
    // }

    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
        *it = toupper(*it); // 将当前字符改成大写形式

    cout << s << endl;
}