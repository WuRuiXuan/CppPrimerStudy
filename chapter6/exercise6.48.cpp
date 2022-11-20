#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main()
{
    string s;
    string sought = "\n";
    while (cin >> s && s != sought) { }
    assert(cin);
}