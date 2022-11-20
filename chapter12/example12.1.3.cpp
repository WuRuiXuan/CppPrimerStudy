#include <iostream>
#include <memory>

using namespace std;

shared_ptr<int> clone(int);

int main()
{
    shared_ptr<int> p = clone(1);
    cout << *p << endl;
}

shared_ptr<int> clone(int p) {
    return shared_ptr<int>(new int(p));
}