#include <iostream>
using namespace std;

//函数模版
template <class T> 
void Swap(T & x,T & y) { 
    T tmp = x; 
    x = y; 
    y = tmp; 
}

//函数模版中可以有不止一个类型参数
template <class T1, class T2> 
T2 print(T1 arg1, T2 arg2) { 
    cout<< arg1 << " "<< arg2<<endl;  
    return arg2; 
}

//求数组最大元素的MaxElement函数模板
template <class T> 
T MaxElement(T a[], int size){ //size是数组元素个数 
    T tmpMax = a[0]; 
    for( int i = 1;i < size;++i) 
        if( tmpMax < a[i] ) 
            tmpMax = a[i]; 
    return tmpMax; 
}

//不通过参数实例化函数模版
template <class T> 
T Inc(T n) { 
    return 1 + n; 
}

//函数模版的重载
//函数模板可以重载,只要它们的形参表或类型参数表不同即可。
template<class T1, class T2> 
void print(T1 arg1, T2 arg2) { 
    cout<< arg1 << " "<< arg2<<endl;  
} 
template<class T> 
void print(T arg1, T arg2) { 
    cout<< arg1 << " "<< arg2<<endl;  
} 

template<class T,class T2> 
void print(T arg1, T arg2) { 
    cout<< arg1 << " "<< arg2<<endl;  
}

/*
函数模板和函数的次序
在有多个函数和函数模板名字相同的情况下,编译器如下处理一条函数调用语句
1) 先找参数完全匹配的普通函数(非由模板实例化而得的函数)。
2) 再找参数完全匹配的模板函数。
3) 再找实参数经过自动类型转换后能够匹配的普通函数。
4) 上面的都找不到,则报错。
*/
template <class T> 
T Max( T a, T b)  { 
    cout << "TemplateMax" <<endl;     
    return 0; 
} 
template <class T,class T2> 
T Max( T a, T2 b) { 
    cout << "TemplateMax2" <<endl;    
    return 0; 
} 
double Max(double a, double b){ 
    cout << "MyMax" << endl; 
    return 0; 
}

//匹配模板函数时,不进行类型自动转换
template<class T> 
T myFunction( T arg1, T arg2) { 
    cout<<arg1<<"   "<<arg2<<"\n"; 
    return arg1;
}

//函数模版示例：Map
template<class T,class Pred> //将s到e的数值经op变换存到x处
void Map(T s, T e, T x, Pred op) { 
    for(; s != e; ++s,++x) { 
        *x = op(*s); 
    } 
} 
int Cube(int x) { 
    return x * x * x; 
} 
double Square(double x) { 
    return x * x; 
}
int a[5] = {1,2,3,4,5}, b[5]; 
double d[5] = { 1.1,2.1,3.1,4.1,5.1} , c[5];


//类模版示例：Pair类模版
template <class T1,class T2> 
class Pair { 
    public: T1 key;  //关键字
    T2 value;     //值
    Pair(T1 k,T2 v):key(k),value(v) { }; 
    bool operator < ( const Pair<T1,T2> & p) const; 
}; 
template<class T1,class T2> 
bool Pair<T1,T2>::operator < ( const Pair<T1,T2> & p) const
 //Pair的成员函数 operator < 
 { 
     return key < p.key;   
 }

//用类模版定义对象
//编译器由类模板生成类的过程叫类模板的实例化。由类模板实例化得到的类,叫模板类。
/*同一个类模板的两个模板类是不兼容的
Pair<string,int> * p; 
Pair<string,double> a; 
p = & a; //wrong
*/

//函数模版作为类模版成员
template <class T> class A { 
    public: 
        template<class T2>  
        void Func( T2 t) { cout << t; } //成员函数模板
};

//类模板的“<类型参数表>”中可以出现   非类型参数: 
template <class T, int size> 
class CArray{ 
        T  array[size]; 
    public: 
        void Print( ) { 
            for( int i = 0;i < size; ++i) 
            cout << array[i] << endl; 
        } 
}; 
CArray<double,40> a2; 
CArray<int,50> a3;      //a2和a3属于不同的类


int main(){
    int n = 1,m = 2; 
    Swap(n,m); //编译器自动生成 void Swap(int & ,int & )函数
    cout<<n<<" "<<m<<endl;
    double f = 1.2,g = 2.3; 
    Swap(f,g); //编译器自动生成 void Swap(double & ,double & )函数
    cout<<f<<" "<<g<<endl;
    //不通过参数实例化函数模版
    cout << Inc<double>(4)/2<<endl;  //输出 2.5
    
    //函数模版的重载
    int i=4, j=5; 
    Max( 1.2,3.4); // 输出MyMax 
    Max(i, j);  //输出TemplateMax 
    Max( 1.2, 3); //输出TemplateMax2

    myFunction( 5, 7); //ok:replace T with int 
    myFunction( 5.8, 8.4); //ok: replace T with double 
    //myFunction( 5, 8.4); //error,no matching function for call to 'myFunction(int, double)'

    Map(a,a+5,b,Square); //求平方
    for(int i = 0;i < 5; ++i) 
        cout << b[i] << ","; 
        cout << endl; 
    Map(a,a+5,b,Cube); //求立方
    for(int i = 0;i < 5; ++i) 
        cout << b[i] << ","; 
        cout << endl; 
    Map(d,d+5,c,Square); 
    for(int i = 0;i < 5; ++i) 
        cout << c[i] << ","; 
        cout << endl;

    //类模版示例：Pair类模版
    Pair<string,int> student("Tom",19); 
    //实例化出一个类 Pair<string,int> 
    cout << student.key << " " << student.value;

    //函数模版作为类模版成员
    A<int> a; 
    a.Func('K'); //成员函数模板 Func被实例化
    a.Func("hello"); //成员函数模板 Func再次被实例化


    return 0;
}