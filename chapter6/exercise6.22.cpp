#include <iostream>

using namespace std;

void swap1(int *, int *);
void swap2(int &, int &);

int main()
{
    int a, b;
    a = 1, b = 2;
    swap1(&a, &b);
    cout << a << " " << b << endl;

    a = 1, b = 2;
    swap2(a, b);
    cout << a << " " << b << endl;
}

void swap1(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void swap2(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}