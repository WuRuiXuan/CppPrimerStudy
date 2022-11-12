#include <iostream>
#include <vector>

using namespace std;

void factorial(vector<int>, size_t);

int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    factorial(v, 0);
}

void factorial(vector<int> v, size_t index) {
    if (index < v.size()) {
        cout << v[index] << " ";
        return factorial(v, ++index);
    }
    cout << endl;
}