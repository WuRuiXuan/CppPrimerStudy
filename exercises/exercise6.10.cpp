#include <iostream>

using namespace std;

void exchange(int &, int &);
void exchange2(int *, int *);

int main()
{
    int val1, val2;
    cin >> val1 >> val2;
    // exchange(val1, val2);
    // cout << "val1: " << val1 << " val2: " << val2 << endl;
    exchange2(&val1, &val2);
    cout << "val1: " << val1 << " val2: " << val2 << endl;
}

void exchange(int &val1, int &val2) {
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

void exchange2(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}