#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    string filename = "main.cpp";
    smatch results;
    /**
     * 子表达式
     * ([[:alnum:]]+)   表示文件名，匹配一个或多个字符的序列
     * (cpp|cxx|cc)     表示文件拓展名
     */
    regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$", regex::icase);
    if (regex_search(filename, results, r))
        // str(0) - main.cpp   str(1) - main   str(2) - cpp
        cout << results.str(1) << endl; // 打印第一个子表达式匹配的结果

    /**
     * 如果 pattern 有 n 个子表达式，则 smatch 包含 n + 1 个 ssub_match 元素
     * 位置 [0] 的元素表示整个匹配；元素 [1]...[n] 表示每个对应的子表达式
     */
}