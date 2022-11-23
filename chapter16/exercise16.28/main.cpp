#include <iostream>
#include <string>
#include "shared_pointer.h"
#include "unique_pointer.h"

using namespace std;

int main()
{
    auto foo = cp5::SharedPointer<int>(new int(42));
    auto bar(foo);
    cout << *foo << endl;
    cout << foo.use_count() << endl;

    cp5::SharedPointer<string> string_ptr(new string("Yue"));
    cout << *string_ptr << endl;
    cout << string_ptr->size() << endl;

    UniquePointer<string, DebugDelete> string_uptr(new string("Wu"), DebugDelete());
    cout << *string_uptr << endl;
    cout << string_uptr->size() << endl;

    return 0;
}
