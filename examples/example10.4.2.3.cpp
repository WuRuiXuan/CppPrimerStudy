#include <iostream>
#include <iterator>
#include "../resources/Sales_item.h"

using namespace std;

int main()
{
    istream_iterator<Sales_item> item_iter(cin), eof;
    ostream_iterator<Sales_item> out_iter(cout, "\n");
    // 将第一笔交易记录存在 sum 中，并读取下一条记录
    Sales_item sum = *item_iter++;
    while (item_iter != eof) {
        // 如果当前交易记录（存在 item_iter 中）有着相同的 ISBN 号
        if (item_iter->isbn() == sum.isbn())
            sum += *item_iter++; // 将其加到 sum 上并读取下一条记录
        else {
            out_iter = sum;      // 输出 sum 当前值
            sum = *item_iter++;  // 读取下一条记录
        }
    }
    out_iter = sum;              // 记得打印最后一组记录的和
}