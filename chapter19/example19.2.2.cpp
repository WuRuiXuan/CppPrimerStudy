#include <typeinfo>

using namespace std;

struct Base {
   virtual ~Base() {};
};

struct Derived: public Base { };

int main() {
    Derived *dp = new Derived;
    Base *bp = dp;                      // 两个指针都指向 Derived 对象
    // 在运行时比较两个对象的类型
    if (typeid(*bp) == typeid(*dp)) {
        // bp 和 dp 指向同一类型的对象
    }
    // 检查运行时类型是否是某种指定的类型
    if (typeid(*bp) == typeid(Derived)) {
        // bp 实际指向 Derived 对象
    }
    // 下面的检查永远是失败的：bp 的类型是指向 Base 的指针
    if (typeid(bp) == typeid(Derived)) { // 比较的是 Base* 和 Derived
        // 此处的代码永远不会执行
    }
    /**
     * 如果指针 p 所指类型不含有虚函数，则编译器不会对表达式求值，p 可以是一个空指针
     * 反之，则编译器会对表达式求值，如果 p 是一个空指针，将抛出 bad_typeid 的异常
     */
}