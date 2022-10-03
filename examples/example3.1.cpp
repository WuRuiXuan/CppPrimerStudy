#include <iostream>
// using 声明，当我们使用名字 cin 时，从命名空间 std 中获取它
using std::cin;

int main()
{
    int i;
    cin >> i; // 正确：cin 和 std::cin 含义相同
    // cout << i; // 错误：没有对应的 using 声明，必须使用完整的名字
    std::cout << i; // 正确：显示地从 std 中使用 cout
    return 0;
}