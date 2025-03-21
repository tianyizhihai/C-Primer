#include "Primer.h"
using namespace std;
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
    // 特殊的forward_list操作
    // forward_list<int> flist1;
    // flist1.before_begin();
    // flist1.cbefore_begin();
    // flist1.insert_after(); //返回一个指向最后一个插入元素的迭代器
    // flist1.insert_after(p,n,t);//在p后插入n个t
    // flist1.insert_after(p,b,e);//b,e为两个迭代器
    // flist1.emplace_after();
    // flist1.erase_after(); //返回一个被删元素之后元素的迭代器
    // eg:
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
    // 顺序容器大小操作
    // resize()不适用于array
    // vector<int> v1;
    // v1.resize(n); //调整为n个元素，多余会被删除，若必须添加新元素，对新元素进行值初始化 int值初始化为0
    // v1.resize(n,1);  //调整为n个元素，多余会被删除，若必须添加新元素，所有新元素为1
    // 不要缓存end()迭代器,缓存end()迭代器会导致end()不会重新计算
    // vector<int> v1;
    // auto begin = v1.begin(),end = v1.end();
    // while(begin!=end)
    // {
    //     ++begin;
    //     begin = v1.insert(begin,42);
    //     ++begin;
    // } //扩容的时候，可能会在其他位置开辟空间而不是尾后,删除的时候，尾后仍然不变会导致越界
    // vector是如何增长的
    // shrink_to_fit 只适用于vector、string和deque
    // capacity和reserve只适用于vector和string
    // vector<int> v1;
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
    // string s;
    // s.substr(pos,n);//返回一个string,包含s中从pos开始的n个字符的拷贝.pos的默认值为0.n的默认值为s.size()-pos,级拷贝从pos开始的所有字符
    // string s("hello world");
    // string s2 = s.substr(0,5);//s2 == "hello"
    // string s3 = s.substr(6);//s3 == "world"
    // string s4 = s.substr(6,11);//s4 == "world"
    // string s5 = s.substr(12);//错误，越界
    // 除了接收迭代器的insert和erase版本外,string还提供了接收下标的版本
    // string s;
    // s.insert(s.size(),5,'!');//在s末尾插入5个感叹号
    // s.erase(s.size()-5,5);//在s删除最后5个字符
    // 还提供了接收C风格字符数组的insert和assign版本
    // const char *cp = "Stately, plump Buck";
    // s.assign(cp,7); // s == "Stately"
    // s.insert(s.size(),cp+7); // s = "Stately, plump Buck"
    // 也可以插入string
    // string s = "some string",s2 = "some other string";
    // s.insert(0,s2); //在s中位置0之前插入s2的拷贝
    // s.insert(0,s2,0,s2.size()); //在s[0]之前插入s2中s2[0]开始的s2.sze()个字符
    // append和replace函数
    // append操作实在string进行插入操作的一种简写形式
    // string s("C++ Pirmer"),s2 = s;
    // s.insert(s.size()," 4th Ed.");//C++ Pirmer 4th Ed.
    // s2.append(" 4th Ed.");//C++ Pirmer 4th Ed.
    // replace操作是erase和insert的一种简写形式
    // s.erase(11,3);// s = "C++ Primer  4th"
    // s.insert(s.size(),"5th");//C++ Pirmer 5th Ed.
    // s2.replace(11,3,"5th");//C++ Pirmer 5th Ed.
    // s2.replace(11,3,"lijiaming");//也可以长度无需相等
    // string搜索操作
    // string s("Hello World"),s2("World");
    // find()函数返回首次找到s2中与s中某一段相等的子串的起始位置
    // int pos = s.find(s2); // pos == 6
    // rfind()函数返回最后一次找到s2中与s中某一段相等的子串的起始位置
    // int pos = s.rfind(s2); //pos == 6
    // find_first_of()函数返回首次找到s2中与s中某一字符相等的位置
    // int pos = s.find_first_of("lo"); // pos == 2
    // find_last_of()函数返回最后一次找到s2中与s中某一字符相等的位置
    // int pos = s.find_last_of("lo"); // pos == 9
    // find_first_not_of()函数返回首次找到s2中不与s中某一字符相等的位置
    // int pos = s.find_first_not_of("lo"); // pos == 0
    // find_first_not_of()函数返回首次找到s2中不与s中某一字符相等的位置
    // int pos = s.find_last_not_of("lo"); // pos == 10
    // string numbers("0123456789"),name("r2d2");
    // string::size_type pos = 0;
    // while((pos =name.find_first_of(numbers,pos)) != string::npos)
    // {
    //     cout<<"found number at index "<<pos<<" element is"<< name[pos]<<endl;
    //     pos++;
    // }
    // s.compare()的几种参数形式
    // int result = s.compare(s2); // result == 0
    // result = s.compare(s2.c_str()); // result == 0
    // result = s.compare(0,s.size(),s2,0,s2.size()); // result == 0
    // result = s.compare(0,s.size(),s2,0,s2.size()-1); // result < 0
    // result = s.compare(0,s.size(),s2,s2.size()-1,1); // result > 0
    // string转换成C风格字符数组
    // const char *cp = s.c_str();
    // const char *cp = &s[0];
    // C风格字符数组转string
    // string s2(cp);
    // string s2(cp,n);
    // string s2(cp,n,m);
    // string转换其他类型
    // 栈和队列

