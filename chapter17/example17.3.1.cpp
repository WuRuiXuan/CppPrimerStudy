#include <iostream>
#include <regex>

using namespace std;

int main()
{
    string test_str = "receipt freind theif receive";

    // 查找不在字符 c 之后的字符串 ei
    string pattern("[^c]ei");
    /**
     * ECMAScript
     * [[:alpha:]] 匹配任意字母
     * + 匹配一个或多个
     * * 匹配零个或多个
     */
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern);
    // string 类型的输入序列
    smatch results;

    // 用 r 在 test_str 中查找与 pattern 匹配的子串
    if (regex_search(test_str, results, r)) // regex_search 找到匹配子串就返回 true
        cout << results.str() << endl;      // results 第一个匹配的子串

    /**
     * 一个或多个字母或数字字符后接一个 '.' 再接 "cpp" 或 "cxx" 或 "cc"
     * \\. 第一个反斜线去掉 C++ 语言中反斜线的特殊含义
     * \\. 第二个反斜线去掉 . 的特殊含义
     * icase 在匹配过程中忽略大小写
     */
    regex r2("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
    smatch results2;
    string filename;
    while (cin >> filename)
        if (regex_search(filename, results2, r2))
            cout << results2.str() << endl;

    try {
        // 错误：alnum 漏掉了 ]
        regex r3("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);
    } catch (regex_error e)
    {
        cout << e.what() << "\ncode: " << e.code() << endl;
    }
}