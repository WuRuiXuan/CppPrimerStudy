#ifndef UNIQUE_POINTER_H
#define UNIQUE_POINTER_H
#include <iostream>

template <typename, typename>
class UniquePointer;

template <typename T, typename D>
void swap(UniquePointer<T, D> &lhs, UniquePointer<T, D> &rhs);

class DebugDelete
{
    public:
        DebugDelete(std::ostream &o = std::cerr) : os(o) {}
        template <typename T>
        void operator()(T *p) const
        {
            os << "delete " << *p;
            delete p;
        }
    private:
        std::ostream &os;
};

/**
 *  @brief  std::unique_ptr like class template.
 */
template <typename T, typename D = DebugDelete>
class UniquePointer
{
    friend void swap<T, D>(UniquePointer<T, D> &lhs, UniquePointer<T, D> &rhs);

public:
    // preventing copy and assignment
    UniquePointer(const UniquePointer &) = delete;
    UniquePointer &operator=(const UniquePointer &) = delete;

    // default constructor and one taking T*
    UniquePointer() = default;
    explicit UniquePointer(T *up) : ptr(up) {}
    explicit UniquePointer(T *up, D de) : ptr(up), deleter(de) {}

    // move constructor
    UniquePointer(UniquePointer &&up) noexcept
        : ptr(up.ptr) { up.ptr = nullptr; }

    // move assignment
    UniquePointer &operator=(UniquePointer &&rhs) noexcept;

    // std::nullptr_t assignment
    UniquePointer &operator=(std::nullptr_t n) noexcept;

    // operator overloaded :  *  ->  bool
    T &operator*() const { return *ptr; }
    T *operator->() const { return &this->operator*(); }
    operator bool() const { return ptr ? true : false; }

    // return the underlying pointer
    T *get() const noexcept { return ptr; }

    // swap member using swap friend
    void swap(UniquePointer<T, D> &rhs) { ::swap(*this, rhs); }

    // free and make it point to nullptr or to p's pointee.
    void reset() noexcept
    {
        deleter(ptr);
        ptr = nullptr;
    }
    void reset(T *p) noexcept
    {
        deleter(ptr);
        ptr = p;
    }

    // return ptr and make ptr point to nullptr.
    T *release();

    ~UniquePointer()
    {
        deleter(ptr);
    }

private:
    T *ptr = nullptr;
    D deleter = D();
};

// swap
template <typename T, typename D>
inline void
swap(UniquePointer<T, D> &lhs, UniquePointer<T, D> &rhs)
{
    using std::swap;
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.deleter, rhs.deleter);
}

// move assignment
template <typename T, typename D>
inline UniquePointer<T, D> &
UniquePointer<T, D>::operator=(UniquePointer &&rhs) noexcept
{
    // prevent self-assignment
    if (this->ptr != rhs.ptr)
    {
        deleter(ptr);
        ptr = nullptr;
        ::swap(*this, rhs);
    }
    return *this;
}

// std::nullptr_t assignment
template <typename T, typename D>
inline UniquePointer<T, D> &
UniquePointer<T, D>::operator=(std::nullptr_t n) noexcept
{
    if (n == nullptr)
    {
        deleter(ptr);
        ptr = nullptr;
    }
    return *this;
}

// relinquish contrul by returnning ptr and making ptr point to nullptr.
template <typename T, typename D>
inline T *
UniquePointer<T, D>::release()
{
    T *ret = ptr;
    ptr = nullptr;
    return ret;
}
#endif // UNIQUE_POINTER_H
