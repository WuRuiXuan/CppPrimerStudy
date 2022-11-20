#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    // 定义一个有 20 个元素的 vector，保存 0 到 9 每个整数的两个拷贝
    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i) {
        ivec.push_back(i);
        ivec.push_back(i); // 每个数重复保存一次
    }
    // iset 包含来自 ivec 的不重复的元素；miset 包含所有 20 个元素
    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());
    cout << ivec.size() << endl; // 打印出20
    cout << iset.size() << endl; // 打印出10
    cout << miset.size() << endl; // 打印出20
}