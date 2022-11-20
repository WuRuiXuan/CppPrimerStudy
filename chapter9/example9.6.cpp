#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> intStack; // 空栈
    // 填满栈
    for (size_t ix = 0; ix != 10; ++ix)
        intStack.push(ix);       // intStack 保存 0 到 9 十个数
    while (!intStack.empty()) {  // intStack 中有值就继续循环
        int value = intStack.top();
        cout << value << " ";
        // 使用栈顶值的代码
        intStack.pop(); // 弹出栈顶元素，继续循环
    }
    cout << endl;
}