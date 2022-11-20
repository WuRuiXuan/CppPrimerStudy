#include <iostream>

using namespace std;

class SmallInt {
    public:
        SmallInt(int i = 0): val(i)
        {
            if (i < 0 || i > 255)
                throw out_of_range("Bad SmallInt value");
        }
        // 显式的类型转换运算符：编译器不会自动执行这一类型转换
        explicit operator int() const { return val; }
        int getVal() const { return val; }
    private:
        size_t val;
};

int main()
{
    SmallInt si = 3;            // 正确：SmallInt 的构造函数不是显式的
    // si + 3;                  // 错误：此处需要隐式的类型转换，但类的运算符是显式的
    static_cast<int>(si) + 3;   // 正确：显式地请求类型转换

    /*
        显式的类型转换被隐式地执行的情况：
        1. if、while 及 do 语句的条件部分
        2. for 语句头的条件表达式
        3. 逻辑非运算符(!)、逻辑或运算符(||)、逻辑与运算符(&&)的运算对象
        4. 条件运算符(?:)的条件表达式
    */
}