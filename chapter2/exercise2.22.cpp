#include <iostream>

int main()
{
    int i = 0;
    int *p = &i;
    if (p) // 存有 i 的地址
        std::cout << "if(p) true" << std::endl;
    else
        std::cout << "if(p) false" << std::endl;

    if (*p) // 解引用
        std::cout << "if(*p) true" << std::endl;
    else
        std::cout << "if(*p) false" << std::endl;

    int *q = 0; // 表示是一个空指针
    if (q)
        std::cout << "if(q) true" << std::endl;
    else
        std::cout << "if(q) false" << std::endl;
}