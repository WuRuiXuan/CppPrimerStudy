#include <iostream>

int main()
{
    bool b = 42;    // b 为真
    int i = b;      // i 的值为 1
    i = 3.14;       // i 的值为 3
    double pi = i;  // pi 的值为 3.0
    unsigned char c = -1; // 假设 char 占 8 比特，c 的值为 255
    signed char c2 = 256; // 假设 char 占 8 比特，c2 的值是未定义的
}