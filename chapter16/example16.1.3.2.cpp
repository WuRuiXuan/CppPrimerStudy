#include <functional>
#include "../resources/Sales_data.h"

using namespace std;

// compare 有一个默认模板实参 less<T> 和一个默认函数实参 F()
template <typename T, typename F = less<T>>
int compare(const T& v1, const T& v2, F f = F())
{
    if (f(v1, v2)) return -1;
    if (f(v2, v1)) return 1;
    return 0;
}

template <class T = int> class Numbers {    // T 默认为 int
    public:
        Numbers(T v = 0): val(v) { }
    private:
        T val;
};

int main() {
    bool i = compare(0, 42); // 使用 less
    // 结果依赖于 item1 和 item2 中的 isbn
    Sales_data item1(cin), item2(cin);
    bool j = compare(item1, item2, compareIsbn);

    Numbers<long double> lots_of_precision;
    Numbers<> average_precision; // 空 <> 表示我们希望使用默认类型
}