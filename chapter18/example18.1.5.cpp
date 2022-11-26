#include <iostream>
#include "../resources/Sales_data.h"

using namespace std;

// 自定义异常类
class out_of_stock: public runtime_error {
    public:
        explicit out_of_stock(const string& s): runtime_error(s) { }
};

class isbn_mismatch: public logic_error {
    public:
        explicit isbn_mismatch(const string& s): logic_error(s) { }
        isbn_mismatch(const string& s,
            const string& lhs, const string& rhs):
            logic_error(s), left(lhs), right(rhs) { }
        const string left, right;
};

// 如果参与加法的两个对象并非同一书籍，则抛出一个异常
Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
    if (isbn() != rhs.isbn())
        throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

int main() {
    Sales_data item1, item2, sum;
    while (cin >> item1 >> item2) {         // 读取两条交易信息
        try {
            sum = item1 + item2;            // 计算它们的和
            // 使用 sum
        } catch (const isbn_mismatch &e) {
            cerr << e.what() << ": left isbn(" << e.left
                 << ") right isbn(" << e.right << ")" << endl;
        }
    }
}