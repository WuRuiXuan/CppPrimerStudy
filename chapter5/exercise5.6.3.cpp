#include <iostream>
#include <string>

using namespace std;

int main()
{
    try {
        double val1, val2;
        cin >> val1 >> val2;
        if (val2 == 0) {
            throw runtime_error("the second number must not be zero.");
        }
        cout << val1 / val2 << endl;
    } catch (runtime_error err) {
        cout << err.what() << "\n\n" << "Try again: ";
        string input;
        cin >> input;
        if (input[0] == 'y') {
            main();
        }
    }
}