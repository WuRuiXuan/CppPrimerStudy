#include <string>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

int main()
{
    string a_str("aaa");
    string b_str("bbb");
    string c_str("ccc");
    vector<string> svec{a_str, b_str, c_str};
    // fp 指向 string 的 empty 函数
    auto fp = &string::empty;

    /**
     * 错误：要想通过成员指针调用函数，必须使用 ->* 运算符
     * 在 find_if 内部将执行以下代码：
     * if (fp(*it))
     */
    // find_if(svec.begin(), svec.end(), fp);
    
    /**
     * 使用 function 生成一个可调用对象
     * 在 find_if 内部将执行以下代码：
     * if (((*it).*p)())                // p 是 fcn 内部的一个指向成员函数的指针
     */
    function<bool (const string&)> fcn = &string::empty;
    find_if(svec.begin(), svec.end(), fcn);

    vector<string*> pvec{&a_str, &b_str, &c_str};
    function<bool (const string*)> pfcn = &string::empty;
    // pfcn 接受一个指向 string 的指针，然后使用 ->* 调用 empty
    find_if(pvec.begin(), pvec.end(), pfcn);

    /**
     * 使用 mem_fn 生成一个可调用对象
     * 无须显式地指定对象的类型
     * mem_fn 生成的可调用对象含有一对重载的函数调用运算符
     * 一个接受 string*，另一个接受 string&
     */
    find_if(svec.begin(), svec.end(), mem_fn(&string::empty));

    auto f = mem_fn(&string::empty);    // f 接受一个 string 或者 string*
    f(*svec.begin());       // 正确：传入一个 string 对象，f 使用 .* 调用 empty
    f(&svec[0]);            // 正确：传入一个 string 的指针，f 使用 ->* 调用 empty

    /**
     * 使用 bind 生成一个可调用对象
     * 选择范围中的每个 string，并将其 bind 到 empty 的第一个隐式实参上
     * 和 mem_fn 一样，生成的可调用对象的第一个实参既可以是 string*，也可以是 string&
     */
    auto it = find_if(svec.begin(), svec.end(), bind(&string::empty, _1));

    auto f2 = bind(&string::empty, _1);
    f2(*svec.begin());      // 正确：传入一个 string 对象，f 使用 .* 调用 empty
    f2(&svec[0]);           // 正确：传入一个 string 的指针，f 使用 ->* 调用 empty
}