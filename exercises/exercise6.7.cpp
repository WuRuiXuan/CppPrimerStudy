#include <iostream>

using namespace std;

int func();

int main()
{
    for (int i = 1; i < 5; ++i)
    {
        cout << "func(" << i << ") : " << func() << endl;
    }
}

int func() {
    static int result;
    return result++ > 0 ? 1 : 0;
}