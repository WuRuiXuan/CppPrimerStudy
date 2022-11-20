#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() 
{
    // 统计每个单词在输入中出现次数的一种更烦琐的方法
    map<string, size_t> word_count; // 从 string 到 size_t 的空 map
    string word;
    while (cin >> word) {
        // 插入一个元素，关键字等于 word，值为1；
        // 若 word 已在 word_count 中，insert 什么也不做
        auto ret = word_count.insert({word, 1});
        if (!ret.second) {          // word 已在 word_count 中
            ++ret.first->second;    // 递增计数器
            cout << ret.first->first << ": " << ret.first->second << endl;
        }
    }
    for (auto it = word_count.cbegin(); it != word_count.cend(); ++it)
    {
        pair<string, size_t> pa = *it;
        cout << pa.first << " " << pa.second << endl;
    }
}