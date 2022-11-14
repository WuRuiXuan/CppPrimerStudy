#include <iostream>
#include <string>

using namespace std;

istream& read(istream&);

int main() {
    istream& is = read(cin);
    read(is);
}

istream& read(istream& is)
{
    string result;
    string str;
    // auto old_state = is.rdstate();
    is.clear();
    while (is >> str)
    {
        result += str;
    }
    cout << result << endl;
    // is.setstate(old_state);
    return is;
}