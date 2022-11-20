#include <iostream>
#include "../resources/Sales_item.h"

int main() {
    Sales_item currentItem, item;
    int cnt = 1;
    if (std::cin >> currentItem) {
        while (std::cin >> item)
        {
            if (item.isbn() == currentItem.isbn()) {
                cnt++;
            }
            else {
                std::cout << "Book " << currentItem << " has " 
                << cnt << " sale records";
                currentItem = item;
                cnt = 1;
            }
        }
        std::cout << "Book " << currentItem << " has " 
        << cnt << " sale records";
    }
    return 0;
}