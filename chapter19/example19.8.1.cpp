
typedef unsigned int Bit;

class File {
    Bit mode: 2;        // mode 占 2 位
    Bit modified: 1;    // modified 占 1 位
    Bit prot_owner: 3;  // prot_owner 占 3 位
    Bit prot_group: 3;  // prot_group 占 3 位
    Bit prot_world: 3;  // prot_world 占 3 位
    public:
        // 文件类型以八进制的形式表示
        enum modes { READ = 01, WRITE = 02, EXECUTE = 03 };
        File& open(modes);
        void close();
        void write();
        bool isRead() const;
        void setWrite();
};

void File::write()
{
    modified = 1;
    // ...
}

void File::close()
{
    if (modified) {
        // ... 保存内容
    }
}

// 使用内置的运算符操作超过 1 位的位域
File& File::open(File::modes m)
{
    mode |= READ;               // 按默认方式设置 READ
    // 其他处理
    if (m & WRITE)              // 如果打开了 READ 和 WRITE
    // 按照读/写方式打开文件
    return *this;
}

inline bool File::isRead() const { return mode & READ; }
inline void File::setWrite() { mode |= WRITE; }