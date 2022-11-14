#include <iostream>
#include <string>

using namespace std;

class Sales_data {
    public:
        // 非委托构造函数使用对应的实参初始化成员
        Sales_data(string s, unsigned cnt, double price) :
                bookNo(s), units_sold(cnt), revenue(cnt * price) { }
        // 其余构造函数全都委托给另一个构造函数
        Sales_data(): Sales_data("", 0, 0) {}
        Sales_data(string s): Sales_data(s, 0, 0) {}
        Sales_data(istream &is): Sales_data() { read(is, *this); }
    private:
        string bookNo;
        unsigned units_sold;
        double revenue;
        istream &read(istream&, Sales_data&);
};