#include <iostream>
#include <string>

using namespace std;

int main()
{
    // 不断提示用户输入一对数，然后求其和
    string rsp; // 作为循环的条件，不能定义在 do 的内部
    do {
        cout << "please enter two values: ";
        int val1 = 0, val2 = 0;
        cin >> val1 >> val2;
        cout << "The sum of " << val1 << " and " << val2
            << " = " << val1 + val2 << "\n\n"
            << "More? Enter yes or no: ";
        cin >> rsp;
    } while (!rsp.empty() && rsp[0] != 'n');
}