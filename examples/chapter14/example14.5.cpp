#include <iostream>
#include "../resources/Sales_data.h"

using namespace std;

class StrVec {
    public:
        string& operator[](size_t n) { return elements[n]; }
        const string& operator[](size_t n) const { return elements[n]; }
        size_t size() const { return elements->size(); };
    private:
        string* elements;       // 指向数组首元素的指针
};

int main()
{
    StrVec svec;
    // 假设 svec 是一个 StrVec 对象
    const StrVec cvec = svec;       // 把 svec 的元素拷贝到 cvec 中
    // 如果 svec 中含有元素，对第一个元素运行 string 的 empty 函数
    if (svec.size() && svec[0].empty()) {
        svec[0] = "zero";               // 正确：下标运算符返回 string 的引用
        // cvec[0] = "Zip";             // 错误：对 cvec 取下标返回的是常量引用
    }
}