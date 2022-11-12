#include <iostream>
#include <string>

using namespace std;

const string &shorterString(const string &, const string &);

int main()
{
    string s1 = "Hello";
    string s2 = "Bye";
    cout << shorterString(s1, s2) << endl;
    bool some_failure;
    if (some_failure)
        return EXIT_FAILURE;
    else
        return EXIT_SUCCESS;
}

const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}