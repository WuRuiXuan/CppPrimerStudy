#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flst.before_begin(); // 表示 flst 的“首前元素”
    auto curr = flst.begin();        // 表示 flst 中的第一个元素
    while (curr != flst.end()) {     // 仍有元素要处理
        if (*curr % 2)
            curr = flst.erase_after(prev); // 删除它并移动 curr
        else {
            prev = curr; // 移动迭代器 curr，指向下一个元素，prev 指向 curr 之前的元素
            ++curr;
        }
    }
    for (int i : flst)
        cout << i << " ";
    cout << endl;
}