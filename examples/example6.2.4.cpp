#include <iostream>

using namespace std;

void print1(const char *);
void print2(const int *, const int *);
void print3(const int[], size_t);
void print4(int (&)[10]);
void print5(int (*)[10], int);

int main()
{
    char cstr1[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char cstr2[] = " World\n";
    print1(cstr1);
    print1(cstr2);

    int j[2] = {0, 1};
    print2(begin(j), end(j));
    print3(j, end(j) - begin(j));

    int k[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int (&arr)[10] = k;
    print4(arr);

    int matrix[][10] = {{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}};
    print5(matrix, 1);
}

void print1(const char *cp)
{
    if (cp)
        while (*cp)
            cout << *cp++;
}

void print2(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++ << endl;
}

void print3(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i) {
        cout << ia[i] << endl;
    }
}

void print4(int (&arr)[10])
{
    for (auto elem : arr)
        cout << elem << endl;
}

void print5(int (*matrix)[10], int rowSize)
{
    for (int i = 0; i < 10; ++i) {
        int *p = matrix[i];
        for (int j = 0; j < rowSize; ++j) {
            cout << *p++ << " ";
        }
    }
}