#include <iostream>

using std::cout;
using std::endl;
using std::begin;
using std::end;
using int_array = int[4];

// typedef int int_array[4];

int main()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    cout << "first:\n";
    for (auto p = ia; p != ia + 3; ++p) {
        for (auto q = *p; q != *p + 4; ++q)
            cout << *q << ' ';
        cout << endl;
    }
    cout << "second:\n";
    for (auto p = begin(ia); p != end(ia); ++p) {
        for (auto q = begin(*p); q != end(*p); ++q)
            cout << *q << ' ';
        cout << endl;
    }
    cout << "third:\n";
    for (int (*p)[4] = ia; p != ia + 3; ++p) {
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << ' ';
        cout << endl;
    }
    cout << "fourth:\n";
    for (int_array *p = ia; p != ia + 3; ++p) {
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << " ";
        cout << endl;
    }
    cout << "fifth:\n";
    for (int_array &row : ia) {
        for (int &col : row)
            cout << col << " ";
        cout << endl;
    }
    cout << "sixth:\n";
    for (auto &row : ia) {
        for (auto &col : row)
            cout << col << " ";
        cout << endl;
    }
    cout << "seventh:\n";
    for (int (&row)[4] : ia) {
        for (int &col : row)
            cout << col << " ";
        cout << endl;
    }
}