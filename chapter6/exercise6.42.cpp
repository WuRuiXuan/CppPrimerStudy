#include <iostream>
#include <string>

using namespace std;

int ff(int a, int b = 0, int c = 0);
// char *init(int ht = 24, int wd, char background);

string ed;
string make_plural(size_t, const string &, const string & = ed);

int main()
{
    ed = "s";
    cout << make_plural(1, "success") << endl;
    cout << make_plural(2, "success") << endl;
    cout << make_plural(1, "failure") << endl;
    cout << make_plural(2, "failure") << endl;
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}