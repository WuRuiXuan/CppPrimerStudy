#include <iostream>

using namespace std;

void print(int *, int);

int main()
{
    int i = 0, j[2] = {0, 1};
    print(&i, 1);
    print(j, 2);
}

void print(int *p, int size)
{
    for (int i = 0; i < size; ++i) {
        cout << *p++ << " ";
    }
    cout << endl;
}