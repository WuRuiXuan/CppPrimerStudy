#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str, result;
    if (cin >> str) {
        for (auto s : str) {
            if (!ispunct(s))
                result += s;
        }
    }
    cout << result << endl;
}