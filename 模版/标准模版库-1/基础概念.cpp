#include <iostream>
#include <vector>
using namespace std;

//泛型程序设计

//容器概述
/*
    顺序容器、关联容器、容器适配器、

顺序容器和关联容器中都有的成员函数

begin 返回指向容器中第一个元素的迭代器
end 返回指向容器中最后一个元素后面的位置的迭代器
rbegin 返回指向容器中最后一个元素的迭代器
rend 返回指向容器中第一个元素前面的位置的迭代器
erase 从容器中删除一个或几个元素
clear 从容器中删除所有元素

顺序容器的常用成员函数

front :返回容器中第一个元素的引用
back : 返回容器中最后一个元素的引用
push_back : 在容器末尾增加新元素
pop_back : 删除容器末尾的元素
erase :删除迭代器指向的元素(可能会使该迭代器失效),或删除一个区间,返回被删除元素后面的那个元素的迭代器


*/

//迭代器
    //迭代器示例
/*
 用于指向顺序容器和关联容器中的元素
 迭代器用法和指针类似
 有const 和非 const两种
 通过迭代器可以读取它指向的元素
 通过非const迭代器还能修改其指向的元素
*/

    //双向迭代器

    //随机访问迭代器

//算法简介


//STL中的 大，小，相等


//vector和deque


//双向链表list


//函数对象




int main(){
    vector<int> v; //一个存放int元素的数组,一开始里面没有元素
    v.push_back(1);  v.push_back(2);   v.push_back(3);  
    v.push_back(4); vector<int>::const_iterator i;   //常量迭代器
    for( i = v.begin();i != v.end();++i ) 
        cout << * i << ","; 
    cout << endl;

    vector<int>::reverse_iterator r;  //反向迭代器
    for( r = v.rbegin();r != v.rend();r++ ) 
        cout << * r << ","; 
    cout << endl; 
    vector<int>::iterator j;   //非常量迭代器
    for( j = v.begin();j != v.end();j ++ ) * j =  100; 
    for( i = v.begin();i != v.end();i++ ) cout << * i << ",";


    return 0;
}