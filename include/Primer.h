#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;



#pragma region string流(未完善)
struct PersonInfo
{
    /* data */
    string name;
    vector<string> phones;
};

void LJM_StringStream();
#pragma endregion

#pragma region 顺序容器
class noDefualt
{
private:
    int num;
};
class Container_demo1
{
private:
    string str;
public:
    Container_demo1(string str_)
    {
        str = str_;
    }
};
#pragma endregion