#include <iostream>
#include <string>
#include <memory>
#include <map>
#include "./example13.5.h"

using namespace std;

inline StrVec::StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}

inline size_t StrVec::size() const { return first_free - elements; }

inline size_t StrVec::capacity() const { return cap - elements; }

inline string* StrVec::begin() const { return elements; }

inline string* StrVec::end() const { return first_free; }

inline void StrVec::chk_n_alloc() { if (size() == capacity()) reallocate(); }

inline void StrVec::push_back(const string& s)
{
    chk_n_alloc(); // 确保有空间容纳新元素
    // 在 first_free 指向的元素中构造 s 的副本
    alloc.construct(first_free++, s);
}

inline void StrVec::push_back(string&& s)
{
    chk_n_alloc(); // 如果需要的话为 StrVec 重新分配内存
    // 由于 move 返回一个右值引用，因此，会使用 string 的移动构造函数来构造新元素
    alloc.construct(first_free++, std::move(s));
}

inline pair<string*, string*> 
            StrVec::alloc_n_copy(const string* b, const string* e) {
    // 分配空间保存给定范围中的元素
    auto data = alloc.allocate(e - b);
    // 初始化并返回一个 pair，该 pair 由 data 和 uninitialized_copy 的返回值构成
    return { data, uninitialized_copy(b, e, data) };
}

inline void StrVec::free()
{
    // 不能传递给 deallocate 一个空指针，如果 elements 为0，函数什么也不做
    if (elements) {
        // 逆序销毁旧元素
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

inline StrVec::StrVec(const StrVec &s)
{
    // 调用 alloc_n_copy 分配空间以容纳与 s 中一样多的元素
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

inline StrVec::~StrVec() { free(); }

inline StrVec &StrVec::operator=(const StrVec &rhs)
{
    // 调用 alloc_n_copy 分配内存，大小与 rhs 中元素占用空间一样多
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

// inline void StrVec::reallocate()
// {
//     // 我们将分配当前大小两倍的内存空间
//     auto newcapacity = size() ? 2 * size() : 1;
//     // 分配新内存
//     auto newdata = alloc.allocate(newcapacity);
//     // 将数据从旧内存移动到新内存
//     auto dest = newdata;    // 指向新数组中下一个空闲位置
//     auto elem = elements;   // 指向旧数组中下一个元素
//     for (size_t i = 0; i != size(); ++i)
//         alloc.construct(dest++, std::move(*elem++));
//     free(); // 一旦我们移动完元素就释放旧内存空间
//     // 更新我们的数据结构，执行新元素
//     elements = newdata;
//     first_free = dest;
//     cap = elements + newcapacity;
// }

inline void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);
    // 移动迭代器
    auto last = uninitialized_copy(make_move_iterator(begin()),
                                    make_move_iterator(end()),
                                    first);
    free();
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}

// 移动构造函数
inline StrVec::StrVec(StrVec&& s) noexcept
    // 成员初始化器接管 s 中的资源
    : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    // 令 s 进入这样的状态————对其运行析构函数是安全的
    s.elements = s.first_free = s.cap = nullptr;
}

// 移动赋值运算符
inline StrVec& StrVec::operator=(StrVec&& rhs) noexcept
{
    // 直接检测自赋值
    if (this != &rhs) {
        free();                  // 释放已有元素
        elements = rhs.elements; // 从 rhs 接管资源
        first_free = rhs.first_free;
        cap = rhs.cap;
        // 将 rhs 置于可析构状态
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

int main()
{
    StrVec vec1;
    vec1.push_back("a");
    vec1.push_back("b");
    vec1.push_back("c");
    cout << vec1.size() << endl;
    cout << vec1.capacity() << endl;
    cout << *vec1.begin() << endl;
    cout << *(vec1.end() - 1) << endl;

    cout << endl;

    StrVec vec2 = vec1;
    cout << vec2.size() << endl;
    cout << vec2.capacity() << endl;
    cout << *vec2.begin() << endl;
    cout << *(vec2.end() - 1) << endl;

    StrVec vec;
    string s = "some string or another";
    vec.push_back(s);       // 调用 push_back(const string&)
    vec.push_back("done");  // 调用 push_back(string&&)
}