#include "Primer.h"

#pragma region string流(未完善)
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
//消除重复单词
void elimDups(vector<string>& words)
{
    //按字典顺序排序words，以便查找重复单词
    sort(words.begin(),words.end());
    //unique消除相邻的重复项
    //排列在范围的前部,返回指向不重复区域之后一个位置的迭代器
    auto end_unique = unique(words.begin(),words.end());
    words.erase(end_unique,words.end());
}

#pragma endregion