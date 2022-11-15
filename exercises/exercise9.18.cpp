#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    string word;
    deque<string> dq;
    auto iter = dq.begin();
    while (cin >> word) {
        iter = dq.insert(iter, word);
    }
    for (string item : dq)
        cout << item << " ";
    cout << endl;
}