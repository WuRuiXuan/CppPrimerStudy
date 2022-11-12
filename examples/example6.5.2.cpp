#include <iostream>

using namespace std;

int main()
{
    int arr[scale(2)]; // 正确：scale(2)是常量表达式
    int i = 2; // i 不是常量表达式
    // int a2[scale(i)]; // 错误：scale(i)不是常量表达式
}

constexpr size_t scale(size_t cnt)
{
    return new_sz() * cnt;
}

constexpr int new_sz() {
    return 42;
}