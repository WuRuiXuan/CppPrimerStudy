#include <iostream>
#include "../resources/Sales_item.h"

int main() {
    Sales_item item1, item2, sum;
    if (std::cin >> item1) {
        sum = item1;
        while (std::cin >> item2)
        {
            if (item2 == item1) {
                sum += item2;
            }
        }
    }
    std::cout << sum << std::endl;
    return 0;
}