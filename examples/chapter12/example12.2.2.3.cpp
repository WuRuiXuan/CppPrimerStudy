#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi = {1, 2, 3};
    size_t n = vi.size() * 2;
    // 分配比 vi 中元素所占用空间大一倍的动态内存
    allocator<int> alloc;
    auto p = alloc.allocate(n);
    // 通过拷贝 vi 中的元素来构造从 p 开始的元素
    auto q = uninitialized_copy(vi.begin(), vi.end(), p);
    // 将剩余元素初始化为 42
    uninitialized_fill_n(q, vi.size(), 42);
    
    for (int i = 0; i < n; ++i)
        cout << *(p + i) << " ";
    cout << endl;

    alloc.destroy(q);
    alloc.deallocate(p, n);
}