#include <iostream>

int main() {
    std::cout << "Enter two numbers" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    while (v2 >= v1) {
        std::cout << v2 << std::endl;
        --v2;
    }
    return 0;
}