#include <string>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    vector<string> svec{"aaa", "bbb", "ccc"};
    // fp 指向 string 的 empty 函数
    auto fp = &string::empty;

    /**
     * 错误：要想通过成员指针调用函数，必须使用 ->* 运算符
     * 在 find_if 内部将执行以下代码：
     * if (fp(*it))
     */
    find_if(svec.begin(), svec.end(), fp);
    
    /**
     * 使用 function 生成一个可调用对象
     * 在 find_if 内部将执行以下代码：
     * if (((*it).*p)())                // p 是 fcn 内部的一个指向成员函数的指针
     */
    function<bool (const string&)> fcn = &string::empty;
    find_if(svec.begin(), svec.end(), fcn);

    vector<string*> pvec;
    function<bool (const string*)> pfcn = &string::empty;
    // pfcn 接受一个指向 string 的指针，然后使用 ->* 调用 empty
    find_if(pvec.begin(), pvec.end(), pfcn);
}