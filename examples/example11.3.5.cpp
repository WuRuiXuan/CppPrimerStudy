#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    multimap<string, string> authors;
    // 关键字相同的元素，相邻存储
    for (int i = 0; i < 2; ++i)
    {
        authors.insert({"Alain", "book1"});
        authors.insert({"Mike", "book2"});
    }
    string search_item("Alain");                // 要查找的作者
    auto entries = authors.count(search_item);  // 元素的数量
    auto iter = authors.find(search_item);      // 此作者的第一本书
    // 用一个循环查找此作者的所有著作
    while (entries)
    {
        cout << iter->second << endl;            // 打印每个题目
        ++iter;                                  // 前进到下一本书
        --entries;                               // 记录已经打印了多少本书
    }
    cout << endl;

    // beg 和 end 表示对应此作者的元素的范围
    for (auto beg = authors.lower_bound(search_item),
                end = authors.upper_bound(search_item);
                beg != end; ++beg)
        cout << beg->second << endl; // 打印每个题目
    cout << endl;
    
    // pos 保存迭代器对，表示与关键字匹配的元素范围
    for (auto pos = authors.equal_range(search_item);
                pos.first != pos.second; ++pos.first)
        cout << pos.first->second << endl; // 打印每个题目
}
