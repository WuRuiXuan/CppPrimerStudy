#include <iostream>
#include <typeinfo>

using namespace std;

class Base { /* ...*/ };

class Derived: public Base { /* ...*/ };

int main()
{
    int arr[10];
    Derived d;
    Base *p = &d;

    // name 返回一个 C 风格字符串，表示类型名字的可打印形式，因系统而异
    cout << typeid(42).name() << endl;
    cout << typeid(arr).name() << endl;
    cout << typeid(string).name() << endl;
    cout << typeid(p).name() << endl;
    cout << typeid(*p).name() << endl;
}