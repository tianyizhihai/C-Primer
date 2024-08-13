#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iterator>
#include <list>
#include <array>
#include <deque>
#include <forward_list>
#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;
class Sales_item
{
    Sales_item(){};
};
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

#pragma region 泛型算法概述
//消除重复单词
void elimDups(vector<string>& words);
/// @brief 比较函数，用来按长度排序单词
/// @param s1 
/// @param s2 
/// @return 
bool isShorter(const string& s1, const string& s2);
void ToString(const vector<string>& words);

void biggies1(vector<string>& words, vector<string>::size_type sz);

void biggies2(vector<string>& words, vector<string>::size_type sz,ostream &os=cout,char c =' ');

//值捕获
void func1();
//引用捕获
void func2();
void func3();
void func4();

bool check_size(const string& s1, string::size_type sz);
#pragma endregion