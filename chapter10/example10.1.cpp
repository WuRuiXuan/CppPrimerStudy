#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int val = 42; // 我们将查找的值
    vector<int> vec{1, 2, 42, 4, 5};
    // 如果在 vec 中找到想要的元素，则返回结果指向它，否则返回结果为 vec.cend()
    auto result = find(vec.cbegin(), vec.cend(), val);
    // 报告结果
    cout << "The value " << val
        << (result == vec.end()
                ? " is not present" : " is present.") << endl;

    int ia[] = {27, 210, 12, 47, 109, 83};
    int val2 = 83;
    int *result2 = find(begin(ia), end(ia), val2);
    cout << *result2 << endl;
}