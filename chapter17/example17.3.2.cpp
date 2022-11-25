#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    string test_str = "receipt freind theif receive";

    // 查找不在字符 c 之后的字符串 ei
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern, regex::icase);

    // sregex_iterator 反复调用 regex_search 来寻找文件中的所有匹配
    for (sregex_iterator it(test_str.begin(), test_str.end(), r), end_it;
            it != end_it; ++it)
            cout << it->str() << endl;
    cout << endl;

    for (sregex_iterator it(test_str.begin(), test_str.end(), r), end_it;
            it != end_it; ++it) {
            cout << it->str() << endl;
            // 调用 prefix/suffix 返回 ssub_match 对象
            cout << "prefix: " << it->prefix().str() << " ";
            cout << "suffix: " << it->suffix().str() << " ";
            cout << endl;
    }
}