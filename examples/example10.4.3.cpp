#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 从尾元素到首元素的反向迭代器
    for (auto r_iter = vec.crbegin();   // 将 r_iter 绑定到尾元素
                r_iter != vec.crend();  // creand 指向首元素之前的位置
                ++r_iter)               // 实际是递减，移动到前一个元素
        cout << *r_iter << " ";        // 打印 9, 8, 7, ... 0
    cout << endl;

    // 按逆序排序：将最小元素放在 vec 的末尾
    sort(vec.rbegin(), vec.rend());

    for (auto r_iter = vec.cbegin();
                r_iter != vec.cend();
                ++r_iter)
        cout << *r_iter << " ";
    cout << endl;
}