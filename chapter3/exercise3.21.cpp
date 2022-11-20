#include <iostream>
#include <vector>

using std::iostream;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<int> v1;
    int val;
    while (cin >> val)
    {
        v1.push_back(val);
    }
    for (auto it = v1.begin(); it != v1.end(); ++it)
    {
        if (*it <= v1.size() / 2) {
            cout << v1[*it] + v1[v1.size() - 1 - *it] << endl;
        }
        else {
            cout << v1[*it] << endl;
            break;
        }
    }
}