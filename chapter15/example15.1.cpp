#include <iostream>
#include <string>

using namespace std;

class Quote {
    public:
        Quote() = default;
        Quote(const string& book, double p):
                    bookNo(book), price(p) {}
        string isbn() const { return bookNo; };
        // 虚函数（基类）
        // 返回给定数量的书籍的销售总额
        virtual double net_price(size_t n) const { return n * price; }
        virtual ~Quote() = default; // 对析构函数进行动态绑定
    private:
        string bookNo;              // 书籍的 ISBN 编号
    protected:
        double price = 0.0;         // 不打折的价格
};

class Disc_quote : public Quote {
    public:
        Disc_quote() = default;
        Disc_quote(const string& book, double p, 
                    size_t qty, double disc):
                    Quote(book, p), min_qty(qty), discount(disc) {}
        // 纯虚函数（必须在类的外部定义）
        double net_price(size_t) const = 0;
    protected:
        size_t min_qty = 0;         // 享受折扣的最低购买量
        double discount = 0.0;      // 折扣额
};

class Bulk_quote : public Disc_quote {   // Bulk_quote 继承自 Quote
    public:
        Bulk_quote() = default;
        // 首先初始化基类的部分，然后依次初始化派生类的成员
        Bulk_quote(const string& book, double p, 
                    size_t qty, double disc):
                    Disc_quote(book, p, qty, disc) {}
        // 覆盖基类的函数版本
        double net_price(size_t) const override;
};

// 计算并打印销售给定数量的某种书籍所得的费用
double print_total(ostream& os, const Quote& item, size_t n)
{
    // 根据传入 item 形参的对象类型调用 Quote::net_price
    // 或者 Bulk_quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()   // 调用 Quote::isbn
        << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

// 如果达到了最低购买量，就可以享受折扣价了
double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

int main()
{
    Quote basic("aaa", 1.5);
    Bulk_quote bulk("aaa", 1.5, 10, 0.1);
    // 调用一个虚函数时，将发生动态绑定
    print_total(cout, basic, 20);       // Quote::net_price
    print_total(cout, bulk, 20);        // Bulk_quote::net_price

    // 强行调用基类中定义的函数版本
    double undiscounted = bulk.Quote::net_price(10);
    double discounted = bulk.net_price(10);
    cout << undiscounted << endl;
    cout << discounted << endl;

    // Disc_quote 声明了纯虚函数，是抽象基类
    // Disc_quote disc;             // 错误：不能定义 Disc_quote 的对象
    Bulk_quote bulk2;               // 正确：Bulk_quote 中没有纯虚函数
}