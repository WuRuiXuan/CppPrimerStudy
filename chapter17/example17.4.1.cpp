#include <iostream>
#include <random>
#include <vector>
#include <ctime>

using namespace std;

// 生成随机整数 vector 的错误方法，每次调用生成的随机数都相同
vector<unsigned> bad_randVec()
{
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0, 9);
    vector<unsigned> ret;
    for (size_t i = 0; i < 100; ++i)
        ret.push_back(u(e));
    return ret;
}

// 生成随机整数 vector 的正确方法
vector<unsigned> good_randVec()
{
    /**
     * 定义为 static 的，这样引擎和分布对象可以保持状态
     * 第一次调用会使用 u(e) 生成的序列中的前100个随机数
     * 第二次调用会获得接下来100个，依此类推，从而每次调用都生成新的数
     */
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(0, 9);
    vector<unsigned> ret;
    for (size_t i = 0; i < 100; ++i)
        ret.push_back(u(e));
    return ret;
}

int main()
{
    default_random_engine e; // 生成随机无符号数
    for (size_t i = 0; i < 10; ++i)
        // e() “调用”对象来生成下一个随机数
        cout << e() << " ";
    cout << endl;

    // 生成0到9之间（包含）均匀分布的随机数
    uniform_int_distribution<unsigned> u(0, 9);
    for (size_t i = 0; i < 10; ++i)
        cout << u(e) << " ";
    cout << endl;

    cout << "min: " << e.min() << " max: " << e.max() << endl;
    cout << endl;

    vector<unsigned> v1(bad_randVec());
    vector<unsigned> v2(bad_randVec());
    cout << ((v1 == v2) ? "equal" : "not equal") << endl;

    vector<unsigned> v3(good_randVec());
    vector<unsigned> v4(good_randVec());
    cout << ((v3 == v4) ? "equal" : "not equal") << endl;

    default_random_engine e1;               // 使用默认种子
    default_random_engine e2(2147483646);   // 使用给定的种子值
    // e3 和 e4 将生成相同的序列，因为它们使用了相同的种子
    default_random_engine e3;
    e3.seed(32767);
    default_random_engine e4(32767);
    for (size_t i = 0; i != 100; ++i) {
        if (e1() == e2())
            cout << "unseeded match at iteration: " << i << endl;
        if (e3() != e4())
            cout << "seeded differs at iteration: " << i << endl;
    }

    // 使用系统时间作为种子
    default_random_engine el(time(0));
}