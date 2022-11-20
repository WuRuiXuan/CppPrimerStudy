#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string text("Hello World!!!");
    // 依次输出 text 的每一行直至遇到第一个空白行为止
    for (auto it = text.cbegin(); it != text.cend(); ++it)
        cout << *it <<endl;
}