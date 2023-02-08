#include <iostream>
#include "../resources/Sales_item.h"

int main()
{
    typedef double wages; // wages 是 double 的同义词
    typedef wages base, *p; // base 是 double 的同义词，p 是 double* 的同义词

    using SI = Sales_item; // SI 是 Sales_item 的同义词

    wages hourly, weekly; // 等价于 double hourly, weekly
    SI item; // 等价于 Sales_item item
}