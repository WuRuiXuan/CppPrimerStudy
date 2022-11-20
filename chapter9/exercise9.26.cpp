#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> v(ia, ia + sizeof(ia) / sizeof(ia[0]));
    list<int> lst(ia, ia + sizeof(ia) / sizeof(ia[0]));
    auto v_it = v.begin();
    while (v_it != v.end())
        if (*v_it % 2)
            ++v_it;
        else
            v_it = v.erase(v_it);
    for (int i : v)
        cout << i << " ";
    cout << endl;

    auto l_it = lst.begin();
    while (l_it != lst.end())
        if (*l_it % 2)
            l_it = lst.erase(l_it);
        else
            ++l_it;
    for (int i : lst)
        cout << i << " ";
    cout << endl;
}