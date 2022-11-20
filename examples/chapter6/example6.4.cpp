#include <iostream>
#include <string>

using namespace std;

const string &shorterString(const string &, const string &);
string &shorterString(string &, string &);

int main()
{
    string str1 = "Hello";
    string str2 = "Bye";
    string &s1 = str1;
    string &s2 = str2;
    string &s3 = shorterString(s1, s2);
    cout << s3 << endl;
    s3 += " World";
    cout << s3 << endl;
}

const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

string &shorterString(string &s1, string &s2)
{
    auto &r = shorterString(const_cast<const string&>(s1), 
                            const_cast<const string&>(s2));
    return const_cast<string&>(r);
}