#pragma endregion
#pragma region 泛型算法概述
    // // 求和
    // vector<int> vec;
    // // int sum = accumulate(vec.cbegin(),vec.cend(),0);//第三个参数决定返回值类型
    // // vector<string> v = {"123","456"};
    // // string sum = accumulate(v.cbegin(),v.cend(),string(""));//正确
    // //     sum = accumulate(v.cbegin(),v.cend(),"");//错误，const char* 没有定义+运算符
    // // 比较
    // vector<string> roster1 = {"123", "345"};
    // list<const char *> roster2 = {"123", "345"};
    // // vector<string> roster2 = {"123","345"};
    // // 第三个参数表示第二个序列的首元素
    // // roster2中的元素树木应该至少和roster1一样多，否则返回false
    // cout << equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) << endl;
    // // 上面的roster1可以是vector<string>
    // // 而roster2是list<const char*> 只要能够访问，能够比较即可
    // // 写容器元素的算法
    // fill(vec.begin(), vec.end(), 0);                     // 将每个元素重置为0
    // fill(vec.begin(), vec.begin() + vec.size() / 2, 10); // 将容器的一个子序列设置为10
    // fill_n(vec.begin(), vec.size(), 0);                  // 将每个元素重置为0
    // // fill_n(dest,n,val);//dest指向一个元素,而从dest开始至少需要包含n个元素
    // fill_n(vec.begin(), 10, 0); // 灾难：不可越界
    // // 插入迭代器
    // auto it = back_inserter(vec);
    // *it = 42; // 假设vec为空,现在vec有一个值为42的元素
    // vector<int> vec2;
    // fill_n(back_inserter(vec2), 10, 0); // 添加10哥元素到vec
    // // 每次赋值都会在迭代器上调用push_back
    // // 拷贝算法
    // int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int a2[sizeof(a1) / sizeof(*a1)]; // a1与a2大小一样
    // // ret指向拷贝到a2的尾后位置
    // auto ret = copy(begin(a1), end(a1), a2); // 把a1的内容拷贝给a2
    // // 将所有值为0的元素改为42
    // list<int> ilist;
    // replace(ilist.begin(), ilist.end(), 0, 42);
    // // 使用back_insterter按需要增长目标序列
    // replace_copy(ilist.cbegin(), ilist.cend(), back_inserter(vec), 0, 42);
    // 上面的语句调用后,list并未改变,vec包含list的一份拷贝
    // 不过原来在list中值为0的元素在vec中都变成了42
    // vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    // elimDups(words);
    // sort(words.begin(), words.end(),isShorter);
    // elimDups(words);
    // stable_sort(words.begin(), words.end(), isShorter);
    // ToString(words);
    // lambda表达式
    // auto check_size = [](const string &s) { return s.size() >= 5; };
    // auto wc = count_if(words.begin(), words.end(), check_size);
    // 正则表达式
    // regex r("[a-zA-Z]+");
    // sregex_iterator it(words.begin(), words.end(), r), end;
    // for(; it!= end; ++it)
    // {
    //     cout << "Match: " << it->str() << endl;
    // }
    // 正则表达式和lambda
    // sregex_token_iterator it(words.begin(), words.end(), r, -1), end;
    // for(; it!= end; ++it)
    // {
    //     cout << "Match: " << it->str() << endl;
    // }
    // 正则表达式和函数
    // auto is_shorter = [](
    // lambda表达式
    // auto f = []
    // { return 42; };
    // cout<<f()<<endl;
    // biggies(words, 4);
    // lambda捕获和返回
    // func1();
    // func2();
    // vector<int> vi = {1,-3,3,-4};
    // transform(vi.begin(), vi.end(),vi.begin(),[](int i)->int{if(i<0)return -i;else return i;});
    // for_each(vi.begin(), vi.end(), [](int i){cout<<i<<" ";});
    // auto check6 = bind(check_size, _1, 6);
    // string s = "hello";
    // bool b1 = check6(s);
    // cout << b1 << endl;
    // auto wc = find_if(words.begin(), words.end(), bind(check_size, _1, 6));
    // cout << *wc << endl;
    // auto wc2 = find_if(words.begin(), words.end(), check6);
    // cout << *wc2 << endl;

    // g是一个有两个参数的可调用对象
    // auto g = bind(f,a,b,_2,c,_1);
    // g(X,Y)的调用会映射到：f(a,b,Y,c,X);
    //  //按单词长度由短至长排序
    //  sort(words.begin(), words.end(),isShorter);
    //  //按单词长度由长至短排序
    //  sort(words.begin(), words.end(),bind(isShorter,_2,_1));
    // ref
    //  it 是由inserter生成的迭代器
    //  *it = val;//和下面代码一致
    //  it =c.insert(iter,val);
    //  ++it;
    // back_inserter,创建一个使用push_back的迭代器
    // front_inserter,创建一个使用push_front的迭代器
    // inserter,创建一个使用insert的迭代器,插入指定迭代器之前的位置

    // list<int> lst = {1, 2, 3, 4};
    // auto it = lst.begin();
    // cout<<*it<<endl;
    // lst.push_front(0);
    // cout<<*it<<endl;
    // list<int> lst2, lst3;

    // copy(lst.cbegin(), lst.cend(), front_inserter(lst2));         // 4,3,2,1
    // for_each(lst2.begin(),lst2.end(),[](int s){cout<<s<<endl;});
    // copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin())); // 1,2,3,4
    // for_each(lst3.begin(),lst3.end(),[](int s){cout<<s<<endl;});
    // iostream迭代器
    // vector<int> vec = {1, 2, 3, 4, 5};
    // istream_iterator<int> int_iter(cin); // 绑定流,从cin读取int
    // istream_iterator<int> int_eof;       // 默认初始化迭代器，尾后迭代器
    // while(int_iter!=int_eof)
    // {
    //     vec.push_back(*int_iter++);
    // }
    // //等同于
    // vector<int> vec1(int_iter,int_eof);

    // ifstream in("file.txt");
    // istream_iterator<string> str_iter(in);//从"file.txt"中读取字符串
    // cout << accumulate(int_iter, int_eof, 0) << endl;
    // ostream_iterator<int> out_iter(cout, " ");

    // for (auto e : vec)
    // {
    //     *out_iter++ = e;
    // }
    // cout<<endl;

    // for(auto e:vec)
    //     out_iter = e;
    // cout<<endl;

    // copy(vec.begin(),vec.end(),out_iter);
    // cout<<endl;
    // Sales_item类
    // istream_iterator<Sales_item> item_iter(cin),eof;
    // ostream_iterator<Sales_item> out_iter(cout,"\n");
    // Sales_item sum = *item_iter++;
    // while(item_iter != eof)
    // {
    //     if(true)
    //     cout<<endl;
    // }
    // 反向迭代器
    // for(auto r_iter = vec.crbegin();r_iter!=vec.crend();++r_iter)
    // {
    //     cout<<*r_iter<<endl;
    // }
    // sort(vec.begin(),vec.end());//升序
    // sort(vec.rbegin(),vec.rend());//降序

    // string line = "FIRST,MIDDLE,LAST";
    // auto comma = find(line.cbegin(), line.cend(), ',');
    // cout << string(line.cbegin(), comma) << endl;

    // auto rcomma = find(line.crbegin(), line.crend(), ',');
    // cout << string(line.crbegin(), rcomma) << endl;

    // cout << string(rcomma.base(), line.cend()) << endl;
    // 泛型算法结构
    // 特定容器算法
