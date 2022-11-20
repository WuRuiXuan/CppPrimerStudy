#include <iostream>
#include <string>

using namespace std;

typedef string str_arr[10];

void func0(str_arr *arr);
string (*func1())[10];
str_arr *func2();
void output(str_arr *);

int main()
{
    str_arr arr{};
    str_arr *arr0 = &arr;
    func0(arr0);
    output(arr0);

    // string (*arr1)[10] = func1();
}

void func0(str_arr *arr)
{
    string *p = *arr;
    for (auto beg = begin(*arr); beg != end(*arr); ++beg)
    {
        *p++ = "a";
    }
}

string (*func1())[10]
{
    string str_arr[10]{};
    string *p = str_arr;
    for (auto beg = begin(str_arr); beg != end(str_arr); ++beg)
        *p++ = "a";
    string (*q)[10] = &str_arr;
    return q;
}

str_arr *func2()
{
    string str_arr[10]{};
    string *p = str_arr;
    for (auto beg = begin(str_arr); beg != end(str_arr); ++beg)
        *p++ = "a";
    string (*q)[10] = &str_arr;
    return q;
}

void output(str_arr *arr)
{
    int i = 0;
    for (auto beg = begin(*arr); beg != end(*arr); ++i, ++beg)
        cout << (*arr)[i] << " ";
    cout << endl;
}