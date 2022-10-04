#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    string input, total;
    while (cin >> input) {
        total = total + " " + input;
    }
    cout << total << endl;
}