#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    string pattern = "(\\()?(\\d{3})?(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    regex r(pattern);
    string number = "lee (908) 555-1800";
    string fmt = "$2.$5.$7"; // 将号码格式改为 ddd.ddd.dddd
    cout << regex_replace(number, r, fmt) << endl;

    // 只输出输入序列中匹配的部分
    cout << regex_replace(number, r, fmt, regex_constants::format_no_copy) << endl;
}