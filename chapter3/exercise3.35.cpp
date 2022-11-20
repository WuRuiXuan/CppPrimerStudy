#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
    int arr[10] = {1, 2, 3, 4, 5};
    for (int *beg = begin(arr); beg != end(arr); beg++) {
        *beg = 0;
    }
    for (int *beg = begin(arr); beg != end(arr); beg++) {
        cout << *beg << " ";
    }
    cout << endl;
}