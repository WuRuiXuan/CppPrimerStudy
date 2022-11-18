#include <string>
#include <list>
#include <vector>

using namespace std;

int main()
{
    // shared_ptr，可以指向 string
    shared_ptr<string> p1;
    // shared_ptr，可以指向 int 的 list
    shared_ptr<list<int>> p2;
    // 指向一个值为42的 int 的 shared_ptr
    shared_ptr<int> p3 = make_shared<int>(42);
    // p4 指向一个值为"9999999999"的 string
    shared_ptr<string> p4 = make_shared<string>(10, '9');
    // p5 指向一个值初始化的 int，即，值为0
    shared_ptr<int> p5 = make_shared<int>();
    // p6 指向一个动态分配的空 vector<string>
    auto p6 = make_shared<vector<string>>();

    auto p = make_shared<int>(42); // p 指向的对象只有 p 一个引用者
    auto q(p); // p 和 q 指向相同对象，此对象有两个引用者
}