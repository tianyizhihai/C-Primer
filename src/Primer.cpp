#include "Primer.h"

#pragma region string流
void LJM_StringStream()
{
    string line, word;
    vector<PersonInfo> people;
    while (getline(cin, line))
    {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        while (record >> word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
        cout << info.name << endl;
        cout << info.phones.size() << endl;
        cout << "people.size():" << people.size() << endl;
        break;
    }
    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        cout << "name:" << entry.name << endl;
        for (const auto &nums : entry.phones)
        {
            cout << "nums:" << nums << endl;
        }
    }
}
#pragma endregion

#pragma region 泛型算法概述
// 消除重复单词
void elimDups(vector<string> &words)
{
    // 按字典顺序排序words，以便查找重复单??
    sort(words.begin(), words.end());
    // unique消除相邻的重复项
    // 排列在范围的前部,返回指向不重复区域之后一个位置的迭代??
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
void ToString(const vector<string> &words)
{
    for (const auto &word : words)
    {
        cout << word << " ";
    }
}
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    // stable_sort(words.begin(), words.end(), isShorter);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b)
                { return a.size() < b.size(); });
    auto wc = find_if(words.begin(), words.end(), [sz](const string &a)
                      { return a.size() >= sz; });
    auto count = words.end() - wc;
    cout<<"李佳明"<<sz<<"李佳明"<<count<<"李佳明"<<endl;
    for_each(wc, words.end(), [](const string &s)
             { cout << s << " "; });
    cout << endl;
}
#pragma endregion