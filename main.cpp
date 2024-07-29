#include "Primer.h"

int main()
{


#pragma region 顺序容器
//若类有默认构造函数，可以直接vector创建，若没有则需要元素初始化器
//vector<Defualt> v1(10); 正确：有默认构造函数
//vector<noDefualt> v1(10,init); 正确：提供元素初始化器
//vector<noDefualt> v2(10); 错误
//没有默认构造函数实例：
// Container_demo1 aObj("hello");
// vector<Container_demo1> aObj(100,aObj);
//隐式转换
// string aObj("hello");
// vector<Container_demo1> aObj(100,aObj);
//迭代器
// while (begin() != end())
// {
//     *begin() =val;
//     ++begin();
// }
//list<string> a= {"hello", "world"};
//auto it1 = a.begin();//list<string>::iterator
//auto it2 = a.rbegin();//list<string>::reverse_iterator
//auto it3 = a.cbegin();//list<string>::const_iterator
//auto it4 = a.crbegin();//list<string>::const_reverse_iterator
//it1 = it3;//错误 it3为const
//it3 = it1;//正确
//begin()、end()等、其实是重载
// iterator begin()
// {
//     ...
// }
// const_iterator begin()
// {
//     ...
// }
// const list<string> b = {"Hello","World"};
// list<string>::iterator cit1 = b.begin();//错误，this指针指向的是const对象
// list<string>::const_iterator cit2 = b.begin();//正确
// 
array<int,10> a1;
//初始化
array<int,10> a2(a1);
array<int,10> a3 = a2;
array<int,10> a4 = {1,2,3};
//遍历array
array<int,10>::iterator a4it;
for(a4it = a4.begin(); a4it != a4.end(); a4it++)
{
    cout<<*a4it<<endl;
}
cout<<a1.size()<<endl;
vector<int> vector1;
// array<int> arrays;
#pragma endregion
    return 0;
}