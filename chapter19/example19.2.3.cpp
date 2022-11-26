#include <typeinfo>

using namespace std;

class Base {
    friend bool operator==(const Base&, const Base&);
    public:
        // Base 的接口成员
    protected:
        virtual bool equal(const Base&) const;
        // Base 的数据成员和其他用于实现的成员
};

class Derived: public Base {
    public:
        // Derived 的其他接口成员
    protected:
        bool equal(const Base&) const;
        // Derived 的数据成员和其他用于实现的成员
};

bool operator==(const Base& lhs, const Base& rhs)
{
    // 如果 typeid 不相同，返回 false；否则虚调用 equal
    return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

bool Derived::equal(const Base& rhs) const
{
    // 调用 typeid 结果相同后才继续调用该函数，因此转换过程不会抛出异常
    auto r = dynamic_cast<const Derived&>(rhs);
    // 执行比较两个 Derived 对象的操作并返回结果
}

bool Base::equal(const Base& rhs) const
{
    // 执行比较 Base 对象的操作
}