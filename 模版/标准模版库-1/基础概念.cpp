#include <iostream>
#include <vector>
#include<algorithm>
#include<list>
using namespace std;

//泛型程序设计

//容器概述
/*
    顺序容器、vector(动态一位数组),deque(双向队列),list(双向链表)
    关联容器、set, multiset, map, multimap  //内部元素是已经排序的
    容器适配器、

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
template<class T> 
void PrintVector( T s, T e) { 
    for(; s != e; ++s) 
        cout << * s << " "; 
    cout << endl; 
}


//双向链表list
/*
在任何位置插入删除都是常数时间,不支持随机存取。
除了具有所有顺序容器都有的成员函数以外,还支持8个成员函数: 
push_front: 在前面插入
pop_front:   删除前面的元素
sort: 排序( list 不支持 STL 的算法 sort) //list不支持随机迭代器，所以排序要用list自己的sort成员函数
remove:  删除和指定值相等的所有元素
unique: 删除所有和前一个元素相同的元素(要做到元素不重复,则unique之前还需要 sort) 
merge:   合并两个链表,并清空被合并的那个
reverse: 颠倒链表
splice: 在指定位置前面插入另一链表中的一个或多个元素,并在另一链表中删除被插入的元素
*/


//list容器
class A { 
    private: 
        int n; 
    public: A( int n_ ) { 
        n = n_; 
} 
friend bool operator<( const A & a1, const A & a2); 
friend bool operator==( const A & a1, const A & a2); 
friend ostream & operator <<(  ostream & o, const A & a); };
bool operator<( const A & a1, const A & a2) { 
    return a1.n < a2.n; 
} 
bool operator==( const A & a1, const A & a2) { 
    return a1.n == a2.n; 
} 
ostream & operator <<(  ostream & o, const A & a) { 
    o << a.n; 
    return o; 
}
template <class T> 
void PrintList(const list<T> & lst) { 
//不推荐的写法,还是用两个迭代器作为参数更好
int tmp = lst.size(); 
if( tmp > 0  ) { 
    typename list<T>::const_iterator i; 
    i = lst.begin(); 
    for( i = lst.begin();i != lst.end(); i ++) 
        cout << * i << ","; 
    } 
}// typename用来说明 list<T>::const_iterator是个类型
//在vs中不写也可以


//函数对象




int main(){
    // vector<int> v; //一个存放int元素的数组,一开始里面没有元素
    // v.push_back(1);  v.push_back(2);   v.push_back(3);  
    // v.push_back(4); vector<int>::const_iterator i;   //常量迭代器
    // for( i = v.begin();i != v.end();++i ) 
    //     cout << * i << ","; 
    // cout << endl;

    // vector<int>::reverse_iterator r;  //反向迭代器
    // for( r = v.rbegin();r != v.rend();r++ ) 
    //     cout << * r << ","; 
    // cout << endl; 
    // vector<int>::iterator j;   //非常量迭代器
    // for( j = v.begin();j != v.end();j ++ ) 
    //     * j =  100; 
    // for( i = v.begin();i != v.end();i++ ) 
    //     cout << * i << ",";


    // int a[5] = { 1,2,3,4,5 };    
    // vector<int> v(a,a+5);  //将数组a的内容放入v 
    // cout << "1) " << v.end()  - v.begin() << endl; //两个随机迭代器可以相减,输出 1) 5 
    // cout << "2) "; PrintVector(v.begin(),v.end()); //2) 1 2 3 4 5 
    // v.insert(v.begin() + 2, 13); //在begin()+2位置插入 13 ，后面的元素依次往后推
    // cout << "3) "; PrintVector(v.begin(),v.end()); //3) 1 2 13 3 4 5 
    // v.erase(v.begin() + 2); //删除位于 begin() + 2的元素
    // cout << "4) "; 
    // PrintVector(v.begin(),v.end()); //4) 1 2 3 4 5 
    // vector<int> v2(4,100);  //v2 有4个元素,都是100 
    // v2.insert(v2.begin(),v.begin()+ 1,v.begin()+3); //将v的[1,3)的元素插入v2开头
    // cout << "5) v2: "; PrintVector(v2.begin(),v2.end()); //5) v2: 2 3 100 100 100 100 48 
    // v.erase(v.begin() + 1, v.begin() + 3); //删除 v 上的一个区间,即 2,3 
    // cout << "6) "; 
    // PrintVector(v.begin(),v.end()); //6) 1 4 5

    //用vector实现二维数组
    // vector<vector<int> > v(3); //v有3个元素,每个元素都是vector<int> 容器
    // for(int i = 0;i < v.size(); ++i) 
    //     for(int j = 0; j < 4; ++j) 
    //         v[i].push_back(j); 
    // for(int i = 0;i < v.size(); ++i) { 
    //     for(int j = 0; j < v[i].size(); ++j) 
    //         cout << v[i][j] << " "; cout << endl; }
    

    list<A>  lst1,lst2; 
    lst1.push_back(1);
    lst1.push_back(3); 
    lst1.push_back(2);
    lst1.push_back(4);  
    lst1.push_back(2); 
    
    lst2.push_back(10);
    lst2.push_front(20); 
    lst2.push_back(30);
    lst2.push_back(30); 
    lst2.push_back(30);
    lst2.push_front(40); 
    lst2.push_back(40); 
    cout << "1) "; PrintList( lst1); cout << endl; 
    // 1) 1,3,2,4,2, 
    cout << "2) "; PrintList( lst2); cout << endl; 
    // 2) 40,20,10,30,30,30,40, 58 
    lst2.sort(); 
    cout << "3) "; PrintList( lst2); cout << endl; 
    //3) 10,20,30,30,30,40,40, 
    lst2.pop_front(); //删除头部元素
    cout << "4) "; PrintList( lst2); cout << endl; 
    //4) 20,30,30,30,40,40, 
    lst1.remove(2); //删除所有和A(2)相等的元素
    cout << "5) "; PrintList( lst1); cout << endl; 
    //5) 1,3,4, 
    lst2.unique();  //删除所有和前一个元素相等的元素
    cout << "6) "; PrintList( lst2); cout << endl; 
    //6) 20,30,40,
    
    lst1.merge (lst2);  //合并 lst2到lst1并清空lst2 
    cout << "7) "; PrintList( lst1); cout << endl; 
    //7) 1,3,4,20,30,40, 
    cout << "8) "; PrintList( lst2); cout << endl; 
    //8) 
    lst1.reverse(); 
    cout << "9) "; PrintList( lst1); cout << endl; 
    //9) 40,30,20,4,3,1, 60 
    lst2.push_back (100);
    lst2.push_back (200); 
    lst2.push_back (300);
    lst2.push_back (400); 
    list<A>::iterator p1,p2,p3; //定义三个迭代器（类似于指针）
    p1 = find(lst1.begin(),lst1.end(),3); 
    p2 = find(lst2.begin(),lst2.end(),200); 
    p3 = find(lst2.begin(),lst2.end(),400); 
    lst1.splice(p1,lst2,p2, p3);  
    //将[p2,p3)插入p1之前,并从lst2中删除[p2,p3) 
    cout << "10) "; PrintList( lst1); cout << endl; 
    //10) 40,30,20,4,200,300,3,1, 
    cout << "11) "; PrintList( lst2); cout << endl; 
    //11) 100,400,



    return 0;
}