#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <map>
#include <set>
#include <sstream>

using namespace std;

class TextQuery {
    public:
        using line_no = vector<string>::size_type;
        TextQuery(ifstream&);
        // 声明嵌套类
        class QueryResult;
        QueryResult query(const string&) const;
    private:
        shared_ptr<vector<string>> file; // 输入文件
        map<string, shared_ptr<set<line_no>>> wm; // 每个单词到它所在的行号的集合的映射
};

// 定义嵌套类
class TextQuery::QueryResult {
    // 位于类的作用域内，因此我们不必对 QueryResult 形参进行限定
    friend ostream& print(ostream&, const QueryResult&);
    public:
        // 嵌套类可以直接使用外层类的成员，无须对该成员的名字进行限定
        QueryResult(string, 
                    shared_ptr<set<line_no>>, 
                    shared_ptr<vector<string>>);
    private:
        string sought; // 查询单词
        shared_ptr<set<line_no>> lines; // 出现的行号
        shared_ptr<vector<string>> file; // 输入文件
        static int static_mem;
};

// 定义嵌套类构造函数
TextQuery::QueryResult::QueryResult(string s,
                                    shared_ptr<set<line_no>> p,
                                    shared_ptr<vector<string>> f):
        sought(s), lines(p), file(f) { }

// 定义嵌套类静态成员
int TextQuery::QueryResult::static_mem = 1024;

TextQuery::QueryResult TextQuery::query(const string& sought) const
{
    // 如果没有找到 sought 则返回 set 的指针
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}