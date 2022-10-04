#include <iostream>

int main()
{
    int i = 0;
    int *p = &i;
    if (p)
        std::cout << "if(p) true" << std::endl;
    else
        std::cout << "if(p) false" << std::endl;

    if (*p)
        std::cout << "if(*p) true" << std::endl;
    else
        std::cout << "if(*p) false" << std::endl;

    int *q = 0;
    if (q)
        std::cout << "if(q) true" << std::endl;
    else
        std::cout << "if(q) false" << std::endl;
}