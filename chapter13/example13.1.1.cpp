#include <string>
#include <vector>

using namespace std;

class Sales_data {
    public:
        Sales_data();
        // 其他成员和构造函数的定义，如前
        // 等价于合成拷贝构造函数
        Sales_data(const Sales_data&);
        // 等价于合成拷贝赋值运算符
        Sales_data& operator=(const Sales_data&);
        // 等价于合成析构函数
        ~Sales_data();
    private:
        string bookNo;
        int units_sold = 0;
        double revenue = 0.0;
};

Sales_data::Sales_data(const Sales_data &orig):
    bookNo(orig.bookNo),            // 使用 string 的拷贝构造函数
    units_sold(orig.units_sold),    // 拷贝 orig.units_sold
    revenue(orig.revenue)           // 拷贝 orig.revenue
    {}                              // 空函数体

Sales_data& Sales_data::operator=(const Sales_data &rhs)
{
    bookNo = rhs.bookNo;            // 调用 string::operator=
    units_sold = rhs.units_sold;    // 使用内置的 int 赋值
    revenue = rhs.revenue;          // 使用内置的 double 赋值
    return *this;                   // 返回一个此对象的引用
}

Sales_data::~Sales_data() {}        // 成员会被自动销毁，除此之外不需要做其他事情

int main()
{
    // p 和 p2 指向动态分配的对象
    Sales_data *p = new Sales_data;         // p 是一个内置指针
    auto p2 = make_shared<Sales_data>();    // p2 是一个 shared_ptr
    Sales_data item(*p);        // 拷贝构造函数将 *p 拷贝到 item 中
    vector<Sales_data> vec;     // 局部对象
    vec.push_back(*p2);         // 拷贝 p2 指向的对象
    delete p;                   // 对 p 指向的对象执行析构函数
}   // 退出局部作用域；对 item、p2 和 vec 调用析构函数
    // 销毁 p2 会递减其引用计数；如果引用计数变为0，对象被释放
    // 销毁 vec 会销毁它的元素