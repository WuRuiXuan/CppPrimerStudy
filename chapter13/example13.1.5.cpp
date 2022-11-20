#include <iostream>

using namespace std;

class Sales_data {
    public:
        // 使用 = default 来显示地要求编译器生成合成的版本
        Sales_data() = default;                     // 默认构造函数
        Sales_data(const Sales_data&) = default;    // 拷贝构造函数
        Sales_data& operator=(const Sales_data&);   // 拷贝赋值运算符
        ~Sales_data() = default;                    // 析构函数
};

Sales_data& Sales_data::operator=(const Sales_data&) = default;

class NoCopy {
    public:
        // 使用 = delete 来通知编译器，不希望定义这些成员
        NoCopy() = default;
        NoCopy(const NoCopy&) = delete;              // 阻止拷贝
        NoCopy& operator=(const NoCopy&) = delete;   // 组织赋值
        ~NoCopy() = default;
};

class NoDtor {
    public:
        NoDtor() = default;
        ~NoDtor() = delete;     // 不能销毁 NoDtor 类型的对象
};

int main()
{
    // NoDtor nd; // 错误：NoDtor 的析构函数是删除的
    NoDtor *p = new NoDtor(); // 正确：但不能 delete p
    // delete p; // 错误：NoDtor 的析构函数是删除的
}