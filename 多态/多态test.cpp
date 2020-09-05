#include <iostream>
using namespace std;


//在非构造函数和非析构函数中调用虚函数
//在非构造函数，非析构函数的成员函数中调用虚函数，是多态
class Base { 
    public: 
        void fun1()  { fun2(); } //相当于   this->fun2();由于this指向的是派生类对象，所以调用的是派生类的fun2()
        virtual void fun2()  {   
            cout << "Base::fun2()" << endl;   
        } 
}; 
class Derived:public Base { 
    public: 
        virtual void fun2() { 
            cout << "Derived:fun2()" << endl; 
        } 
};


//构造函数和析构函数中调用虚函数

/*
构造函数和析构函数中调用虚函数
在构造函数和析构函数中调用虚函数,不是多态。编译时即可确定,调用的函数是自己的类或基类中定义的函数,不会等到运行时才决定调用自己的还是派生类的函数。
*/

//只要基类的函数加了virtual,派生类中和基类中同名、同参数表的函数，不加virtual也自动成为虚函数

class myclass { 
    public: 
        virtual void hello(){
            cout<<"hello from myclass"<<endl; 
        }
        virtual void bye(){
            cout<<"bye from myclass"<<endl;
        } 
}; 
class son:public myclass{   
    public: 
        void hello(){ 
            cout<<"hello from son"<<endl;
        }; 
        son(){ 
            hello(); 
        }; 
        ~son(){ 
            bye(); 
        }; 
}; 
class grandson:public son{   
    public: 
        void hello(){
            cout<<"hello from grandson"<<endl;
        }; 
        void bye() { 
            cout << "bye from grandson"<<endl;
        } 
        grandson(){
            cout<<"constructing grandson"<<endl;
        }; 
        ~grandson(){
            cout<<"destructing grandson"<<endl;
        }; 
};

//虚函数的访问权限
class CBase { 
    private: 
        virtual void fun2()  { 
            cout << "Base::fun2()" << endl; 
        } 
}; 
class CDerived:public CBase { 
    public: 
        virtual void fun2() { 
            cout << "Derived:fun2()" << endl; 
        } 
}; 
/*
编译出错是因为 fun2() 是Base的私有成员。即使运行到此时实际上调用的应该是Derived的公有成员 fun2()也不行,因为语法检查是不考虑运行结果的。
如果 将Base中的 private换成public,即使Derived中的fun2() 是private的,编译依然能通过,也能正确调用Derived::fun2()。
*/

int main(){
    //在非构造函数和非析构函数中调用虚函数
    Derived d; 
    Base * pBase = & d; 
    pBase->fun1();
    cout<<endl;

    //构造函数和析构函数中调用虚函数
    grandson gson;
    son * pson;
    pson = &gson;
    pson->hello();//多态
    cout<<endl;

    //虚函数的访问权限
    // CDerived d1; 
    // CBase * pCBase = & d1; 
    // pCBase -> fun2();  // 编译出错
    //cout<<endl;

    return 0;
}