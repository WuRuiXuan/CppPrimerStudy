#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    vector<string> v1;
    string str;
    while (cin >> str)
    {
        for (auto &s : str)
            s = toupper(s);
        v1.push_back(str);
    }
    for (auto s : v1)
        cout << s << endl;
}