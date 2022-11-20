#include <iostream>
#include <string>

using namespace std;

bool lengthCompare(const string &, const string &);

int main()
{
    bool (*pf)(const string &, const string &);
    // pf = lengthCompare;
    pf = &lengthCompare;

    bool b1 = pf("hello", "goodbye");
    bool b2 = (*pf)("hello", "goodbye");
    bool b3 = lengthCompare("hello", "goodbye");
}

bool lengthCompare(const string &s1, const string &s2)
{
    return s1.size() > s2.size();
}