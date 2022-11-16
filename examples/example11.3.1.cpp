#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, size_t> word_count = {{"hello", 1}, {"world", 2}};
    // 获得指向 word_count 中一个元素的迭代器
    auto map_it = word_count.begin();
    // *map_it 是指向一个 pair<const string, size_t> 对象的引用
    cout << map_it->first;           // 打印此元素的关键字
    cout << " " << map_it->second;   // 打印此元素的值
    // map_it->first = "new key";       // 错误：关键字是 const 的
    ++map_it->second; // 正确：我们可以通过迭代器改变元素
}