#pragma endregion
#pragma region 使用关联容器

    map<string, size_t> word_cout;
    set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                           "the", "but", "and", "or", "an", "a"};
    // string word;
    // while(cin>>word)
    //     if(exclude.find(word)==exclude.end())
    //         ++word_cout[word];
    // for(const auto& w:word_cout)
    //     cout<<w.first<<" occurs "<< w.second << ((w.second>1)?" times":" time")<<endl;

    // vector<int> ivec;

    set<string>::key_type v1;   // v1是一个string
    set<string>::value_type v2; // v2是一个string 两者相同

    map<string, int>::value_type v3;  // v3是一个pare<const string,int>
    map<string, int>::key_type v4;    // v4是一个string
    map<string, int>::mapped_type v5; // v5是一个int

    // *map_it 是指向pair<const string,size_t>对象的引用

    // cout<<map_it->first<<endl;
    // cout<<map_it->second<<endl;
    // cout<<map_it->second<<endl;
    // map_it->first = "new key";//错误：关键字是const的
    // ++map_it->second;
    set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // set<int>::iterator set_it = iset.begin();
    // if(set_it!=iset.end())
    // {
    //     // *set_it =42;//错误，set中的关键字是const的
    //     cout<<*set_it<<endl;
    // }

    // string word;
    // while(cin>>word)
    // {
    //     auto ret = word_cout.insert({word,1});
    //     if(!ret.second)
    //         ++ret.first->second;

    // }
    // auto map_it = word_cout.begin();
    // while(map_it!=word_cout.end())
    // {
    //     cout<<map_it->first<<"occurs"<<map_it->second<<"times"<<endl;
    //     ++map_it;
    // }
    // //erase删除一个关键字，返回删除的元素数量
    // if(word_cout.erase("word"))
    //     cout<<"ok:"<<"word"<<" removed\n";
    // else
    //     cout<<"oops:"<<"word"<<" not found!\n";
    // //插入一个关键字为Anna的元素,关联值进行值初始化；然后将1赋予它
    // word_cout["Anna"] = 1; //下标运算符肯呢个插入一个新元素，我们只可以对非const的map使用下标操作，at也不能用于非const
    // lower_bound和upper_bound不适用于无序容器
    // lower_bound(k)返回一个迭代器,指向第一个关键字不小于k的元素
    // upper_bound(k)返回一个迭代器,指向第一个关键字大于k的元素
    // equal_range(k)返回一个迭代器pair，表示关键字等于k的元素的范围。若k不存在,pair的两个成员均等于c.end()

    iset.find(1);   // 返回一个迭代器,指向key==1的元素
    iset.find(11);  // 返回iset.end()
    iset.count(1);  // 1
    iset.count(11); //  0

    // multimap<string,string> author{{"李佳明","一"},{"李佳明","二"},{"李佳明","三"},{"李佳明","四"}};
    // size_t num = author.count("李佳明");
    // auto author_it = author.find("李佳明");
    // while(num)
    // {
    //     cout<<author_it->second<<endl;
    //     author_it++;
    //     num--;
    // }
    // for(auto beg = author.lower_bound("李佳明"),end = author.upper_bound("李佳明");beg!=end;beg++)
    // {
    //     cout<<beg->second<<endl;
    // }
    // for(auto pos = author.equal_range("李佳明");pos.first!=pos.second;pos.first++)
    // {
    //     cout<<pos.first->second<<endl;
    // }
    // unordered_map<string,size_t>word_count;
    // string word;
    // while(cin>>word)
    //     if(exclude.find(word)==exclude.end())
    //         ++word_count[word];
    // for(const auto& w:word_count)
    //     cout<<w.first<<" occurs "<< w.second << ((w.second>1)?" times":" time")<<endl;
    //哈希，桶
