#include <iostream>
#include<set>
using namespace std;

//关联容器
/*
set,multiset,map,multimap
内部元素有序排列,新元素插入的位置取决于它的值,查找速度快。
除了各容器都有的函数外,还支持以下成员函数: 

find: 查找等于某个值 的元素(x小于y和y小于x同时不成立即为相等) 
lower_bound : 查找某个下界
upper_bound : 查找某个上界
equal_range : 同时查找上界和下界
count :计算等于某个值的元素个数(x小于y和y小于x同时不成立即为相等) 
insert: 用以插入一个元素或一个区间
*/

//multiset用法示例
template <class T> 
void Print(T first, T last)   {    
    for(;first != last ; ++first) cout << * first << " ";  
    cout << endl;   
} 
class A    { 
    private: 
        int n; 
    public: 
        A(int n_ ) { n = n_; } 
        friend bool operator< ( const A & a1, const A & a2 ){ 
            return a1.n < a2.n; 
        } 
        friend ostream &  operator<< ( ostream & o, const A & a2 ){ 
            o << a2.n;    
            return o; 
        } 
        friend class MyLess;  
}; 
struct MyLess{ 
    bool operator()( const A & a1, const A & a2) 
    //按个位数比大小
    {  return ( a1.n % 10 ) < (a2.n % 10);  } 
}; 
typedef multiset<A> MSET1;    //MSET1用 "<"比较大小
typedef multiset<A,MyLess> MSET2;  //MSET2用 MyLess::operator()比较大小


int main(){
    // const int SIZE = 6; 
    // A a[SIZE] = { 4,22,19,8,33,40 }; 
    // MSET1 m1;   
    // m1.insert(a,a+SIZE);   
    // m1.insert(22); 
    // cout << "1) " << m1.count(22) << endl;       //输出 1) 2 
    // cout << "2) "; Print(m1.begin(),m1.end());   //输出 2) 4 8 19 22 22 33 40
    // //m1元素:4 8 19 22 22 33 40 
    // MSET1::iterator pp =  m1.find(19); 
    // if( pp != m1.end() ) //条件为真说明找到
    //     cout << "found" << endl; 
    //     //本行会被执行,输出 found 
    // cout << "3) "; cout << * m1.lower_bound(22) << "," <<* m1.upper_bound(22)<< endl;  //输出 3) 22,33 
    // pp = m1.erase(m1.lower_bound(22),m1.upper_bound(22)); //pp指向被删元素的下一个元素
    // cout << "4) "; Print(m1.begin(),m1.end()); //输出 4) 4 8 19 33 40 
    // cout << "5) "; cout << * pp << endl;           //输出 5) 33 
    // MSET2 m2;    // m2里的元素按n的个位数从小到大排m2.insert(a,a+SIZE); 
    // cout << "6) "; Print(m2.begin(),m2.end()); //输出 6) 40 22 33 4 8 19


    //set用法示例

    typedef set<int>::iterator IT; 
    int a[5] = { 3,4,6,1,2 }; 
    set<int> st(a,a+5);    // st里是 1 2 3 4 6 
    pair< IT,bool> result; 
    result = st.insert(5);  // st变成 1 2 3 4 5 6 
    if( result.second )     //插入成功则输出被插入元素
    cout << * result.first  << " inserted" << endl; //输出: 5 inserted 
    if( st.insert(5).second )    
        cout << * result.first  << endl; 
    else 
        cout << * result.first << " already exists" << endl; //输出 5 already exists 
    pair<IT,IT> bounds = st.equal_range(4); 
    cout << * bounds.first << "," << * bounds.second<<endl ;     //输出:4,5


    return 0;
}