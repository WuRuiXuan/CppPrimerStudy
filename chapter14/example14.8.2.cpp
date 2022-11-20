#include <functional>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    plus<int> intAdd;           // 可执行 int 加法的函数对
    negate<int> intNegate;      // 可对 int 值取反的函数对象
    // 使用 intAdd::operator(int, int) 求 10 和 20 的和
    int sum = intAdd(10, 20);           // 等价于 sum = 30
    sum = intNegate(intAdd(10, 20));    // 等价于 sum = 30
    // 使用 intNegate::operator(int) 生成 -10
    // 然后将 -10 作为 intAdd::operator(int, int) 的第二个参数
    sum = intAdd(10, intNegate(10));    // sum = 0

    vector<string> svec{"aaa", "bbb", "ccc"};
    // 传入一个临时的函数对象用于执行两个 string 对象的 > 比较运算
    sort(svec.begin(), svec.end(), greater<string>());

    vector<string*> nameTable;              // 指针的 vector
    // 比较指针的内存地址来 sort 指针的 vector
    // 错误：nameTable 中的指针彼此之间没有关系，所以 < 将产生未定义的行为
    sort(nameTable.begin(), nameTable.end(),
        [](string *a, string *b) { return a < b; });
    // 正确：标准库规定指针的 less 是定义良好的
    sort(nameTable.begin(), nameTable.end(), less<string*>());
}