#pragma endregion
#pragma region 关联容器
#pragma endregion
#pragma region 智能指针

// shared_ptr<string> p1;
// shared_ptr<list<int>> p2;
// if(p1&&p1->empty())
// {
//     *p1 = "hi";
// }
// cout<<"p1"<<endl;
// cout<<p1.unique()<<endl;
// // shared_ptr<int> p3 = make_shared<int>(42);
// // shared_ptr<string> p4 = make_shared<string>(10,'9'); 
// //shared_ptr<int> p(new int(42));
// //process(p);
// //cout<<p.use_count()<<endl;//count = 1

// //int *x(new int(1024));
// //process(x); 错误不能将int*转化为shared_ptr<int>
// //process(shared_ptr<int>(x));//合法
// //调用方法后x被释放

// shared_ptr<int> p(new int(42));
// int *q = p.get();
// {
//     shared_ptr<int> p2(q);
// }//程序块结束，p2被销毁，指向的内存被释放
//永远不要用get初始化另一个智能指针或为另一个智能指针赋值
#pragma endregion
#pragma region 动态数组
// typedef int arrT[42];
// int *p = new arrT;//编译器执行int *p = new int[42];
// int *pia = new int[10];//10个未初始化的int
// int *pia2 = new int[10]();//10个值初始化为0的int
// string *psa = new string[10]; //10个空string
// string *psa2 = new string[10](); //10个空string
// int *pia3 = new int[10]{0,1,2,3,4,5,6,7,8,9};//初始化
// string *psa3 = new string[10]{"a","an","the",string(3,'x')};

