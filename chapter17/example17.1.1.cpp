#include <iostream>
#include <tuple>
#include <vector>
#include <list>

using namespace std;

int main()
{
    tuple<size_t, size_t, size_t> threeD; // 三个成员都设置为 0
    tuple<string, vector<double>, int, list<int>>
        someVal("constants", {3.14, 2.718}, 42, {0, 1, 2, 3, 4, 5});
    
    // tuple<size_t, size_t, size_t> threeD2 = {1, 2, 3}; // 错误
    tuple<size_t, size_t, size_t> threeD3{1, 2, 3}; // 正确

    // tuple<const char*, int, double>
    auto item = make_tuple("0-999-78345-X", 3, 20.00);

    // 访问 tuple 成员
    auto book = get<0>(item);
    auto cnt = get<1>(item);
    auto price = get<2>(item) / cnt;
    get<2>(item) *= 0.8;

    // tuple 中成员的数量
    size_t sz = tuple_size<decltype(item)>::value; // 返回 3
    // tuple 中某一成员的类型
    tuple_element<1, decltype(item)>::type cnt = get<1>(item); // cnt 是一个 int

    tuple<string, string> duo("1", "2");
    tuple<size_t, size_t> twoD(1, 2);
    bool b = (duo == twoD);     // 错误：不能比较 size_t 和 string
    tuple<size_t, size_t, size_t> threeD(1, 2, 3);
    b = (twoD < threeD);        // 错误：成员数量不同
    tuple<size_t, size_t> origin(0, 0);
    b = (origin < twoD);        // 正确：b 为 true
}