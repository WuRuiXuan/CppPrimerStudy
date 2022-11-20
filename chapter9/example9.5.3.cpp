#include <iostream>
#include <string>

using namespace std;

int main()
{
    string numbers("0123456789"), name("r2d2");
    string::size_type pos = 0; // 从什么位置开始查找
    // 每步循环查找 name 中下一数
    while ((pos = name.find_first_of(numbers, pos)) != string::npos) {
        cout << "found number at index: " << pos
            << " element is " << name[pos] << endl;
        ++pos; // 移动到下一个字符
    }
}