// size_t n = 0;
// int *p = new int[n];
// //若n = 0,则p就类似于尾后迭代器
// for(int *q = p; q!=p+n;++q)
// {
//     //处理数组
// }
// char arr[0];//错误：不能定义长度为0的数组
// char* cp = new char[0];//正确，但cp不能解引用；


// unique_ptr<int[]> up(new int[10]);
// up.reset();//自动调用delete[]
// for(size_t i = 0;i!=10;i++)
// {
//     up[i] = i;    
// }
// //如果希望使用share_ptr管理，必须自定义删除器
// shared_ptr<int> sp(new int[10],[](int *p){delete []p;});
// sp.reset();//使用我们提供的lambda释放数组
// //shared_ptr 未定义下标运算符，并且不支持指针的算数运算
// for(size_t i = 0;i!=10;i++)
// {
//     *(sp.get()+i) = i;//使用get()获取一个内置指针
// }

//allocator类
//将内存分配和对象构造组合在一起可能导致不必要的浪费
// string *const p = new string[10]; 
// string s;
// string *q = p;//q指向第一个string
// while(cin>>s&&q!=p+10)
// {
//     *q++ = s; //赋予*q一个新值
// }
// const size_t size = q-p;//记录我们读取了多少string
// //使用数组
// delete[] p;

// int n =10;
// allocator<string> alloc;

// auto const p = alloc.allocate(n);
// auto q = p;
// alloc.construct(q++);
// alloc.construct(q++,10,'c');
// alloc.construct(q++,"hi");

// cout<<*p<<endl;//正确，“”
// cout<<*q<<endl;//错误，q指向未构造的内存
// while(q!=p)
// {
//     alloc.destroy(--q);
// }
// alloc.deallocate(p,n);
allocator<int> alloc;
vector<int> vi({0,1,2,3,4,5,6,7,8,9});
auto p = alloc.allocate(vi.size()*2);
auto q = uninitialized_copy(vi.begin(),vi.end(),p);

uninitialized_fill_n(q,vi.size(),42);
#pragma endregion
    return 0;
}