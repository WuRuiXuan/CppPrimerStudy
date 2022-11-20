#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    vector<int> vec;
    istream_iterator<int> in_iter(cin); // 从 cin 读取 int
    istream_iterator<int> eof;      // istream 尾后迭代器
    while (in_iter != eof)              // 当有数据可供读取时
        // 后置递增运算读取流，返回迭代器的旧值
        // 解引用迭代器，获得从流读取的前一个值
        vec.push_back(*in_iter++);
    for (int i : vec)
        cout << i << " ";
    cout << endl;
    
    cin.clear();

    istream_iterator<int> in_iter2(cin), eof2;
    cout << accumulate(in_iter2, eof2, 0) << endl;
}