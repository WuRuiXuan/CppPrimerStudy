#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, size_t> word_count;
    string word = "hello";
    // 向 word_count 插入 word 的4种方法
    word_count.insert({word, 1});
    word_count.insert(make_pair(word, 1));
    word_count.insert(pair<string, size_t>(word, 1));
    word_count.insert(map<string, size_t>::value_type(word, 1));
    for (auto it = word_count.cbegin(); it != word_count.cend(); ++it)
    {
        pair<string, size_t> pa = *it;
        cout << pa.first << " " << pa.second << endl;
    }
}