#include <iostream>

using namespace std;

int max(const int, const int *);

int main()
{
    int a = 1;
    int b = 2;
    int res = max(a, &b);
    cout << res << endl;
}

int max(const int num, const int *p)
{
    return num > *p ? num : *p;
}