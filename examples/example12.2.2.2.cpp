#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
    size_t n = 3;
    allocator<string> alloc;                // 可以分配 string 的 allocator 对象
    auto const p = alloc.allocate(n);       // 分配 n 个未初始化的 string

    auto q = p;                             // q 指向最后构造的元素之后的位置
    alloc.construct(q++);                   // *q 为空字符串
    alloc.construct(q++, 10, 'c');          // *q 为 cccccccccc
    alloc.construct(q++, "hi");             // *q 为 hi

    for (int i = 0; i < n; ++i)
        cout << *(p + i) << " ";            // 正确：使用 string 的输出运算符
        // cout << *(q - i) << " ";            // 灾难：q 指向未构造的内存
    cout << endl;

    while (q != p)
        alloc.destroy(--q);                 // 释放我们真正构造的 string

    alloc.deallocate(p, n);                 // 将内存归还给系统
}