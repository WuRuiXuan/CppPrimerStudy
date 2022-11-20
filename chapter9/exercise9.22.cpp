#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> iv{1, 2, 3, 4, 5};
    int some_val = 2;
    vector<int>::iterator iter = iv.begin(),
                        mid = iv.begin() + iv.size() / 2;
    while (iter++ != mid)
        if (*iter == some_val)
            iv.insert(iter, 2 * some_val);
    for (int i : iv)
        cout << i << " ";
    cout << endl;
}