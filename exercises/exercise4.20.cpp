#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

int main() {
    vector<string> vec = {"a", "b", "c"};
    vector<string>::iterator iter = vec.begin();
    cout << *iter++ << endl;
    // cout << (*iter)++ << endl;
    // cout << *iter.empty() << endl;
    cout << iter->empty() << endl;
    // cout << ++*iter << endl;
    cout << iter++->empty() << endl;
}