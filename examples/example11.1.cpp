#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main()
{
    // 统计每个单词在输入中出现的次数
    map<string, size_t> word_count;  // string 到 size_t 的空 map
    set<string> exclude = {"The", "But", "And", "Or", "An"};

    string word;
    while (cin >> word)
        // 只统计不在 exclude 中的单词
        if (exclude.find(word) == exclude.end())
            ++word_count[word];          // 提取 word 的计数器并将其加1
    for (const auto &w : word_count) // 对 map 中的每个元素
        // 打印结果
        cout << w.first << " occurs " << w.second
                << ((w.second > 1) ? " times " : " time") << endl;
}