#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<functional>
#include<list>
using namespace std;

//函数对象
//若一个类重载了运算符“（）”，则该类的对象就称为函数对象
//是个对象,但是用起来看上去象函数调用,实际上也执行了函数调用。

class CMyAverage { 
    public: 
        double operator()( int a1, int a2, int a3 ) { //重载 () 运算符
            return (double)(a1 + a2+a3) / 3; 
        } 
};

int SumSquares( int total, int value) { 
    return total + value * value;   
} 
template <class T> void PrintInterval(T first, T last) { 
    //输出区间[first,last)中的元素
    for( ; first != last; ++ first) 
        cout << * first << " "; cout << endl; 
}
template<class T> class SumPowers { 
    private: 
        int power; 
    public: SumPowers(int p):power(p) { } 
    const T  operator() ( const T & total, const T & value) { //计算 value的power次方,加到total上
        T v = value; 
        for( int i = 0;i < power - 1; ++ i) 
            v = v * value;  
        return total + v; 
    } 
};

//STL中的函数对象类模版     头文件 <functional>
//equal_to      greater     less //这些函数模版可以用来生成函数对象

// class MyLess { 
//     public: 
//         bool  operator()( const int & c1, const int & c2 ) { 
//             return (c1 % 10) < (c2 % 10); 
//         } 
// };


//写出MyMax模版

template <class T, class Pred> //T可以是一个迭代器 
T MyMax( T * p, int n, Pred myless) { 
    T tmpmax = p[0]; 
    for( int i = 1;i < n;i ++ ) 
        if( myless(tmpmax,p[i])) 
            tmpmax = p[i]; 
    return tmpmax;                         
};

class MyLess { 
    public:    
        bool operator() (int a1,int a2) { 
            if( ( a1 % 10 ) < (a2%10) ) 
                return true; 
            else 
                return false; 
        } 
}; 
bool MyCompare(int a1,int a2) { 
    if( ( a1 % 10 ) < (a2%10) ) 
        return false; 
    else 
        return true;  
}


int main(){
    // CMyAverage average;  //函数对象
    // cout << average(3,2,3);  
    // //average.operator()(3,2,3);用起来看上去象函数调用 输出 2.66667
    // cout<<endl;

    // const int SIZE = 10; 
    // int a1[] = { 1,2,3,4,5,6,7,8,9,10 }; 
    // vector<int> v(a1,a1+SIZE); cout << "1) "; 
    // PrintInterval(v.begin(),v.end()); 
    // int result = accumulate(v.begin(),v.end(),0,SumSquares); 
    // cout << "2) 平方和:" << result << endl; 
    // result = accumulate(v.begin(),v.end(),0,SumPowers<int>(3));  
    // cout << "3) 立方和:" << result << endl; 
    // result = accumulate(v.begin(),v.end(),0,SumPowers<int>(4));  
    // cout << "4) 4次方和:" << result<<endl;

//greater函数对象类模版
/*
list不能直接用STL中的sort(),要用自己的sort()函数
list 有两个sort函数,前面例子中看到的是不带参数的sort函数,它将list中的元素按 < 规定的比较方法 升序排列。
list还有另一个sort函数: 
    template <class T2> 
    void sort(T2 op); 
    可以用 op来比较大小,即 op(x,y) 为true则认为x应该排在前面。
*/
    // const int SIZE = 5; 
    // int a[SIZE] = {5,21,14,2,3}; 
    // list<int> lst(a,a+SIZE); 
    // lst.sort(MyLess()); //MyLess对象使用无参构造函数初始化
    // ostream_iterator<int> output(cout,","); 
    // copy( lst.begin(),lst.end(),output); 
    // cout << endl; 
    // lst.sort(greater<int>()); //greater<int>()是个对象
    //                         //本句进行降序排序
    // copy( lst.begin(),lst.end(),output); cout << endl;

    int a[] = {35,7,13,19,12}; 
    cout << MyMax(a,5,MyLess()) << endl; 
    cout << MyMax(a,5,MyCompare) << endl;    



    return 0;
}