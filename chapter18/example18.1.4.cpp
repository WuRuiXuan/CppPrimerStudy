#include <iostream>

using namespace std;

void recoup(int) noexcept;          // 不会抛出异常
void recoup(int) throw();           // 不会抛出异常
void recoup(int) noexcept(true);    // 不会抛出异常
void alloc(int);                    // 可能抛出异常
void alloc(int) noexcept(false);    // 可能抛出异常

// 违反了异常说明，但仍可以顺利编译通过
void f() noexcept
{
    throw exception();
}

int main()
{
    // recoup 抛异常返回 true，否则返回 false
    noexcept(recoup(0));
}