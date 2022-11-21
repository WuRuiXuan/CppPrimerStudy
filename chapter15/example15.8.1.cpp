#include <iostream>
#include <memory>
#include <set>
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
        // 该虚函数返回当前对象的一份动态分配的拷贝
        virtual Quote* clone() const & { return new Quote(*this); }
        virtual Quote* clone() && { return new Quote(std::move(*this)); }
    private:
        string bookNo;              // 书籍的 ISBN 编号
    protected:
        double price = 0.0;         // 不打折的价格
};

class Bulk_quote : public Quote {
    public:
        Bulk_quote(const string& book, double p, 
                    size_t qty, double disc):
                    Quote(book, p), min_qty(qty), discount(disc) {}
        double net_price(size_t) const override;
        Bulk_quote* clone() const & { return new Bulk_quote(*this); }
        Bulk_quote* clone() && { return new Bulk_quote(std::move(*this)); }
    private:
        size_t min_qty = 0;         // 享受折扣的最低购买量
        double discount = 0.0;      // 折扣额
};

class Basket {
    public:
        // Basket 使用合成的默认构造函数和拷贝控制成员
        void add_item(const shared_ptr<Quote> &sale) { items.insert(sale); }
        /**
         * new Quote(sale) 如果 sale 是 Bulk_quote 对象，则会丢失一部分
         * clone() 根据 sale 是 Quote 对象还是 Bulk_quote 对象来拷贝，不会丢失一部分
         */
        // 拷贝给定的对象
        void add_item(const Quote& sale)
            { items.insert(shared_ptr<Quote>(sale.clone())); }
        // 移动给定的对象
        void add_item(Quote&& sale)
            { items.insert(shared_ptr<Quote>(std::move(sale).clone())); }
        // 打印每本书的总价和购物篮中所有书的总价
        double total_receipt(ostream&) const;
    private:
        // 该函数用于比较 shared_ptr，multiset 成员会用到它
        static bool compare(const shared_ptr<Quote> &lhs,
                            const shared_ptr<Quote> &rhs)
        { return lhs->isbn() < rhs->isbn(); }
        // multiset 保存多个报价，按照 compare 成员排序
        multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double print_total(ostream& os, const Quote& item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
        << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

double Basket::total_receipt(ostream &os) const
{
    double sum = 0.0;               // 保存实时计算出的总价格
    // iter 指向 ISBN 相同的一批元素中的第一个
    // upper_bound 返回一个迭代器，该迭代器指向这批元素的尾后位置
    // 调用 upper_bound 跳过与当前关键字相同的所有元素
    for (auto iter = items.cbegin();
                iter != items.cend();
                iter = items.upper_bound(*iter)) {
        // 在当前的 Basket 中至少有一个该关键字的元素
        // 打印该书籍对应的项目
        sum += print_total(os, **iter, items.count(*iter));
    } 
    os << "Total Sale: " << sum << endl;    // 打印最终的总价格
    return sum;
}

int main()
{
    Basket bsk;
    bsk.add_item(make_shared<Quote>("123", 45));
    bsk.add_item(make_shared<Bulk_quote>("345", 45, 3, .1));
    bsk.add_item(Bulk_quote("567", 45, 1, .1));
    bsk.add_item(Bulk_quote("567", 45, 1, .1));
    bsk.total_receipt(cout);
}