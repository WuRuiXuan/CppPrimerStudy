#include <iostream>

using std::string;
using std::endl;
using std::cout;

int main()
{
    string s("some string");

    // if (!s.empty()) // 确保 s[0] 的位置确实有字符
    //     s[0] = toupper(s[0]); // 为 s 的第一个字符赋一个新值

    // 依次处理 s 中的字符直至我们处理完全部字符或者遇到一个空白
    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
            s[index] = toupper(s[index]); // 将当前字符改成大写形式
    cout << s << endl;
}