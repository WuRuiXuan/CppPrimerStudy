#include <iostream>

int main()
{
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;
    r2 = 3.14159;
    std::cout << r2 << std::endl;
    std::cout << d << "\n" << std::endl;
    // r2 = r1;
    // std::cout << r2 << std::endl;
    // std::cout << d << "\n" << std::endl;
    i = r2;
    std::cout << i << std::endl;
    std::cout << r1 << "\n" << std::endl;
    r1 = d;
    std::cout << i << std::endl;
    std::cout << r1 << "\n" << std::endl;
}