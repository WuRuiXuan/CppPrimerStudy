#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    int i = 1;
    int *ptr = &i;
    cout << (ptr != 0 && *ptr++) << endl;

    int ival = 0;
    cout << (ival++ && ival) << endl;

    vector<int> vec{1, 2, 3};
    cout << (vec[ival++] <= vec[ival]) << endl;
}