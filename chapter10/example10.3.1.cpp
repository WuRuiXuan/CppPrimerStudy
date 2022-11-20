#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void biggies(vector<string> &, vector<string>::size_type);
void elimDups(vector<string> &);
bool isShorter(const string &, const string &);
string make_plural(size_t, const string &, const string &);

int main()
{
    vector<string> words{"the", "quick", "red", "fox", "jumps", 
                        "over", "the", "slow", "red", "turtle"};
    biggies(words, 5);
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words); // 将 words 按字典序重排，并消除重复单词
    // 按长度重新排序，长度相同的单词维持字典序
    stable_sort(words.begin(), words.end(),
                [](const string &a, const string &b)
                    { return a.size() < b.size(); });
    // 获取一个迭代器，指向第一个满足 size() >= sz 的元素
    auto wc = find_if(words.begin(), words.end(),
                [sz](const string &a)
                    { return a.size() >= sz; });
    // 计算满足 size >= sz 的元素的数目
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
        << " of length " << sz << " or longer" << endl;
    // 打印长度大于等于给定值的单词，每个单词后面接一个空格
    for_each(wc, words.end(),
            [](const string &s){ cout << s << " "; });
    cout << endl;
}

void elimDups(vector<string> &words)
{
    // 按字典序排序 words，以便查找重复单词
    sort(words.begin(), words.end());
    // unique 重排输入范围，使得每个单词只出现一次
    // 排列在范围的前部，返回指向不重复区域之后一个位置的迭代器
    auto end_unique = unique(words.begin(), words.end());
    // 使用向量操作 erase 删除重复单词
    words.erase(end_unique, words.end());
}

// 比较函数，用来按长度排序单词
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}