#include "Primer.h"

int main()
{

#pragma region 顺序容器
    // 若类有默认构造函数，可以直接vector创建，若没有则需要元素初始化器
    // vector<Defualt> v1(10); 正确：有默认构造函数
    // vector<noDefualt> v1(10,init); 正确：提供元素初始化器
    // vector<noDefualt> v2(10); 错误
    // 没有默认构造函数实例：
    //  Container_demo1 aObj("hello");
    //  vector<Container_demo1> aObj(100,aObj);
    // 隐式转换
    //  string aObj("hello");
    //  vector<Container_demo1> aObj(100,aObj);
    // 迭代器
    //  while (begin() != end())
    //  {
    //      *begin() =val;
    //      ++begin();
    //  }
    // list<string> a= {"hello", "world"};
    // auto it1 = a.begin();//list<string>::iterator
    // auto it2 = a.rbegin();//list<string>::reverse_iterator
    // auto it3 = a.cbegin();//list<string>::const_iterator
    // auto it4 = a.crbegin();//list<string>::const_reverse_iterator
    // it1 = it3;//错误 it3为const
    // it3 = it1;//正确
    // begin()、end()等、其实是重载
    //  iterator begin()
    //  {
    //      ...
    //  }
    //  const_iterator begin()
    //  {
    //      ...
    //  }
    //  const list<string> b = {"Hello","World"};
    //  list<string>::iterator cit1 = b.begin();//错误，this指针指向的是const对象
    //  list<string>::const_iterator cit2 = b.begin();//正确
    //  int a1[5] = {1,2,3,4,5};
    //  int a2[5] = a1; //错误，内置数组不可拷贝赋值
    // 容器的初始化
    //  array<int,10> a1;
    // 初始化
    //  array<int,10> a2(a1);
    //  array<int,10> a3 = a2;
    //  array<int,10> a4 = {1,2,3}; // 剩下的元素不是默认初始化，是0
    //  //array<int,5> a5 = a1; //错误，若想拷贝容器，则需要两个容器完全一致
    //  //array<string,10> a6 = a1; // 错误
    // 遍历array forward_list不能递减迭代器
    //  array<int,10>::iterator a4it;
    //  for(a4it = a4.begin(); a4it != a4.end(); a4it++)
    //  {
    //      cout<<*a4it<<endl;
    //  }
    //  cout<<a1.size()<<endl;
    //  list<int> list1;
    //  vector<int> vector1;
    //  vector1.push_back(1);
    //  vector1 = {3,2,1};
    //  cout<<vector1[0]<<endl;
    //  a4 = {3,2,1};
    //  cout<<*a4.begin()<<endl;
    //  deque<int> deque1;
    //  forward_list<int> f_list1;
    //  array<int> arrays;
    // 容器的比较
    // 容器的比较，要求容器的元素类型可以进行比较，容器中每个位置元素一一对比
    //  vector<int> v1 = {1,3,5,7,9,11};
    //  vector<int> v2 = {1,3,9};
    //  vector<int> v3 = {1,3,5,7};
    //  vector<int> v4 = {1,3,5,7,9,11};
    //  cout<<(v1<v2)<<endl;//true
    //  cout<<(v1<v3)<<endl;//false
    //  cout<<(v1<=v2)<<endl;//true
    //  cout<<(v1==v2)<<endl;//false
    // 容器的操作
    // array 不支持添加元素，这会导致array改变容器大小
    // push_back和emplace_back的区别
    // emplace()方法是insert()的emplace版本
    //  vector<int> v1;
    //  v1.push_back(1);
    //  v1.emplace_back(2);
    //  vector<Sales_data> v1;
    //  v1.push_back("李佳明",7274,2001); //错误，push_back不会构造Sales_data
    //  v1.emplace_back("李佳明",7274,2001); //正确调用Sales_data(string,int,int)构造函数
    //  v1.emplace_back();//正确，调用空构造
    // 了解左值和右值，左值引用和右值引用
    //  list,forward_list和deque支持元素插入到容器头部
    //  vector<int> v1 = {1,2,3,4,5};
    //  auto it = v1.begin();
    //  v1.insert(v1.begin(),v1.begin(),v1.end());
    //  for(const int &o :v1)
    //      cout<<o<<endl;
    // insert()的返回值是新插入首元素的迭代器位置
    //  v1.insert(v1.begin(),6);
    //  cout<<*it<<endl; //迭代器失效
    //  it = v1.insert(v1.begin(),6);
    //  cout<<*it<<endl;
    // at和下标只适用于string、vector、deque和array
    // back不适用于forward_list
    //  vector<int> v1 = {1,2,3};
    //  v1.back(); //返回v1中尾元素的引用
    //  v1.front(); //返回v1中首元素的引用
    //  v1[i]; //返回下标i元素的引用
    //  v1.at(i); //同上
    // 四种操作若越界或v1为空，则会报错
    // auto推到引用时，不会返回引用，auto更在意值，若想返回引用则需要auto&
    // array 不支持删除元素，这会导致array改变容器大小
    // forward_list 有特殊版本的erase(),且不支持pop_back();
    // vector,string 不支持pop_front()
    // erase()返回指向最后一个被删元素之后位置的迭代器
    // list<int> list1 = {0,1,2,3,4,5,6,7,8,9};
    // auto it = list1.begin();
    // while (it!=list1.end())
    // {
    //     if(*it%2)
    //         it = list1.erase(it);
    //     else
    //         ++it;
    // }
    // it1 = list1.erase(it1,it2);//调用后，it1 == it2;
    //特殊的forward_list操作
    // forward_list<int> flist1;
    // flist1.before_begin();
    // flist1.cbefore_begin();
    // flist1.insert_after(); //返回一个指向最后一个插入元素的迭代器
    // flist1.insert_after(p,n,t);//在p后插入n个t
    // flist1.insert_after(p,b,e);//b,e为两个迭代器
    // flist1.emplace_after();
    // flist1.erase_after(); //返回一个被删元素之后元素的迭代器
    //eg:
    // forward_list<int> flist1 = {0,1,2,3,4,5,7,8,9};
    // auto prev = flist1.before_begin();
    // auto curr = flist1.begin();
    // while(curr != flist1.end())
    // {
    //     if(*curr % 2)
    //         curr = flist1.erase_after(prev);
    //     else
    //     {
    //         prev = curr;
    //         ++curr;
    //     }
    // }
    //顺序容器大小操作
    //resize()不适用于array
    // vector<int> v1;
    // v1.resize(n); //调整为n个元素，多余会被删除，若必须添加新元素，对新元素进行值初始化 int值初始化为0
    // v1.resize(n,1);  //调整为n个元素，多余会被删除，若必须添加新元素，所有新元素为1
    //不要缓存end()迭代器,缓存end()迭代器会导致end()不会重新计算
    // vector<int> v1;
    // auto begin = v1.begin(),end = v1.end();
    // while(begin!=end)
    // {
    //     ++begin;
    //     begin = v1.insert(begin,42);
    //     ++begin;
    // } //扩容的时候，可能会在其他位置开辟空间而不是尾后,删除的时候，尾后仍然不变会导致越界
    //vector是如何增长的
    //shrink_to_fit 只适用于vector、string和deque
    //capacity和reserve只适用于vector和string
    //vector<int> v1;
    // v1.shrink_to_fit(); //将capacity减少为与size相同大小
    // v1.capacity(); // 不重新分配内存空间的话，v1可以保存多少元素
    // v1.reserve(); // 分配至少能容纳n个元素的内存空间
    // string额外操作
    // const char *cp = "Hello World!!!";//以空字符结束
    // char noNull[] = {'H','i'};//不是以空字符结束
    // string s1(cp);//拷贝cp中的字符直到遇到空字符; s1 == "Hello World!!!"
    // string s2(noNull,2);//noNull拷贝两个字符; s2 == "Hi"
    // string s3(noNull);//未定义、noNull不是以空字符结束
    // string s4(cp+6,5);//从s1[6]开始，拷贝5个字符; s4 == "World"
    // string s5(s1,6,5);//从s1[6]开始，拷贝5个字符; s5 == "World"
    // string s6(s1,6); //从s1[6]开始，直到s1末尾; s6 == "World!!!"
    // string s7(s1,6,20);//正确，只拷贝到s1末尾；s7 == "World!!!"
    // string s8(s1,16);//抛出out_of_range异常
    //string s;
    //s.substr(pos,n);//返回一个string,包含s中从pos开始的n个字符的拷贝.pos的默认值为0.n的默认值为s.size()-pos,级拷贝从pos开始的所有字符
    // string s("hello world");
    // string s2 = s.substr(0,5);//s2 == "hello"
    // string s3 = s.substr(6);//s3 == "world"
    // string s4 = s.substr(6,11);//s4 == "world"
    // string s5 = s.substr(12);//错误，越界
    //除了接收迭代器的insert和erase版本外,string还提供了接收下标的版本
    // string s;
    // s.insert(s.size(),5,'!');//在s末尾插入5个感叹号
    // s.erase(s.size()-5,5);//在s删除最后5个字符
    // 还提供了接收C风格字符数组的insert和assign版本
    // const char *cp = "Stately, plump Buck";
    // s.assign(cp,7); // s == "Stately"
    // s.insert(s.size(),cp+7); // s = "Stately, plump Buck"
    // 也可以插入string
    string s = "some string",s2 = "some other string";
    s.insert(0,s2); //在s中位置0之前插入s2的拷贝
    s.insert(0,s2,0,s2.size()); //在s[0]之前插入s2中s2[0]开始的s2.sze()个字符
#pragma endregion
    return 0;
}