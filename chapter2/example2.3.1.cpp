#include <iostream>

int main()
{
    int ival = 1024;
    int &refVal = ival;     // refVal 指向 ival（是 ival 的别名）
    // int &refVal2;           // 报错：引用必须被初始化

    refVal = 2;         // 把 2 赋给 refVal 指向的对象，此处即是赋给了 ival
    int ii = refVal;    // 与 ii = ival 执行结果一样

    // 正确：refVal3 绑定到了那个与 refVal 绑定的对象上，这里就是绑定到 ival 上
    int &refVal3 = refVal;
    // 利用与 refVal 绑定的对象的值初始化变量 i
    int i = refVal;     // 正确：i 被初始化为 ival 的值

    int i1 = 1024, i2 = 2048;   // i1 和 i2 都是 int
    int &r1 = i1, r2 = i2;      // r1 是一个引用，与 i 绑定在一起，r2 是 int
    int i3 = 1024, &ri = i3;    // i3 是 int，ri 是一个引用，与 i3 绑定在一起
    int &r3 = i3, &r4 = i2;     // r3 和 r4 都是引用

    // int &refVal4 = 10;          // 错误：引用类型的初始值必须是一个对象
    double dval = 3.14;
    // int &refVal5 = dval;        // 错误：此处引用类型的初始值必须是 int 型对象
}