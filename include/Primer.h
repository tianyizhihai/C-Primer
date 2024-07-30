#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <list>
#include <array>
#include <deque>
#include <forward_list>
using namespace std;
class Sales_data
{
public:
    string str;
    int num1;
    int num2;
    Sales_data()
    {
        str = "李佳明";
        num1 = 7274;
        num2 = 20010115;
    }
    Sales_data(const string& str_,const int& num1_,const int& num2_):str(str_),num1(num1_),num2(num2_){};
};

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