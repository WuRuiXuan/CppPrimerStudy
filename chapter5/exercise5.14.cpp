#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> v;
    string str;
    while (cin >> str)
    {
        v.push_back(str);
    }
    auto beg = v.begin();
    int index = 0;
    int cnt = 0;
    int times = 1;
    string temp = *beg;
    while (beg != v.end())
    {
        cout << "excute " << times << " times \n";
        if (*beg != temp) {
            int i = 1;
            for (; index + i < v.size() && v[index + i] == *beg; ++i)
            ;
            if (i > cnt) {
                temp = *beg;
                cnt = i;
            }
            beg += i;
            index += i;
        }
        else {
            cnt++;
            index++;
            beg++;
        }
        times++;
    }
    if (cnt > 1) {
        cout << temp << " appear " << cnt << " times." << endl;
    }
    else {
        cout << "There is no word that appeared continually." << endl;
    }
}