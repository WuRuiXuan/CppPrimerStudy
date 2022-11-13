#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Screen;

class Window_mgr {
    public:
        // 窗口中每个屏幕的编号
        using ScreenIndex = vector<Screen>::size_type;
        // 按照编号将指定的 Screen 重置为空白
        void clear(ScreenIndex);
    private:
        // 这个 Window_mgr 追踪的 Screen
        // 默认情况下，一个 Window_mgr 包含一个标准尺寸的空白 Screen
        vector<Screen> screens;
};

class Screen {
    // Window_mgr 的成员可以访问 Screen 类的私有部分
    friend class Window_mgr;
    // Window_mgr::clear 必须在 Screen 类之前被声明
    friend void Window_mgr::clear(ScreenIndex);
    // storeOn 的 ostream 版本能访问 Screen 对象的私有部分
    friend ostream& storeOn(ostream &, Screen &);
    public:
        typedef string::size_type pos;
        Screen() = default; // 因为 Screen 有另一个构造函数，所以本函数是必需的
        // cursor 被其类内初始化值初始化为 0
        Screen(pos ht, pos wd, char c): height(ht), width(wd), 
        contents(ht * wd, c) { }
        char get() const                       // 读取光标处的字符
            { return contents[cursor]; }       // 隐式内联
        inline char get(pos ht, pos wd) const; // 显示内联
        Screen &move(pos r, pos c);            // 能在之后被设为内联

        void some_member() const;

        Screen &set(char);
        Screen &set(pos, pos, char);
        
        Screen &display(ostream &os)
                    { do_display(os); return *this; }
        const Screen &display(ostream &os) const
                    { do_display(os); return *this; }
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        string contents;

        mutable size_t access_ctr; // 即使在一个 const 对象内也能被修改

        void do_display(ostream &os) const { os << contents; } // 该函数负责显示 Screen 的内容
};

inline Screen &Screen::move(pos r, pos c) // 可以在函数的定义处指定 inline
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const // 在类的内部声明成 inline
{
    pos row = r * width;
    return contents[row + c];
}

void Screen::some_member() const
{
    ++access_ctr; // 保存一个计数值，用于记录成员函数被调用的次数
    // 该成员需要完成的其他工作
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;
    return *this;
}

extern ostream& storeOn(ostream &, Screen &);
// extern BitMap& storeOn(BitMap &, Screen &);

void Window_mgr::clear(ScreenIndex i)
{
    // s 是一个 Screen 的引用，指向我们想清空的那个屏幕
    Screen &s = screens[i];
    // 将那个选定的 Screen 重置为空白
    s.contents = string(s.height * s.width, ' ');
}

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
}