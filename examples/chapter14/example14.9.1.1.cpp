#include <iostream>

using namespace std;

class SmallInt {
    public:
        SmallInt(int i = 0): val(i)
        {
            if (i < 0 || i > 255)
                throw out_of_range("Bad SmallInt value");
        }
        // 类型转换运算符（必须是成员函数，不能指定返回类型，参数列表必须为空）
        operator int() const { return val; }
        int getVal() const { return val; }
    private:
        size_t val;
};

int main()
{
    SmallInt si;
    si = 4;     // 首先将 4 隐式地转换成 SmallInt，然后调用 SmallInt::operator=
    si + 3;     // 首先将 si 隐式地转换成 int，然后执行整数的加法
    cout << si.getVal() << endl;

    // 内置类型转换将 double 实参转换成 int
    si = 3.14;              // 调用 SmallInt(int) 构造函数
    // SmallInt 的类型转换运算符将 si 转换成 int
    si + 3.14;              // 内置类型转换将所得的 int 继续转换成 double
}