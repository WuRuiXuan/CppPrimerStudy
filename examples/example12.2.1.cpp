#include <iostream>
#include <memory>

using namespace std;

int main()
{
    // up 指向一个包含10个未初始化 int 的数组
    unique_ptr<int[]> up(new int[10]);
    up.release(); // 自动用 delete[] 销毁其指针
    for (size_t i = 0; i != 10; ++i)
        up[i] = i; // 为每个元素赋予一个新值

    // 为了使用 shared_ptr，必须提供一个删除器
    shared_ptr<int> sp(new int[10], [](int *p) { delete[] p; });
    sp.reset(); // 使用我们提供的 lambda 释放数组，它使用 delete[]

    // shared_ptr 未定义下标运算符，并且不支持指针的算术运算
    for (size_t i = 0; i != 10; ++i)
        *(sp.get() + i) = i; // 使用 get 获取一个内置指针
}