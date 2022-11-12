#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int arr[5];
    cout << "v size " << v.size() << " ";
    for (auto it = v.begin(); it != v.end(); it++) {
        auto idx = it - v.begin();
        cout << "idx " << idx << " ";
        arr[idx] = *it;
    }
    cout << "arr ";
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}