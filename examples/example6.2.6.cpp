#include <iostream>
#include <string>

using namespace std;

class ErrCode
{
    private:
        int num = 0;

    public:
        ErrCode(int i)
        {
            num = i;
        }
        string msg()
        {
            if (num == 0)
            {
                return "success";
            }
            else
            {
                return "Input Error";
            }
        }
};

void error_msg(initializer_list<string>);
void error_msg(ErrCode, initializer_list<string>);

int main()
{
    string expected = "Hello";
    string actual = "Bye";
    if (expected != actual)
        error_msg({"functionX", expected, actual});
    else
        error_msg({"functionX", "okay"});

    if (expected != actual)
        error_msg(ErrCode(42), {"functionX", expected, actual});
    else
        error_msg(ErrCode(0), {"functionX", "okay"});
}

void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}

void error_msg(ErrCode e, initializer_list<string> il)
{
    cout << e.msg() << ": ";
    for (const auto &elem : il)
        cout << elem << " ";
    cout << endl;
}
