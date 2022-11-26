#include <typeinfo>

using namespace std;

/**
 * dynamic_cast 的使用形式：
 * 1. dynamic_cast<type*>(e)
 * 2. dynamic_cast<type&>(e)
 * 3. dynamic_cast<type&&>(e)
 * 
 * e 要满足以下三个条件之一，否则转换失败：
 * 1. type 的公有派生类
 * 2. type 的公有基类
 * 3. type 的同类型
 * 
 * 如果转换目标是指针类型，则转换失败返回 0
 * 如果转换目标是引用类型，则转换失败抛出 bad_cast 异常
 */

struct Base {
   virtual ~Base() {};
};

struct Derived: public Base { };

void f(const Base& b)
{
    // 引用类型转换
    try {
        const Derived& d = dynamic_cast<const Derived&>(b);
        // 使用 b 引用的 Derived 对象
    } catch (bad_cast& e) {
        // 处理类型转换失败的情况
    }
}

int main()
{
    // 指针类型转换
    Base *bp; 
	bp = new Derived;
    if (Derived* dp = dynamic_cast<Derived*>(bp)) {
        // 使用 dp
    } else {        // bp 指向一个 Base 对象
        // 使用 bp
    }
}