#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec{1, 2, 3};
    ostream_iterator<int> out_iter(cout, " ");
    for (auto e : vec)
        *out_iter++ = e; // 赋值语句实际上将元素写到 cout
    cout << endl;

    copy(vec.begin(), vec.end(), out_iter);
    cout << endl;
}