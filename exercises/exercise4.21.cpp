#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    for (int i = 0; i < vec.size(); ++i)
        vec[i] = ((vec[i] % 2 == 0) ? vec[i] : vec[i] * 2);
    for (auto i : vec)
        cout << i << endl;
}