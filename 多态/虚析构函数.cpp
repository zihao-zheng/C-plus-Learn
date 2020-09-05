/*
虚析构函数
 通过基类的指针删除派生类对象时,通常情况下只调用基类的析构函数
     但是,删除一个派生类的对象时,应该先调用派生类的析构函数,然后调用基类的析构函数。
 解决办法:把基类的析构函数声明为virtual 
     派生类的析构函数可以virtual不进行声明
     通过基类的指针删除派生类对象时,首先调用派生类的析构函数,然后调用基类的析构函数
     一般来说,一个类如果定义了虚函数,则应该将析构函数也定义成虚函数。或者,一个类打算作为基类使用,也应该将析构函数定义成虚函数。
 注意:不允许以虚函数作为构造函数
*/
#include <iostream>
using namespace std;

//执行grandson::~grandson(),引起执行son::~son()!!!
class son{ 
    public: 
        virtual ~son() {
            cout<<"bye from son"<<endl;
        }; 
}; 
class grandson:public son{ 
    public: ~grandson(){
        cout<<"bye from grandson"<<endl;
    }; 
}; 
int main() { 
    son *pson; 
    pson= new grandson(); 
    delete pson; 
    return 0; 
}