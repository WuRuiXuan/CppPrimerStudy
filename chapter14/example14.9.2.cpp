
struct B;
struct A
{
    A() = default;
    A(const B&);        // 把一个 B 转换成 A

    // 最好不要创建两个转换源都是算术类型的类型转换
    A(int = 0);
    A(double);
    // 最好不要创建两个转换对象都是算术类型的类型转换
    operator int() const;
    operator double() const;
};

struct B
{
    operator A() const; // 也是把一个 B 转换成 A
};

A f(const A&);
void f2(long double);

struct C
{
    C(int);
};

struct D
{
    D(int);
};

void manip(const C&);
void manip(const D&);

struct E
{
    E(double);
};

void manip2(const C&);
void manip2(const E&);

int main()
{
    B b;
    // A a = f(b);             // 二义性错误
    A a1 = f(b.operator A());  // 正确：使用 B 的类型转换运算符
    A a2 = f(A(b));            // 正确：使用 A 的构造函数

    A a(0);
    // f2(a);                   // 二义性错误

    long lg;
    // A a3(lg);                // 二义性错误

    short s = 42;               // 把 short 提升成 int 优于把 short 转换成 double
    A a4(s);                    // 使用 A::A(int)

    // manip(10);               // 二义性错误
    manip(C(10));               // 正确：调用 manip(const C&)

    // manip2(10);              // 二义性错误
}
