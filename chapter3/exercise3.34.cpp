#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int *p1 = arr;
    int *p2 = &arr[3];
    p1 += p2 - p1;
    cout << *p1 << " " << *p2 << endl;
    int k = p2[0] - p2[-3];
    cout << k << endl;
}