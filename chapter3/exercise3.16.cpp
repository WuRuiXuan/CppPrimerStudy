#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main()
{
    string str1 = "v1: ";
    vector<int> v1;
    for (auto i : v1)
        str1 += i;
    decltype(v1.size()) size1 = v1.size();
    cout << str1 << "\nsize1: " << size1 << endl;

    string str3 = "v3: ";
    vector<int> v3(10, 42);
    for (auto i : v3)
        str3 += i;
    decltype(v3.size()) size3 = v3.size();
    cout << str3 << "\nsize3: " << size3 << endl;
}