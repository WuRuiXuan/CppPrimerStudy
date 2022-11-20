#include <iostream>
#include <string>

using namespace std;

inline bool isShorter(const string &, const string &);
// constexpr bool isShorter(const string &, const string &);

int main()
{
    string s1 = "Hello";
    string s2 = "Bye";
    cout << isShorter(s1, s2) << endl;
}

inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

// constexpr bool isShorter(const string &s1, const string &s2)
// {
//     return s1.size() < s2.size();
// }