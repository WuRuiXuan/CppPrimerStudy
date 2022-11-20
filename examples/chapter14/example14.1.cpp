#include <string>

using namespace std;

int main()
{
    string s = "world";
    // 正确：我们能把一个 const char* 加到一个 string 对象中
    string t = s + "!"; // s.operator+("!")
    // 如果 + 是 string 的成员，则产生错误
    string u = "hi" + s; // operator+("hi", s)
}