#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <map>
#include <set>
#include <sstream>

using namespace std;

class QueryResult; // 为了定义函数 query 的返回类型，这个定义是必需的

void runQueries(ifstream &);
string make_plural(size_t, const string &, const string &);
ostream &print(ostream&, const QueryResult &);

class TextQuery {
    public:
        using line_no = vector<string>::size_type;
        TextQuery(ifstream&);
        QueryResult query(const string&) const;
    private:
        shared_ptr<vector<string>> file; // 输入文件
        // 每个单词到它所在的行号的集合的映射
        map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult {
    friend ostream& print(ostream&, const QueryResult&);
    public:
        using line_no = vector<string>::size_type;
        QueryResult(string s, 
                    shared_ptr<set<line_no>> p,
                    shared_ptr<vector<string>> f);
    private:
        string sought; // 查询单词
        shared_ptr<set<line_no>> lines; // 出现的行号
        shared_ptr<vector<string>> file; // 输入文件
};

inline QueryResult::QueryResult(string s, 
                    shared_ptr<set<line_no>> p,
                    shared_ptr<vector<string>> f): sought(s), lines(p), file(f) {}

inline TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
    string text;
    while (getline(is, text)) {             // 对文件中每一行
        file->push_back(text);              // 保存此行文本
        int n = file->size() - 1;           // 当前行号
        istringstream line(text);           // 将行文本分解为单词
        string word;
        while (line >> word) {              // 对行中每个单词
            // 如果单词不在 wm 中，以之为下标在 wm 中添加一项
            auto &lines = wm[word];          // lines 是一个 shared_ptr
            if (!lines) // 在我们第一次遇到这个单词时，此指针为空
                lines.reset(new set<line_no>); // 分配一个新的 set
            lines->insert(n);               // 将此行号插入 set 中
        }
    }
}

inline QueryResult TextQuery::query(const string &sought) const
{
    // 如果未找到 sought，我们将返回一个指向此 set 的指针
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    // 使用 find 而不是下标运算符来查找单词，避免将单词添加到 wm 中
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file); // 未找到
    else 
        return QueryResult(sought, loc->second, file);
}

void runQueries(ifstream &infile)
{
    // infile 是一个 ifstream，指向我们要处理的文件
    TextQuery tq(infile); // 保存文件并建立查询 map
    // 与用户交互：提示用户输入要查询的单词，完成查询并打印结果
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        // 若遇到文件尾或用户输入了'q'时循环终止
        if (!(cin >> s) || s == "q") break;
        // 指向查询并打印结果
        print(cout, tq.query(s)) << endl;
    }
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

ostream &print(ostream& os, const QueryResult &qr)
{
    // 如果找到了单词，打印出现次数和所有出现的位置
    os << qr.sought << " occurs " << qr.lines->size() << " "
        << make_plural(qr.lines->size(), "time", "s") << endl;
    // 打印单词出现的每一行
    for (auto num : *qr.lines) // 对 set 中每个单词
        // 避免行号从 0 开始给用户带来的困惑
        os << "\t(line " << num + 1 << ") "
            << *(qr.file->begin() + num) << endl;
    return os;
}

int main()
{
    ifstream ifs("../resources/storyDataFile");
    runQueries(ifs);    // 将句子拆成单词保存时，单词会带上连着的标点符号
}