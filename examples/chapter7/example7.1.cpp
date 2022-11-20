#include <iostream>
#include <string>

using namespace std;

struct Sales_data
{
    // 新成员：关于 Sales_data 对象的操作
    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    // 数据成员
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    // 新增的构造函数
    Sales_data() = default;
    Sales_data(const string &s): bookNo(s) { }
    Sales_data(const string &s, unsigned n, double p): bookNo(s), 
                units_sold(n), revenue(p*n) { }
    Sales_data(istream &);
};

Sales_data::Sales_data(istream &is)
{
    read(is, *this); // read 函数的作用是从 is 中读取一条交易信息然后存入 this 对象中
}

// Sales_data 的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold; // 把 rhs 的成员加到 this 对象的成员上
    revenue += rhs.revenue;
    return *this; // 返回调用该函数的对象
}

double Sales_data::avg_price() const {
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs; // 把 lhs 的数据成员拷贝给 sum
    sum.combine(rhs); // 把 rhs 的数据成员加到 sum 当中
    return sum;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price();
    return os;
}

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

int main()
{
    Sales_data total; // 保存当前求和结果的变量
    if (read(cin, total)) { // 读入第一笔交易
        Sales_data trans; // 保存下一条交易数据的变量
        while(read(cin, trans)) { // 读入剩余的交易
            if (total.isbn() == trans.isbn()) // 检查 isbn
                total.combine(trans); // 更新变量 total 当前的值
            else {
                print(cout, total) << endl; // 输出结果
                total = trans; // 处理下一本书
            }
        }
        print(cout, total) << endl; // 输出最后一条交易
    } else {
        cerr << "No data?!" << endl; // 通知用户
    }
}