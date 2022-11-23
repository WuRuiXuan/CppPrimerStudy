#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <memory>

using namespace std;

/**
 * 显式实例化
 * extern 模板表示不会在本文件中实例化，而是在其他文件中有非 extern 声明和定义
 * 避免多个文件实例化相同模板引起的开销
 */
// extern template class Blob<string>;
// extern template int compare(const int&, const int&);


// 函数对象类，对给定指针执行 delete
class DebugDelete {
    public:
        DebugDelete(ostream& s = cerr): os(s) { }
        // 与任何函数模板相同，T 的类型由编译器推断
        template <typename T> void operator()(T *p) const
        {
            os << "deleting unique_ptr" << endl;
            delete p;
        }
    private:
        ostream& os;
};

// 类和成员各自有自己的、独立的模板参数
template <typename T> class Blob {
    public:
        template <typename It> Blob(It b, It e);
    private:
        shared_ptr<vector<T>> data;
};

// 必须同时为类模板和成员模板提供模板参数列表
template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e): data(make_shared<vector<T>>(b, e)) { }

int main()
{
    double* p = new double;
    DebugDelete d; // 可像 delete 表达式一样使用的对象
    d(p); // 调用 DebugDelete::operator()(double*)，释放 p
    int* ip = new int;
    // 在一个临时 DebugDelete 对象上调用 operator()(int*)
    DebugDelete()(ip);

    // 销毁 p 指向的对象
    // 实例化 DebugDelete::operator()<int>(int*)
    unique_ptr<int, DebugDelete> up(new int, DebugDelete());
    // 销毁 sp 指向的对象
    // 实例化 DebugDelete::operator()<string>(string*)
    unique_ptr<string, DebugDelete> usp(new string, DebugDelete());

    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<long> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<const char*> w = {"now", "is", "the", "time"};
    // 实例化 Blob<int> 类及接受两个 int* 参数的构造函数
    Blob<int> a1(begin(ia), end(ia));
    // 实例化 Blob<int> 类及接受两个 vector<long>::iterator 参数的构造函数
    Blob<int> a2(vi.begin(), vi.end());
    // 实例化 Blob<string> 类及接受两个 list<const char*>::iterator 参数的构造函数
    Blob<string> a3(w.begin(), w.end());
}