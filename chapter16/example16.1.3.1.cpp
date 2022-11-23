#include <iostream>
#include <map>

using namespace std;

// 为类模板定义一个类型别名
template <typename T> using twin = pair<T, T>;

template <typename T> using partNo = pair<T, unsigned>;

template <typename T> class Foo {
    public:
        static size_t count() { return ctr; }
    private:
        static size_t ctr;
};

template <typename T> size_t Foo<T>::ctr = 0; // 定义并初始化 ctr

typedef double A;   // 被类型参数 A 隐藏
template <typename A, typename B> void f(A a, B b)
{
    A tmp = a;      // tmp 的类型为模板参数 A 的类型，而非 double
    // double B;    // 错误：重声明模板参数 B
}

// 错误：非法重用模板参数名 V
// template <typename V, typename V>

// 声明中的模板参数的名字不必与定义中相同（以下都是相同的函数模板）
template <typename T> T calc(const T&, const T&); // 声明
template <typename U> U calc(const U&, const U&); // 声明
template <typename Type> Type calc(const Type&, const Type&) { /* ... */ } // 定义

// typename T::value_type 显式地告诉编译器 value_type 是一个类型（不是 static 数据成员）
template <typename T> typename T::value_type top(const T& c)
{
    if (!c.empty())
        return c.back();
    else
        return typename T::value_type();
}

int main()
{
    twin<string> authors; // authors 是一个 pair<string, string>
    twin<int> win_loss; // win_loss 是一个 pair<int, int>
    twin<double> area;  // area 是一个 pair<double, double>

    partNo<string> books; // books 是一个 pair<string, unsigned>

    // 实例化 static 成员 Foo<string>::ctr 和 Foo<string>::count
    Foo<string> fs;
    // 所有三个对象共享相同的 Foo<int>::ctr 和 Foo<int>::count 成员
    Foo<int> fi1, fi2, fi3;
    
    Foo<int> fi;                    // 实例化 Foo<int> 类和 static 数据成员 ctr
    auto ct = Foo<int>::count();    // 实例化 Foo<int>::count
    ct = fi.count();                // 使用 Foo<int>::count
    // ct = Foo::count();           // 错误：使用哪个模板实例的 count ？
}