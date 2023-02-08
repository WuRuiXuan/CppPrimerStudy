#include <iostream>
#include "../resources/Sales_item.h"

int main()
{
    int sum = 0, value, // sum、value 和 units_sold 都是 int
    units_sold = 0;     // sum 和 units_sold 初值为 0
    
    Sales_item item; // item 的类型是 Sales_item

    // string 是一种库类型，表示一个可变长的字符序列
    std::string book("0-201-78345-X"); // book 通过一个 string 字面值初始化

    // 正确：price 先被定义并赋值，随后被用于初始化 discount
    double price = 109.99, discount = price * 0.16;
    // 正确：调用函数 applyDiscount，然后用函数的返回值初始化 salePrice
    // double salePrice = applyDiscount(price, discount);

    int units_sold = 0;
    int units_sold = {0}; // 列表初始化
    int units_sold{0}; // 列表初始化
    int units_sold(0);

    long double ld = 3.1415926536;
    int a{ld}, b = {ld};    // 错误：转换未执行，因为存在丢失信息的危险
    int c(ld), d = ld;      // 正确：转换执行，且确实丢失了部分值

    std::string empty;      // empty 非显示地初始化为一个空串
    Sales_item item;        // 被默认初始化的 Sales_item 对象
}