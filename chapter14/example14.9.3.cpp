#include <iostream>

class SmallInt {
    // 既提供了重载运算符
    friend SmallInt operator+(const SmallInt&, const SmallInt&);
    public:
        SmallInt(int = 0);
        // 又提供了算术类型的类型转换
        operator int() const { return val; }
    private:
        size_t val;
};

int main()
{
    SmallInt s1, s2;
    SmallInt s3 = s1 + s2;      // 使用重载的 operator+
    // 则会有重载运算符与内置运算符的二义性问题
    // int i = s3 + 0;          // 二义性错误（0 转成 SmallInt 或者 s3 转成 int）
}