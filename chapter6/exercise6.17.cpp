#include <iostream>
#include <string>

using namespace std;

bool hasUpperCase(const string &);
void changeToLowerCase(string &);

int main()
{
    string str = "Hello World";
    cout << hasUpperCase(str) << endl;
    changeToLowerCase(str);
    cout << str << endl;
}

bool hasUpperCase(const string &str) {
    for (decltype(str.size()) i = 0; i < str.size(); ++i) 
        if (isupper(str[i])) return true;
    return false;
}

void changeToLowerCase(string &str) {
    for (decltype(str.size()) i = 0; i < str.size(); ++i)
        str[i] = tolower(str[i]);
}