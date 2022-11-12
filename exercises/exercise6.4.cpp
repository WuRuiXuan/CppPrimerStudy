#include <iostream>

using namespace std;

int fact(int);

int main()
{
    int val;
    cin >> val;
    cout << fact(val) << endl;
}

int fact(int val) {
    int result = 1;
    while (val > 1)
    {
        result *= val--;
    }
    return result;
}