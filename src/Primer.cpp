#include "Primer.h"
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