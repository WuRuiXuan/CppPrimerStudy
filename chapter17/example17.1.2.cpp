#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <tuple>
#include "../resources/Sales_data.h"

using namespace std;

typedef tuple<vector<Sales_data>::size_type,
                vector<Sales_data>::const_iterator,
                vector<Sales_data>::const_iterator> matches;

vector<matches>
findBook(const vector<vector<Sales_data>>& files, const string& book)
{
    vector<matches> ret;
    for (auto it = files.cbegin(); it != files.cend(); ++it) {
        // equal_range 返回一个迭代器 pair，表示元素的范围
        auto found = equal_range(it->cbegin(), it->cend(),
                                book, compareIsbn);
        // first 表示第一条匹配的记录
        // second 表示匹配的尾后位置
        if (found.first != found.second)
            ret.push_back(make_tuple(it - files.cbegin(),
                                    found.first, found.second));
    }
    return ret;
}

void reportResults(istream& in, ostream& os,
                    const vector<vector<Sales_data>>& files)
{
    string s; // 要查找的书
    while (in >> s) {
        auto trans = findBook(files, s); // 销售了这本书的书店
        if (trans.empty()) {
            cout << s << " not found in any stores" << endl;
            continue; // 获得下一本要查找的书
        }
        for (const auto& store : trans)
            os << "store " << get<0>(store) << " sales: "
                << accumulate(get<1>(store), get<2>(store),
                                Sales_data(s))
                << endl;
    }
}
