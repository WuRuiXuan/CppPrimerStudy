#include <iostream>
#include <string>
#include <set>
#include "./example13.4.h"

using namespace std;

inline Message::Message(const string &str = ""): contents(str) {}

inline Message::Message(const Message &m): 
                contents(m.contents), folders(m.folders)
{
    add_to_folders(m);  // 将本消息添加到指向 m 的 Folder 中
}

inline Message& Message::operator=(const Message &rhs)
{
    // 通过先删除指针再插入它们来处理自赋值情况
    remove_from_folders();      // 更新已有 Folder
    contents = rhs.contents;    // 从 rhs 拷贝消息内容
    folders = rhs.folders;      // 从 rhs 拷贝 Folder 指针
    add_to_folders(rhs);        // 将本 Message 添加到那些 Folder 中
    return *this;
}

inline Message::~Message()
{
    remove_from_folders();
}

inline void Message::save(Folder& f)
{
    folders.insert(&f);     // 将给定 Folder 添加到我们的 Folder 列表中
    f.addMsg(this);         // 将本 Message 添加到 f 的 Message 集合中
}

inline void Message::remove(Folder& f)
{
    folders.erase(&f);      // 将给定 Folder 从我们的 Folder 列表中移除
    f.remMsg(this);         // 将本 Message 从 f 的 Message 集合中删除
}

// 将本 Message 添加到指向 m 的 Folder 中
inline void Message::add_to_folders(const Message& m)
{
    for (auto f : m.folders)    // 对每个包含 m 的 Folder
        f->addMsg(this);        // 向该 Folder 添加一个指向本 Message 的指针
}

// 从对应的 Folder 中删除本 Message
inline void Message::remove_from_folders()
{
    for (auto f : folders)      // 对 folders 中每个指针
        f->remMsg(this);        // 从该 Folder 中删除本 Message
}

inline void Message::addFldr(Folder *f)
{
    folders.insert(f);
}

inline void Message::remFldr(Folder *f)
{
    folders.erase(f);
}

inline void Message::move_folders(Message* m)
{
    folders = std::move(m->folders);    // 使用 set 的移动赋值运算符
    for (auto f : folders) {
        f->remMsg(m);                   // 从 Folder 中删除旧 Message
        f->addMsg(this);                // 将本 Message 添加到 Folder 中
    }
    m->folders.clear();                 // 确保销毁 m 是无害的
}

// 移动构造函数
inline Message::Message(Message &&m): contents(std::move(m.contents))
{
    move_folders(&m); // 移动 folders 并更新 Folder 指针
}

// 移动赋值运算符
inline Message& Message::operator=(Message&& rhs)
{
    if (this != &rhs) { // 直接检查自赋值情况
        remove_from_folders();
        contents = std::move(rhs.contents); // 移动赋值运算符
        move_folders(&rhs); // 重置 Folders 指向本 Message
    }
    return *this;
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;    // 在本例中严格来说并不需要，但这是一个好习惯
    // 将每个消息的指针从它（原来）所在 Folder 中删除
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    // 交换 contents 和 Folder 指针 set
    swap(lhs.folders, rhs.folders);     // 使用 swap(set&, set&)
    swap(lhs.contents, rhs.contents);   // swap(string&, string&)
    // 将每个 Message 的指针添加到它的（新）Folder 中
    for (auto f: lhs.folders)
        f->addMsg(&lhs);
    for (auto f: rhs.folders)
        f->addMsg(&rhs);
}

inline Folder::Folder(const string &str = ""): name(str) {}

inline Folder::Folder(const Folder& f): name(f.name), msgs(f.msgs)
{ 
    add_to_messages(f); 
}

inline Folder& Folder::operator=(const Folder& f)
{
    remove_from_messages();
    name = f.name;
    msgs = f.msgs;
    add_to_messages(f);
    return *this;
}

inline Folder::~Folder()
{
    remove_from_messages();
}

inline void Folder::save(Message& m)
{
    msgs.insert(&m);
    m.addFldr(this);
}

inline void Folder::remove(Message& m)
{
    msgs.erase(&m);
    m.remFldr(this);
}

inline void Folder::add_to_messages(const Folder& f)
{
    for (auto m : f.msgs)
        m->addFldr(this);
}

inline void Folder::remove_from_messages()
{
    for (auto m : msgs)
        m->remFldr(this);
}

inline void Folder::addMsg(Message *m)
{
    msgs.insert(m);
}

inline void Folder::remMsg(Message *m)
{
    msgs.erase(m);
}

inline void Message::debug_print()
{
    cout << "Message contents: " << contents << endl;
    cout << "Message folders: ";
    for (auto f : folders)
        cout << f->name << " ";
    cout << endl;
}

inline void Folder::debug_print()
{
    cout << "Folder name: " << name << endl;
    cout << "Folder messages: ";
    for (auto m : msgs)
        cout << m->contents << " ";
    cout << endl;
}

int main(int argc, const char * argv[])
{
    string s1("contents1");
    string s2("contents2");
    string s3("contents3");
 
    Message m1(s1);
    Message m2(s2);
    Message m3(s3);
 
    Folder f1("folder1");
    Folder f2("folder2");
 
    m1.save(f1);
    m1.save(f2);
    m2.save(f2);
    m3.save(f1);
 
    m1.debug_print();
    m2.debug_print();
    m3.debug_print();

    f1.debug_print();
    f2.debug_print();

    cout << endl;

    m1 = m2;
    m1.debug_print();

    cout << endl;

    swap(m1, m3);
    m1.debug_print();
    m3.debug_print();

    return 0;
}