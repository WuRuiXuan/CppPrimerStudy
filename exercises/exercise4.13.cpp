#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int i; double d;
    d = i = 5;
    cout << "i " << i << " d " << d << endl;
    i = d = 3.5;
    cout << "i " << i << " d " << d << endl;
}