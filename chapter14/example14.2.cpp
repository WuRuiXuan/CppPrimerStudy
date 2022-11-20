#include <iostream>
#include "../resources/Sales_data.h"

using namespace std;

// 输入输出运算符必须是非成员函数，一般被声明为友元
ostream& operator<<(std::ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price();
    return os;
}

istream& operator>>(istream &is, Sales_data &item)
{
    double price; // 不需要初始化，因为我们将先读入数据到 price，之后才使用它
    is >> item.bookNo >> item.units_sold >> price;
    if (is)       // 检查输入是否成功
        item.revenue = item.units_sold * price;
    else
        item = Sales_data(); // 输入失败：对象被赋予默认的状态
    return is;
}