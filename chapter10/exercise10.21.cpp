#include <iostream>

using namespace std;

int main()
{
    int i = 10;
    auto f = [i] () mutable -> bool {
        bool flag;
        if (i > 0)
            flag = false;
        else 
            flag = true;
        while(i > 0)
            --i;
        return flag;
    };
    cout << f() << endl;
    cout << f() << endl;
}