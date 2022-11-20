#include <iostream>
#include <vector>

int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);

using namespace std;
using F = int(int, int);

int main()
{
    vector<F *> v{add, subtract, multiply, divide};
    // vector<F *> v{&add, &subtract, &multiply, &divide};
    for (auto func : v)
        cout << func(2, 1) << endl;
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}
