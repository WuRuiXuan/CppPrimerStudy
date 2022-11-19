#include <iostream>
#include <string>
#include <set>

using namespace std;

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);
    public:
        // folders 被隐式初始化为空集合
        explicit Message(const string &);
        // 拷贝控制成员，用来管理指向本 Message 的指针
        Message(const Message&);
        Message& operator=(const Message&);
        ~Message();
        // 从给定 Folder 集合中添加/删除本 Message
        void save(Folder&);
        void remove(Folder&);
        void debug_print();
        // 移动构造函数
        Message(Message&&);
        // 移动赋值运算符
        Message& operator=(Message&&);
    private:
        string contents;        // 实际消息文本
        set<Folder*> folders;   // 包含本 Message 的 Folder
        // 拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
        // 将本 Message 添加到指向参数的 Folder 中
        void add_to_folders(const Message&);
        // 从 folders 中的每个 Folder 中删除本 Message
        void remove_from_folders();
        void addFldr(Folder *f);
        void remFldr(Folder *f);
        // 从本 Message 移动 Folder 指针
        void move_folders(Message*);
};

class Folder {
    friend class Message;
    friend void swap(Message &lhs, Message &rhs);
    public:
        explicit Folder(const string &);
        Folder(const Folder&);
        Folder& operator=(const Folder&);
        ~Folder();
        void save(Message&);
        void remove(Message&);
        void debug_print();
    private:
        string name;
        set<Message*> msgs;
        void add_to_messages(const Folder&);
        void remove_from_messages();
        void addMsg(Message *m);
        void remMsg(Message *m);
};