#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
    size_t n = 10;
    string *const p = new string[n]; // 构造 n 个空 string
    string s;
    string *q = p;                   // q 指向第一个 string
    while (cin >> s && q != p + n)
        *q++ = s;                    // 赋予 *q 一个新值
    const size_t size = q - p;       // 记住我们读取了多少个 string
    // 使用数组
    delete [] p; // p 指向一个数组；记得用 delete [] 来释放
    for (int i = 0; i <= size; ++i)
        cout << *q-- << " ";
    cout << endl;
}