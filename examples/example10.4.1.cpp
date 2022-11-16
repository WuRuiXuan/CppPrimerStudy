#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

void print(list<int> &);

int main()
{
    list<int> lst = {1, 2, 3, 4};
    list<int> lst2, lst3; // 空 list
    // 拷贝完成之后，lst2 包含 4 3 2 1
    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
    // 拷贝完成之后，lst3 包含 1 2 3 4
    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
    print(lst2);
    print(lst3);
}

void print(list<int> &lst)
{
    for (int i : lst)
        cout << i << " ";
    cout << endl;
}