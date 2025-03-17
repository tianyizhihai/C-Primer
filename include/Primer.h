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
#include <map>
#include <set>
#include <memory>
class Sales_item
{
    Sales_item(){};
};
class Sales_data
{
public:
    std::string str;
    int num1;
    int num2;
    Sales_data()
    {
        str = "李佳明";
        num1 = 7274;
        num2 = 20010115;
    }
    Sales_data(const std::string& str_,const int& num1_,const int& num2_):str(str_),num1(num1_),num2(num2_){};
};

#pragma region string流(未完善)
struct PersonInfo
{
    /* data */
    std::string name;
    std::vector<std::string> phones;
};

void LJM_StringStream();


std::string make_plural(size_t ctr,const std::string& word,const std::string& ending);
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
    std::string str;
public:
    Container_demo1(std::string str_)
    {
        str = str_;
    }
};
#pragma endregion

#pragma region 泛型算法概述
//消除重复单词
void elimDups(std::vector<std::string>& words);
/// @brief 比较函数，用来按长度排序单词
/// @param s1 
/// @param s2 
/// @return 
bool isShorter(const std::string& s1, const std::string& s2);
void ToString(const std::vector<std::string>& words);

void biggies1(std::vector<std::string>& words, std::vector<std::string>::size_type sz);

void biggies2(std::vector<std::string>& words, std::vector<std::string>::size_type sz,std::ostream &os=std::cout,char c =' ');

//值捕获
void func1();
//引用捕获
void func2();
void func3();
void func4();

bool check_size(const std::string& s1,std::string::size_type sz);
#pragma endregion

#pragma region 智能指针

void process(std::shared_ptr<int> ptr);

class QueryResult;

using line_on =std::vector<std::string>::size_type;
class TextQuery
{
public:

    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string,std::shared_ptr<std::set<line_on>>> wm;
    
};

class QueryResult
{
    friend std::ostream& print(std::ostream&,const QueryResult&);
public:
    QueryResult(std::string s,std::shared_ptr<std::set<line_on>>p,std::shared_ptr<std::vector<std::string>>f):
    sought(s),lines(p),file(f){};
private:
    std::string sought;
    std::shared_ptr<std::set<line_on>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

std::ostream& print(std::ostream&,const QueryResult&);
#pragma endregion

#pragma region 拷贝，赋值与销毁
class Foo
{
public:
    Foo(){std::cout<<"默认构造"<<std::endl;};
    Foo(const Foo&){std::cout<<"拷贝构造"<<std::endl;};//拷贝构造函数通常不应该是explicit的
};
Foo f(Foo f);
#pragma endregion
