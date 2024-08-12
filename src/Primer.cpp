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
void biggies1(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    // stable_sort(words.begin(), words.end(), isShorter);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b)
                { return a.size() < b.size(); });
    auto wc = find_if(words.begin(), words.end(), [sz](const string &a)
                      { return a.size() >= sz; });
    auto count = words.end() - wc;
    cout << "长度大于等于" << sz << "的元素有" << count << "个" << endl;
    for_each(wc, words.end(), [](const string &s)
             { cout << s << " "; });
    cout << endl;
}
void biggies2(vector<string> &words, vector<string>::size_type sz, ostream &os, char c)
{
    // 隐式在前，显式在后
    // os隐式捕获，引用捕获；c显式捕获,值捕获方式
    for_each(words.begin(), words.end(), [&, c](const string &s)
             { os << s << c; });
    // os显式捕获，引用捕获,c隐式捕获,值捕获
    for_each(words.begin(), words.end(), [=, &os](const string &s)
             { os << s << c; });
}
void func1()
{
    size_t v1 = 42;
    auto f = [v1]()
    { return v1; };
    v1 = 0;
    auto j = f();
    cout << j << endl; // j=42
}
/// @brief 引用捕获
void func2()
{
    // 当以引用方式捕获一个变量时，必须保证在lambda执行时变量是存在的
    size_t v1 = 42;
    auto f2 = [&v1]()
    { return v1; };
    v1 = 0;
    auto j = f2();
    cout << j << endl; // j=0
}
void func3()
{
    size_t v1 = 42;
    auto f2 = [v1]() mutable //对于值拷贝的变量，如何需要修改,必须加上关键字mutable
    { return ++v1; };
    v1 = 0;
    auto j = f2();
    cout << j << endl; // j = 43
}
void func4()
{
    size_t v1 = 42;
    auto f2 = [&v1]()
    { return ++v1; };
    v1 = 0;
    auto j = f2();
    cout << j << endl; // j = 1
}

bool check_size(const string& s,string::size_type sz)
{
    return s.size()>=sz;
}
#pragma endregion