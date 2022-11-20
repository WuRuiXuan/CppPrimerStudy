#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::cin;

int main()
{
    string line;
    // 每次读入一整行，直至到达文件末尾
    while (getline(cin, line))
        cout << line << endl;
    return 0;
}