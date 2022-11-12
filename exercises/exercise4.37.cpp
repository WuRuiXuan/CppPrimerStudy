#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    double d = 3.14;
    const string str = "hello";
    const string *ps = &str;
    char ch = 'c';
    char *pc = &ch;
    void *pv;

    pv = const_cast<void *>(reinterpret_cast<const void *>(ps));
    i = static_cast<int>(*pc);
    pv = static_cast<void *>(&d);
    pc = static_cast<char *>(pv);
}