#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdarg.h>

using namespace std;

bool valid(string);
string format(string);
inline string format_string(const char*, va_list);
inline string format_string(const char*, ...);

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main(int argc, char const *argv[])
{
    string line, word;              // 分别保存来自输入的一行和单词
    vector<PersonInfo> people;      // 保存来自输入的所有记录
    // 逐行从输入读取数据，直至 cin 遇到文件尾（或其他错误）
    while (getline(cin, line)) {
        PersonInfo info;            // 创建一个保存此纪录数据的对象
        istringstream record(line); // 将记录绑定到刚读入的行
        record >> info.name;        // 读取名字
        while (record >> word)      // 读取电话号码
            info.phones.push_back(word); // 保持它们
        people.push_back(info);     // 将此纪录追加到 people 末尾
    }
    for (const auto &entry : people) { // 对 people 中每一项
        ostringstream formatted, badNums; // 每个循环步创建的对象
        for (const auto &nums : entry.phones) { // 对每个数
            if (!valid(nums)) {
                badNums << " " << nums; // 将数的字符串形式存入 badNums
            } else
                // 将格式化的字符串“写入” formatted
                formatted << " " << format(nums);
        }
        if (badNums.str().empty())          // 没有错误的数
            cout << entry.name << " "         // 打印名字
                << formatted.str() << endl; // 和格式化的数
        else // 否则，打印名字和错误的数
            cerr << "input error: " << entry.name
                << " invalid number(s) " << badNums.str() << endl;
    }
    return 0;
}

bool valid(string nums) {
    return nums.size() <= 11;
}

string format(string nums) {
    return format_string("numbers: %s", nums);
}

inline string format_string(const char* format, va_list args) {
    constexpr size_t oldlen = BUFSIZ;
    char buffer[oldlen];  // 默认栈上的缓冲区
    va_list argscopy;
    va_copy(argscopy, args);
    size_t newlen = vsnprintf(&buffer[0], oldlen, format, args) + 1;
    newlen++;  // 算上终止符'\0'
    if (newlen > oldlen) {  // 默认缓冲区不够大，从堆上分配
        vector<char> newbuffer(newlen);
        vsnprintf(newbuffer.data(), newlen, format, argscopy);
        return newbuffer.data();
    }
    return buffer;
}

inline string format_string(const char* format, ...) {
    va_list args;
    va_start(args, format);
    auto s = format_string(format, args);
    va_end(args);
    return s;
}