#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    // boolalpha 后续打印 bool 值都会打印 true 或 false 而非 1 或 0
    cout << "default bool values: " << true << " " << false << endl;
    cout << "alpha bool values: " << boolalpha << true << " " << false << endl;
    // noboolalpha 恢复 cout 打印 bool 格式到初始状态
    cout << boolalpha << true << " " << noboolalpha << true << endl;
    cout << endl;

    /**
     * 默认十进制
     * oct 八进制
     * hex 十六进制
     * dec 十进制
     * 只影响整型
     */
    cout << showbase;   // 打印整型值时显式进制
    cout << "default: " << 20 << " " << 1024 << endl;
    cout << "octal: " << oct << 20 << " " << 1024 << endl;
    cout << "hex: " << hex << 20 << " " << 1024 << endl;
    cout << "decimal: " << dec << 20 << " " << 1024 << endl;
    cout << noshowbase; // 恢复流状态

    // uppercase 字母以大写打印
    cout << uppercase << showbase << hex
         << "printed in hex: " << 20 << " " << 1024
         << nouppercase << noshowbase << dec << endl;
    cout << endl;

    // cout.precision 返回打印精度
    cout << "Precision: " << cout.precision()
         << ", Value: " << sqrt(2.0) << endl;
    // 将打印精度设置为 12 位数字（总位数）
    cout.precision(12);
    cout << "Precision: " << cout.precision()
         << ", Value: " << sqrt(2.0) << endl;

    // 在执行 scientific、fixed 或 hexfloat 后，精度值控制的是小数点后面的数字位数
    cout << "default: " << 100 * sqrt(2.0) << endl;
    cout << "scientific: " << scientific << 100 * sqrt(2.0) << endl;
    cout << "fixed: " << fixed << 100 * sqrt(2.0) << endl;
    cout << "hex: " << hexfloat << 100 * sqrt(2.0) << endl;
    cout << "use default: " << defaultfloat << 100 * sqrt(2.0) << endl;
    cout << endl;

    // showpoint 打印小数点
    cout << 10.0 << endl; // 打印 10
    cout << showpoint << 10.0 << noshowpoint << endl; // 打印 10.0000
    cout << endl;

    /**
     * 输出补白
     * setw 下一个值输出的最小长度
     * left 左对齐输出
     * right 右对齐输出（默认）
     * internal 左对齐符号，右对齐值，中间用空格填满
     * setfill 指定一个字符替代空格来补白输出
     */
    int i = -16;
    cout << "i: " << setw(12) << i << " next col" << endl;
    cout << "i: " << left << setw(12) << i << " next col" << endl;
    cout << "i: " << right << setw(12) << i << " next col" << endl;
    cout << "i: " << internal << setw(12) << i << " next col" << endl;
    cout << "i: " << setfill('#') << setw(12) << i << " next col" << endl 
         << setfill(' ');

    // 设置 cin 读取空白字符
    cin >> noskipws;
    char ch;
    while (cin >> ch)
    {
        cout << ch;
    }
    cin >> skipws; // 将 cin 恢复到默认状态，不读取空白字符
}