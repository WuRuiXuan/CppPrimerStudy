#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<string> text{"a", "b", "c", "d", "e"};
    string sought{"c"};
    // text 必须是有序的
    // beg 和 end 表示我们搜索的范围
    auto beg = text.begin(), end = text.end();
    auto mid = text.begin() + (end - beg) / 2; // 初始状态下的中间点
    // 当还有元素尚未检查并且我们还没有找到 sought 时执行循环
    while (mid != end && *mid != sought)
    {
        if (sought < *mid)  // 我们要找的元素在前半部分吗？
            end = mid;      // 如果是，调整搜索范围使得忽略掉后半部分
        else                // 我们要找的元素在后半部分
            beg = mid + 1;  // 在 mid 之后寻找
        mid = beg + (end - beg) / 2; //新的中间点
    }
    cout << mid - text.begin() << endl;
}