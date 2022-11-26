
// 限定作用域的枚举类型
enum class open_modes { input, output, append };

// 不限定作用域的枚举类型
enum color { red, yellow, green };
enum { floatPrec = 6, doublePrec = 10, double_doublePrec = 10 };

// enum stoplight { red, yellow, green };           // 错误：重复定义了枚举成员
enum class peppers { red, yellow, green };          // 正确：枚举成员被隐藏了
color eyes = green;    // 正确
// peppers p = green;  // 错误

color hair = color::red;                            // 正确
peppers p2 = peppers::red;                          // 正确

enum class intTypes {
    charTyp = 8, shortTyp = 16, intTyp = 16,
    longTyp = 32, long_longTyp = 64
};

constexpr intTypes charbits = intTypes::charTyp;

// 指定 enum 成员的类型
enum longValues: unsigned long long {
    charTyp = 255, shortTyp = 65535, intTyp = 65535,
    longTyp = 4294967295UL, long_longTyp = 18446744073709551615ULL
};

int main() {
    // open_modes om = 2;               // 错误
    open_modes om = open_modes::input;  // 正确

    int i = color::red;                 // 正确：不限定作用域的枚举类型可以进行隐式转换
    // int j = peppers::red;            // 错误：限定作用域的枚举类型不能进行隐式转换

    // 不限定作用域的枚举类型，必须指定成员类型
    enum intValues: unsigned long long;
    // 限定作用域的枚举类型，使用默认成员类型 int
    enum class open_modes;
}