#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<unsigned> scores(11, 0); // 11 个分数段，全都初始化为 0
    unsigned grade;
    while (cin >> grade) { // 读取成绩
        if (grade <= 100) // 只处理有效的成绩
            ++scores[grade/10]; // 将对应分数段的计数值加 1
            /*
                等价于
                auto ind = grade/10; // 得到分数段索引
                scores[ind] = scores[ind] + 1; // 将计数值加 1
            */
    }
}