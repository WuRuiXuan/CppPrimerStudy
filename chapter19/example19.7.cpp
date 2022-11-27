
using namespace std;

int a, val;
void foo(int val)
{
    static int si;
    enum Loc { a = 1024, b };
    // Bar 是 foo 的局部类
    struct Bar
    {
        Loc locVal;                 // 正确：使用一个局部类型名
        int barVal;

        void fooBar(Loc l = a)      // 正确：默认实参是 Loc::a
        {
            // barVal = val;        // 错误：val 是 foo 的局部变量
            barVal = ::val;         // 正确：使用一个全局对象
            barVal = si;            // 正确：使用一个静态局部对象
            locVal = b;             // 正确：使用一个枚举成员
        }
    };   
}

// 嵌套的局部类
void foo2()
{
    class Bar {
        public:
            // 声明 Nested 类
            class Nested;
    };
    // 定义 Nested 类
    class Bar::Nested {

    };
}