#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    vector<int> v1;
    int val;
    while (cin >> val) {
        v1.push_back(val);
    }
    // for (unsigned i = 0; i < v1.size(); i = i + 2) {
    //     if (i < v1.size() - 1) {
    //         cout << v1[i] + v1[i + 1] << endl;
    //     }
    //     else {
    //         cout << v1[i] << endl;
    //     }
    // }
    decltype(v1.size()) size = v1.size();
    for (unsigned i = 0; i < size / 2; i++) {
        if (i < v1.size() - 1) {
            cout << v1[i] + v1[size - 1 - i] << endl;
        }
        else {
            cout << v1[i] << endl;
        }
    }
}