#include <iostream>
#include <string>

using namespace std;

class Quote {
    public:
        Quote() = default;
        Quote(const string& book, double p):
                    bookNo(book), price(p) {}
        string isbn() const { return bookNo; };
        virtual double net_price(size_t n) const { return n * price; }
        virtual ~Quote() = default;
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
        double net_price(size_t) const = 0;
    protected:
        size_t min_qty = 0;         // 享受折扣的最低购买量
        double discount = 0.0;      // 折扣额
};

class Bulk_quote : public Disc_quote {
    public:
        using Disc_quote::Disc_quote;   // 继承 Disc_quote 的构造函数
        // 等价于：
        // Bulk_quote(const string& book, double p, 
        //             size_t qty, double disc):
        //             Disc_quote(book, p, qty, disc) {}
        double net_price(size_t) const override;
};

/**
 * 继承的构造函数的特点：
 * 1. using 声明不会改变该构造函数的访问级别
 * 2. using 声明不能指定 explicit 或 constexpr，只能被继承
 * 3. 默认实参不会被继承
 * 4. 可以继承多个构造函数，如与派生类的参数列表相同，则不继承
 * 5. 默认、拷贝和移动构造函数不会被继承，只会被合成
 */