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

#pragma endregion
    return 0;
}