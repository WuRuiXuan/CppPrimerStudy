#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    // 以 10 分为一个分数段统计成绩的数量：0~9, 10~19, ..., 90~99, 100
    unsigned scores[11] = {}; // 11 个分数段，全部初始化为 0
    // unsigned scores[11];
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100)
            ++scores[grade/10]; // 将当前分数段的计数值加 1
    }
    for (auto i : scores) // 对于 scores 中的每个计数值
        cout << i << " "; // 输出当前的计数值
    cout << endl;
}