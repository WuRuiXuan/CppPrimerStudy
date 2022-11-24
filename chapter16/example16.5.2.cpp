#include <iostream>
#include <unordered_set>
#include "../resources/Sales_data.h"

using namespace std;

// 打开 std 命名空间，以便特例化 std::hash
namespace std {

// 类模板特例化
template <>
struct hash<Sales_data>
{
    // 用来散列一个无序容器的类型必须要定义下列类型
    typedef size_t result_type;
    typedef Sales_data argument_type; // 默认情况下，此类型需要 ==
    size_t operator()(const Sales_data& s) const;
};

size_t hash<Sales_data>::operator()(const Sales_data& s) const
{
    return hash<string>()(s.bookNo) ^
            hash<unsigned>()(s.units_sold) ^
            hash<double>()(s.revenue);
}

} // 关闭 std 命名空间

int main()
{
    // 使用 hash<Sales_data> 和 Sales_data operator== 
    unordered_multiset<Sales_data> SDset;   
	Sales_data item;
	while (cin >> item) {
		SDset.insert(item);
	}
	cout << SDset.size() << endl;
}