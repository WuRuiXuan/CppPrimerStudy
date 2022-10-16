#include <iostream>
#include <vector>
#include <iterator>

using std::vector;
using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
    constexpr size_t size = 5;
    int arr1[size] = {1, 2, 3, 4, 5};
    int arr2[size] = {1, 2, 3, 4, 5};

    bool flag = true;
    int i = 0;
    for (int i = 0; i < size; i++) {
        int *p1 = arr1;
        int *p2 = arr2;
        cout << "p1 " << p1[i] << " ";
        cout << "p2 " << p2[i] << " ";
        if (p1[i] != p2[i]) {
            flag = false;
        }
    }
    cout << "flag " << flag <<endl;
}