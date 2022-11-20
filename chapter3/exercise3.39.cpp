#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main()
{
    const char ca1[] = "abcde";
    const char ca2[] = "abcde";
    cout << strcmp(ca1, ca2) <<endl;
}