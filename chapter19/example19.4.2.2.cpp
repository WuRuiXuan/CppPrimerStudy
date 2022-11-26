using namespace std;

class Screen {
    public:
        // Action 是一个指针，可以用任意一个光标移动函数对其赋值
        using Action = Screen& (Screen::*)();
        // 指定具体要移动的方向
        enum Directions { HOME, FORWARD, BACK, UP, DOWN };
        Screen& move(Directions);
        Screen& home();
        Screen& forward();
        Screen& back();
        Screen& up();
        Screen& down();
    private:
        static Action Menu[];           // 函数表
};

Screen& Screen::move(Directions cm)
{
    // 运行 this 对象中索引值为 cm 的元素
    return (this->*Menu[cm])();         // Menu[cm] 指向一个成员函数
}

Screen::Action Screen::Menu[] = { &Screen::home,
                                  &Screen::forward,
                                  &Screen::back,
                                  &Screen::up,
                                  &Screen::down
                                };

int main()
{
    Screen myScreen;
    myScreen.move(Screen::HOME);    // myScreen.home()
    myScreen.move(Screen::DOWN);    // myScreen.down()
}