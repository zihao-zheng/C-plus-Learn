#include <iostream>
using namespace std;

class Base { 
    public: 
        int i; 
        virtual void Print() { 
            cout << "Base:Print" ; 
        } 
}; 
class Derived : public Base{ 
    public: 
        int n; 
        virtual void Print() {  
            cout <<"Drived:Print" << endl; 
        } 
}; 

class A   { 
    public: 
        virtual void Func() { 
            cout << "A::Func" << endl; 
        } 
}; 
class B:public A  { 
    public: 
        virtual void Func() { 
            cout << "B::Func" << endl; 
        } 
};


int main() { 
    Derived d; 
    cout << sizeof( Base) << ","<< sizeof( Derived )<<endl; //多了四个字节是因为存放了虚函数表,有可能多出更多，是因为对齐的问题
    //虚函数表中存放了所有虚函数的地址
    cout<<endl;
    
    //多态的实现原理
    A a; 
    A * pa = new B(); 
    pa->Func(); //64位程序指针为8字节
    long long * p1 = (long long * ) & a; 
    long long * p2 = (long long * ) pa; 
    * p2 = * p1; //头八个字节（虚函数表存储位置）被覆盖了
    pa->Func();
    cout<<endl;



    return 0; 
}