#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main()
{
    const char ca[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    const char *cp = ca;
    while (*cp)
    {
        cout << *cp << endl;
        ++cp;
    }
    cout << strlen(ca) << endl;
}