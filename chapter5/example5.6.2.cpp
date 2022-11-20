#include <iostream>
#include "../resources/Sales_item.h"

using namespace std;

int main()
{
    Sales_item item1, item2;
    while (cin >> item1 >> item2) {
        try {
            // 首先检查 item1 和 item2 是否表示同一种书籍
            if (item1.isbn() == item2.isbn()) {
                cout << "OK" << endl;
                break;
            }
            else {
                // 如果不是，代码抛出一个 runtime_error 异常
                throw runtime_error("Data must refer to same ISBN");
            }
        }
        catch (runtime_error err) {
            // 提醒用户两个 ISBN 必须一致，询问是否重新输入
            cout << err.what() << "\nTry Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break; // 跳出 while 循环
        }
    }
}