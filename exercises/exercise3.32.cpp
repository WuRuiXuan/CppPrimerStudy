#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v1(10, 0);
    for (auto beg = v1.begin(); beg != v1.end(); beg++)
        *beg = beg - v1.begin();
    for (auto beg = v1.begin(); beg != v1.end(); beg++)
        cout << *beg << " ";
    cout << endl;
}