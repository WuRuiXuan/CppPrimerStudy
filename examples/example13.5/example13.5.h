#include <string>
#include <memory>
#include <map>

using namespace std;

// 类 vector 类内存分配策略的简化实现
class StrVec {
    public:
        StrVec();
        StrVec(const StrVec&);
        // 移动构造函数
        StrVec(StrVec&&) noexcept;    // 移动操作不应抛出任何异常
        StrVec& operator=(const StrVec&);
        // 移动赋值运算符
        StrVec& operator=(StrVec&&) noexcept;
        ~StrVec();
        void push_back(const string&); // 拷贝元素
        void push_back(string&&);      // 移动元素
        size_t size() const;
        size_t capacity() const;
        string* begin() const;
        string* end() const;
    private:
        static allocator<string> alloc; // 分配元素
        // 被添加元素的函数所使用
        void chk_n_alloc();
        // 工具函数，被拷贝构造函数、赋值运算符和析构函数所使用
        pair<string*, string*> alloc_n_copy(const string*, const string*);
        void free();                    // 销毁元素并释放内存
        void reallocate();              // 获得更多内存并拷贝已有元素
        string *elements;               // 指向数组首元素的指针
        string *first_free;             // 指向数组第一个空闲元素的指针
        string *cap;                    // 指向数组尾后位置的指针
};

// 类的静态数据成员需要在类外定义
allocator<string> StrVec::alloc;