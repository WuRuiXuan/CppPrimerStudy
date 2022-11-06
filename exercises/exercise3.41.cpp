#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

int main()
{
    int int_arr[] = {1, 2, 3, 4, 5};
    vector<int> ivec(begin(int_arr), end(int_arr));
    for (auto i : ivec)
        cout << i << " ";
    cout << endl;
}