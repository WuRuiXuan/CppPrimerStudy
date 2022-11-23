#include <iostream>

using namespace std;

template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
    f(t2, t1);
}

template <typename F, typename T1, typename T2>
void flip2(F f, T1&& t1, T2&& t2)
{
    f(t2, t1);
}

/**
 * forward 完美转发：形参传递给下一个函数时，保持其左值或右值的属性
 * 当 T1 实参是一个左值，把 T1 传递给 f 时会发生引用折叠，int&& -> int&
 */
template <typename F, typename T1, typename T2>
void flip3(F f, T1&& t1, T2&& t2)
{
    f(forward<T2>(t2), forward<T1>(t1));
}

void f(int v1, int& v2)
{
    cout << v1 << " " << ++v2 << endl;
}

void g(int&& v1, int& v2)
{
    cout << v1 << " " << ++v2 << endl;
}

int main()
{
    int i = 0, j = 0, k = 0;

    f(42, i);           // f 改变了实参 i
    cout << "i: " << i << endl;
    cout << endl;

    /**
     * 实例化为：void flip1(void(*fcn)(int, int&), int t1, int t2);
     * j 的值被拷贝到 t1 中
     */
    flip1(f, j, 42);    // 通过 flip1 调用 f 不会改变 j
    cout << "j: " << j << endl;
    cout << endl;

    // flip2(g, k, 42); // 错误：不能从一个左值实例化 int&&
    
    flip3(g, k, 42);    // k 以 int& 类型，42 以 int&& 类型
    cout << "k: " << k << endl;
}