#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &, string::size_type);
ostream& print(ostream &, const string &, char);

int main()
{
    string s = "hello";
    vector<string> words{"a", "bb", "ccc"};
    int sz = 3;
    auto wc = find_if(words.begin(), words.end(), bind(check_size, _1, sz));
    for_each(wc, words.end(),
            [](const string &s){ cout << s << " "; });
    cout << endl;

    ostream &os(cout);
    for_each(words.begin(), words.end(), bind(print, ref(os), _1, ' '));
}

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

ostream& print(ostream &os, const string &s, char c)
{
    return os << s << c;
}