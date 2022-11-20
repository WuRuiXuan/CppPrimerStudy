#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include "../resources/Sales_data.h"

using namespace std;

size_t hasher(const Sales_data &);
bool eqOp(const Sales_data &, const Sales_data &);

using SD_multiset = unordered_multiset<Sales_data, 
                    decltype(hasher) *, decltype(eqOp) *>;

int main()
{
    // 统计出现次数，但单词不会按字典序排列
    unordered_map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word];          // 提取并递增 word 的计数器
    for (const auto &w : word_count) // 对 map 中的每个元素
        // 打印结果
        cout << w.first << " occurs " << w.second
                << ((w.second > 1) ? " times" : " time") << endl;

    // 参数是桶大小、哈希函数指针和相等性判断运算符指针
    SD_multiset bookStore(42, hasher, eqOp);
}

size_t hasher(const Sales_data &sd)
{
    return hash<string>()(sd.isbn());
}

bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn();
}