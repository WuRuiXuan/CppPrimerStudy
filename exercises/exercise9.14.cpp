#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main()
{
    const char *c = "Hello World";
    list<const char *> list = {c};
    vector<string> v;
    v.assign(list.cbegin(), list.cend());
    for (string str : v)
        cout << str << " ";
    cout << endl;
}