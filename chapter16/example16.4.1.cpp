#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

template <typename T> string debug_rep(const T& t)
{
    ostringstream ret;
    ret << t;
    return ret.str();
}

// 用来终止递归并打印最后一个元素的函数
// 此函数必须在可变参数版本的 print 定义之前声明
template <typename T> ostream& print(ostream& os, const T& t)
{
    return os << t; // 包中最后一个元素之后不打印分隔符
}

// 包中除了最后一个元素之外的其他元素都会调用这个版本的 print
template <typename T, typename... Args>
ostream& print(ostream& os, const T& t, const Args&... rest)
{
    os << t << ", ";                // 打印第一个实参
    return print(os, rest...);      // 递归调用，打印其他实参
}

// 在 print 调用中对每个实参调用 debug_rep
template <typename... Args>
ostream& errorMsg(ostream& os, const Args&... rest)
{
    // print(os, debug_rep(a1), debug_rep(a2), ..., debug_rep(an))
    return print(os, debug_rep(rest)...);
}

int main()
{
    int i = 0; double d = 3.14; string s = "how now brown cow";
    print(cout, i, s, 42);  // 最后一次递归调用非可变参数版本的 print
    cout << endl;

    string fcnName = "fcn";
    int num = 3;
    errorMsg(cerr, fcnName, num, "other");
}