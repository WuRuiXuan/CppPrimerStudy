
// 可能出现在 C++ 头文件 <cstring> 中的链接指示
// 单语句链接指示
extern "C" size_t strlen(const char*);
// 复合语句链接指示
extern "C" {
    int strcmp(const char*, const char*);
    char* strcat(char*, const char*);
}

/**
 * 声明可以应用于整个头文件
 * 头文件中的所有代码都被认为是由链接指示的语言编写的
 * 链接指示可以嵌套
 */
extern "C" {
    #include <string.h>         // 操作 C 风格字符串的 C 函数
}

extern "C" void (*pf1)(int); // pf1 指向一个 C 函数，该函数接受一个 int 返回 void
void (*pf2)(int);            // pf2 指向一个 C++ 函数
// pf1 = pf2;                // 错误：pf1 和 pf2 的类型不同

// 链接指示对整个声明都有效
extern "C" void f1(void(*)(int)); // f1 是一个 C 函数，它的形参是一个指向 C 函数的指针

// 如果希望给 C++ 函数传入一个指向 C 函数的指针，则必须使用类型别名
extern "C" typedef void FC(int);  // FC 是一个指向 C 函数的指针
void f2(FC*); // f2 是一个 C++ 函数，该函数的形参是指向 C 函数的指针

// 导出 C++ 函数到其他语言
extern "C" double calc(double dparm) { /* ...*/ } // calc 函数可以被 C 程序调用

// 错误：两个 extern "C" 函数的名字相同（C 语言不支持重载）
extern "C" void print(const char*);
extern "C" void print(int);

// 如果在一组重载函数中有一个是 C 函数，则其余的必定都是 C++ 函数
class SmallInt { /* ...*/ };
class BigNum { /* ...*/ };
// C 函数可以在 C 或 C++ 程序中调用
// C++ 函数重载了该函数，可以在 C++ 程序中调用
extern "C" double calc(double);
extern SmallInt calc(const SmallInt&);
extern BigNum calc(const BigNum&);