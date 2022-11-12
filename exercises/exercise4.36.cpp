#include <iostream>

using namespace std;

int main()
{
    int i = 2;
    double d = 3.14;
    // cout << (i *= d, i) << endl;
    cout << (i *= static_cast<int>(d), i) << endl;
}