#include <iostream>
#include <memory>

using namespace std;

class StrVec {
    public:
        template <class... Args> void emplace_back(Args&&...);
    private:
        static allocator<string> alloc;
        void chk_n_alloc();
        string *first_free;
};

template <class... Args>
inline void StrVec::emplace_back(Args&&... args)
{
    chk_n_alloc(); // 如果需要的话重新分配 StrVec 内存空间
    alloc.construct(first_free++, forward<Args>(args)...);
}

int main()
{
    StrVec svec;
    svec.emplace_back(10, 'c'); // 将 cccccccccc 添加为新的元素
}