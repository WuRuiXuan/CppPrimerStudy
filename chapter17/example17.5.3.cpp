#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // 以读写方式打开文件，并定位到文件尾
    fstream inOut("../resources/copyOut",
                    fstream::ate | fstream::in | fstream::out);
    if (!inOut) {
        cerr << "Unable to open file!" << endl;
        return EXIT_FAILURE;
    }
    // inOut 以 ate 模式打开，因此一开始就定义到其文件尾
    auto end_mark = inOut.tellg();          // 记住原文件尾位置
    inOut.seekg(0, fstream::beg);           // 重定位到文件开始
    size_t cnt = 0;                         // 字节数累加器
    string line;                            // 保存输入中的每行
    // 继续读取的条件：还未遇到错误且还在读取原数据
    while (inOut && inOut.tellg() != end_mark
           && getline(inOut, line)) {       // 且还可获取一行输入
        cnt += line.size() + 1;             // 加 1 表示换行符
        auto mark = inOut.tellg();          // 记住读取位置
        inOut.seekp(0, fstream::end);       // 将写标记移动到文件尾
        inOut << cnt;                       // 输出累计的长度
        // 如果不是最后一行，打印一个分隔符
        if (mark != end_mark) inOut << " ";
        inOut.seekg(mark);                  // 恢复读位置
    }
    inOut.seekp(0, fstream::end);           // 定位到文件尾
    inOut << "\n";                          // 在文件尾输出一个换行符
    return 0;
}