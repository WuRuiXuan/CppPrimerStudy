#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1{0, 1, 1, 2};
    vector<int> v2{0, 1, 1, 2, 3, 5, 8};
    vector<int> &v_min = v1.size() > v2.size() ? v2 : v1;
    vector<int> &v_max = v1.size() > v2.size() ? v1 : v2;
    int i = 0;
    for (; i < v_min.size() && v_min[i] == v_max[i]; i++)
    ;
    if (i == v_min.size())
        cout << "Is prefix" << endl;
    else
        cout << "Is not prefix" << endl;
}