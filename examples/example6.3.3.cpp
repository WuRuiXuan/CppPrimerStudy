#include <iostream>

using namespace std;

typedef int arrT[10];
using arrT = int[10];

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

arrT* func(arrT*, int);
int (*func(int i))[10];
decltype(odd) *arrPtr(int);

int main()
{
    arrT a_arr{};
    arrT* b_arr = func(&a_arr, 1);
    for (auto beg = begin(*b_arr); beg != end(*b_arr); ++beg)
        cout << *beg << " ";
    cout << endl;
    
    arrT* c_arr = func(1);
    for (auto beg = begin(*c_arr); beg != end(*c_arr); ++beg)
        cout << *beg << " ";
    cout << endl;

    decltype(odd) *p_arr = arrPtr(1);
    for (auto beg = begin(*p_arr); beg != end(*p_arr); ++beg)
        cout << *beg << " ";
    cout << endl;
}

arrT* func(arrT* arr, int num)
{
    // int *p = *arr;
    for (int i = 0; i < 10; ++i)
        // *p++ = num;
        (*arr)[i] = num;
    return arr;
}

// auto func(int i) -> int(*)[10]
int (*func(int i))[10]
{
    int arr[10]{};
    int (*p2)[10] = &arr;
    int *p = *p2;
    for (int j = 0; j < 10; ++j)
        *p++ = i;
    return p2;
}

decltype(odd) *arrPtr(int i)
{
    return (i % 2) ? &odd : &even;
}