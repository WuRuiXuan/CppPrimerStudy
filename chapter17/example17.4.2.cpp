#include <iostream>
#include <random>
#include <cmath>

using namespace std;

int main()
{
    default_random_engine e;
    // 0 到1（包含）的均匀分布
    uniform_real_distribution<double> u(0, 1);
    for (size_t i = 0; i < 10; ++i)
        cout << u(e) << " ";

    // 空 <> 表示使用默认结果类型（double）
    uniform_real_distribution<> u2(0, 1);

    /**
     * 生成一个正太分布的值的序列
     * 200个数，均值 4，标准差 1.5
     * 大约 99% 都在 0 到 8 之间（包含）
     */
    normal_distribution<> n(4, 1.5);    // 均值 4，标准差 1.5
    vector<unsigned> vals(9);           // 9 个元素均为 0
    for (size_t i = 0; i != 200; ++i) {
        unsigned v = lround(n(e));      // 舍入到最接近的整数
        if (v < vals.size())            // 如果结果在范围内
            ++vals[v];                  // 统计每个数出现了多少次
    }
    for (size_t j = 0; j != vals.size(); ++j)
        cout << j << ": " << string(vals[j], '*') << endl;

    // bernoulli_distribution 返回 true 概率默认值 0.5
    bernoulli_distribution b;
    string resp;
    do {
        cout << "bernoulli_distribution result: " << b(e) << endl;
    } while (cin >> resp);
    // bernoulli_distribution b(.55) 返回 true 概率 0.55
}