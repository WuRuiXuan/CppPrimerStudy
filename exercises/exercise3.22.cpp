#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    string text("hello world!!!");
    for (auto it = text.begin(); !isspace(*it); it++)
        *it = toupper(*it);
    cout << text << endl;
}