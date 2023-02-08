#include <iostream>

int main()
{
    extern int i;   // 声明 i 而非定义 i
    int j;          // 声明并定义 j

    // extern double pi = 3.1416; // 错误：不再是声明而是定义
    // 变量能且只能被定义一次，但是可以被多次声明
}