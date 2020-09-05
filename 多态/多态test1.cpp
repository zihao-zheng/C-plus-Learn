#include <iostream>
using namespace std;

//虚析构函数
/*
虚析构函数
 通过基类的指针删除派生类对象时,通常情况下只调用基类的析构函数
     但是,删除一个派生类的对象时,应该先调用派生类的析构函数,然后调用基类的析构函数。
 解决办法:把基类的析构函数声明为virtual 
     派生类的析构函数可以virtual不进行声明
     通过基类的指针删除派生类对象时,首先调用派生类的析构函数,然后调用基类的析构函数
  一般来说,一个类如果定义了虚函数,则应该将析构函数也定义成虚函数。或者,一个类打算作为基类使用,也应该将析构函数定义成虚函数。
 注意:不允许以虚函数作为构造函数
*/

class son{ 
    public: 
        virtual ~son() {
            cout<<"bye from son"<<endl;
            }
}; 
class grandson:public son{ 
    public: 
        ~grandson(){
            cout<<"bye from grandson"<<endl;
        }
}; 

//纯虚函数和抽象类
/*包含纯虚函数的类叫抽象类
 抽象类只能作为基类来派生新类使用,不能创建独立的抽象类的对象
 抽象类的指针和引用可以指向由抽象类派生出来的类的对象

 在抽象类的成员函数内可以调用纯虚函数,但是在构造函数或析构函数内部不能调用纯虚函数。
 如果一个类从抽象类派生而来,那么当且仅当它实现了基类中的所有纯虚函数,它才能成为非抽象类。(所有纯虚函数都要实例化)
*/
class A { 
    public: 
        virtual void f() = 0; //纯虚函数
        void g( ) { 
            this->f( ) ; //ok，多态
        } 
        A( ){   
            //f( ); // 错误
        } 
}; 
class B:public A{ 
    public: 
        void f(){
            cout<<"B:f()"<<endl; 
        } 
}; 


int main() { 
    son *pson; 
    pson= new grandson(); 
    delete pson; 
    cout<<endl;

    B b; 
    b.g();
    cout<<endl;

    return 0; 
}

