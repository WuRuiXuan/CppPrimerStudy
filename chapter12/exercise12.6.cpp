#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

vector<string> *factory();
void input(vector<string> &);
void print(vector<string> &);

int main()
{
    vector<string> *p = factory();
    input(*p);
    print(*p);
    delete p;
}

vector<string> *factory()
{
    vector<string> *p = new vector<string>({"a", "b", "c"});
    return p;
}

shared_ptr<vector<string>> factory2()
{
    shared_ptr<vector<string>> p = make_shared<vector<string>>();
    return p;
}

void input(vector<string> &v)
{
    string word;
    while (cin >> word)
    {
        v.push_back(word);
    }
}

void print(vector<string> &v)
{
    for (string str : v)
        cout << str << endl;
}