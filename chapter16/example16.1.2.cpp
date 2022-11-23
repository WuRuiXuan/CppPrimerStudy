#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <memory>

using namespace std;

// 前置声明，在 Blob 中声明友元所需要的
template <typename> class BlobPtr;
template <typename> class Blob; // 运算符 == 中的参数所需要的
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob {
    // 每个 Blob 实例将访问权限授予用相同类型实例化的 BlobPtr 和相等运算符
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
    friend T;   // 将访问权限授予用来实例化 Blob 的类型
    public:
        typedef T value_type;
        typedef typename vector<T>::size_type size_type;
        // 构造函数
        Blob();
        Blob(initializer_list<T> il);
        // Blob 中的元素数目
        size_type size() const { return data->size(); }
        bool empty() const { return data->empty(); }
        // 添加和删除元素
        void push_back(const T& t) { data->push_back(t); }
        // 移动版本
        void push_back(const T&& t) { data->push_back(std::move(t)); }
        void pop_back();
        // 元素访问
        T& back();
        T& operator[](size_type i);
    private:
        shared_ptr<vector<T>> data;
        // 若 data[i] 无效，则抛出 msg
        void check(size_type i, const string& msg) const;
};

template <typename T> void Blob<T>::check(size_type i, const string& msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

template <typename T> T& Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T> T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T> void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T> Blob<T>::Blob(): data(make_shared<vector<T>>()) { }

template <typename T> Blob<T>::Blob(initializer_list<T> il):
                                    data(make_shared<vector<T>>(il)) { }

template <typename T> class BlobPtr {
    public:
        BlobPtr(): curr(0) { }
        BlobPtr(Blob<T>& a, size_t sz = 0):
                wptr(a.data), curr(sz) { }
        T& operator*() const
        {
            auto p = check(curr, "dereference past end");
            return (*p)[curr]; // (*p) 为本对象指向的 vector
        }
        /**
         * 简化：BlobPtr<T>& operator++();
         * 当我们处于一个类模板的作用域中时，编译器处理模板自身引用时，
         * 就好像我们已经提供了与模板参数匹配的实参一样
         */
        // 前置运算符
        BlobPtr& operator++();
        BlobPtr& operator--();
        // 后置运算符
        BlobPtr operator++(int);
        BlobPtr operator--(int);
    private:
        // 若检查成功，check 返回一个指向 vector 的 shared_ptr
        shared_ptr<vector<T>> check(size_t, const string&) const;
        // 保存一个 weak_ptr，表示底层 vector 可能被销毁
        weak_ptr<vector<T>> wptr;
        size_t curr; // 数组中的当前位置
};

/**
 * 简化：BlobPtr<T> ret = *this;
 * 如果不提供模板实参，则编译器将假定我们使用的类型与成员实例化所用类型一致
 */
template <typename T> BlobPtr<T> BlobPtr<T>::operator++(int)
{
    // 此处无须检查；调用前置递增时会进行检查
    BlobPtr ret = *this;    // 保存当前值
    ++*this;                // 前置 ++ 检查递增是否合法
    return ret;             // 返回保存的状态
}

int main()
{
    Blob<int> squares = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (size_t i = 0; i != squares.size(); ++i)
        squares[i] = i * i; // 实例化 Blob<int>::operator[](size_t)
    for (size_t i = 0; i != squares.size(); ++i)
        cout << squares[i] << " ";
    cout << endl;
}