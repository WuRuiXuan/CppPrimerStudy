#include <iostream>
#include <string>

using namespace std;

void print(const int[], size_t);
void print(string, size_t);

int main()
{
    int ia[]{1, 2, 3};
    size_t size = 3;
    print(ia, size);

    string word = "Hello";
    size_t threshold = 6;
    print(word, threshold);
}

void print(const int ia[], size_t size)
{
    #ifndef NDEBUG
        cerr << __func__ << ": array size is " << size << endl;
    #endif
}

void print(string word, size_t threshold)
{
    if (word.size() < threshold)
        cerr << "Error: " << __FILE__
            << " : in function " << __func__
            << " at line " << __LINE__ << endl
            << "       Compiled on " << __DATE__
            << " at " << __TIME__ << endl
            << "       Word read was \"" << word
            << "\": Length too short" << endl;
}