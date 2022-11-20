#include <vector>
#include <string>

using std::vector;
using std::string;

int main()
{
    vector<int>::iterator it; // it 能读写 vector<int> 的元素
    string::iterator it2; // it2 能读写 string 对象中的字符
    vector<int>::const_iterator it3; // it3 只能读元素，不能写元素
    vector<int>::const_iterator it4; // it4 只能读字符，不能写字符
}