#include <iostream>

using namespace std;

int &get(int *, int);

int main()
{
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
}

int &get(int *array, int index) {
    return array[index];
}