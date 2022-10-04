#include <iostream>

int main() {
    std::cout << "Enter two numbers" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    int bigger = 0, smaller = 0;
    if (v1 > v2) {
        bigger = v1;
        smaller = v2;
    }
    else {
        bigger = v2;
        smaller = v1;
    }
    while (smaller <= bigger)
    {
        std::cout << smaller++ << std::endl;
    }
    return 0;
}