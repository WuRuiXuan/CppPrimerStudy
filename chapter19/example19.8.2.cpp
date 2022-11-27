
class Task { };

class Screen { };

// 不能使用合成的拷贝/移动构造函数及赋值运算符初始化 volatile 对象或从 volatile 对象赋值
// 必须自定义拷贝、移动、赋值等操作
class Foo {
    public:
        // 从一个 volatile 对象进行拷贝
        Foo(const volatile Foo&);
        // 将一个 volatile 对象赋值给一个非 volatile 对象
        Foo& operator=(volatile const Foo&);
        // 将一个 volatile 对象赋值给一个 volatile 对象
        Foo& operator=(volatile const Foo&) volatile;
};

int main()
{
    const size_t max_size = 100;

    volatile int display_register;      // 该 int 值可能发生改变
    volatile Task *curr_task;           // curr_task 指向一个 volatile 对象
    volatile int iax[max_size];         // iax 的每个元素都是 volatile
    volatile Screen bitmapBuf;          // bitmapBuf 的每个成员都是 volatile

    // 只有 volatile 的成员函数才能被 volatile 的对象调用

    volatile int v;                     // v 是一个 volatile int
    int *volatile vip;                  // vip 是一个 volatile 指针，它指向 int
    volatile int *ivp;                  // ivp 是一个指针，它指向一个 volatile int
    // vivp 是一个 volatile 指针，它指向一个 volatile int
    volatile int *volatile vivp;

    // int *ip = &v;                    // 错误：必须使用指向 volatile 的指针
    ivp = &v;                           // 正确
    vivp = &v;                          // 正确
}