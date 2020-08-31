#include <iostream> 
#include <string> 
using namespace std; 

//继承关系和复合关系
/*
继承关系描述有共同特征的同类型的东西，复合关系表示有相互作用、从属等关系的两个不同的事物
eg:
CUndergraduateStudent是CStudent的继承，是继承关系
小区中人与狗的关系是复合关系
*/


//学籍管理程序
class CStudent { 
    private: 
        string name; 
        string id;  //学号
        char gender; //性别,'F'代表女,'M'代表男
        int age; 
    public: 
        void PrintInfo(); 
        void SetInfo( const string & name_,const string & id_, int age_,char gender_ ); 
        string GetName() {  return name;  } 
};  
class CUndergraduateStudent:public CStudent {//本科生类,继承了CStudent类，public继承
    private: 
        string department; //学生所属的系的名称
    public: 
        void QualifiedForBaoyan() {   //给予保研资格    
            cout << "qualified for baoyan" << endl; 
        } 
        void PrintInfo() { 
            CStudent::PrintInfo(); //调用基类的PrintInfo 
            cout << "Department:" << department <<endl; 
        } 
        void SetInfo( const string & name_,const string & id_, int age_,char gender_ ,const string &  department_) { 
            CStudent::SetInfo(name_,id_,age_,gender_); //调用基类的SetInfo 
            department = department_; 
            } 
};
void CStudent::PrintInfo() { 
    cout << "Name:" << name << endl;
    cout << "ID:" << id << endl;
    cout << "Age:" << age << endl; 
    cout << "Gender:" << gender << endl; 
} 
void CStudent::SetInfo( const string & name_,const string & id_,   int age_,char gender_ ) {
    name = name_; 
    id = id_; 
    age = age_; 
    gender = gender_; 
}

//派生类的构造函数
class Bug  { 
    private : 
        int nLegs;     
        int nColor; 
    public: 
        int nType; 
        Bug (  int legs, int color); 
        void PrintBug (){ }; 
}; 
class FlyBug: public Bug {// FlyBug是Bug的派生类 
    int nWings; 
    public: 
        FlyBug( int legs,int color, int wings); 
}; 
Bug::Bug( int legs, int color) { 
    nLegs = legs; nColor = color; 
} 
//错误的FlyBug构造函数
// FlyBug::FlyBug ( int legs,int color, int wings) { 
//     nLegs = legs;     // 不能访问
//     nColor = color;  // 不能访问
//     nType = 1; // ok 
//     nWings = wings; 
// } 
//正确的FlyBug构造函数: 
FlyBug::FlyBug ( int legs, int color, int wings):Bug(legs, color) { nWings = wings; }


/*
创建封闭类派生类的对象时: 1) 先执行基类的构造函数,用以初始化派生类对象中从基类继承的成员; 2) 再执行成员对象类的构造函数,用以初始化派生类对象中成员对象。
3) 最后执行派生类自己的构造函数
封闭派生类对象消亡时: 1) 先执行派生类自己的析构函数2) 再依次执行各成员对象类的析构函数3) 最后执行基类的析构函数析构函数的调用顺序与构造函数的调用顺序相反
*/

//public继承的赋值兼容规则
/*
class base {  }; 
class derived : public base {   }; 
base b; 
derived d; 
1) 派生类的对象可以赋值给基类对象   b = d; 
2) 派生类对象可以初始化基类引用 base & br = d; 
3) 派生类对象的地址可以赋值给基类指针   base * pb = & d; 
如果派生方式是 private或protected,则上述三条不可行。
*/

//基类与派生类的指针强制转换

class Base { 
    protected: 
        int n; 
    public: 
        Base(int i):n(i){ 
            cout << "Base " << n << " constructed" << endl; 
        }
        ~Base() { 
            cout << "Base " << n << " destructed" << endl; 
        } 
        void Print() { 
            cout << "Base:n=" << n << endl;
        } 
}; 
class Derived:public Base  {
    public: 
        int v; 
        Derived(int i):Base(i),v(2 * i) {  
            cout << "Derived constructed" << endl;  
        } 
        ~Derived() {  cout << "Derived destructed" << endl; } 
        void Func() { } ; 
        void Print() { 
            cout << "Derived:v=" << v << endl; cout << "Derived:n=" << n << endl; 
        } 
};  



int main() { 
    CUndergraduateStudent s2; 
    s2.SetInfo("Harry Potter ",  "118829212",19,'M',"Computer Science"); 
    cout <<  s2.GetName() << " " ; 
    s2.QualifiedForBaoyan (); 
    s2.PrintInfo ();
    cout<<endl; 

    //派生类的构造函数
    FlyBug fb ( 2,3,4); 
    fb.PrintBug(); 
    fb.nType = 1; 
    //fb.nLegs = 2 ;  // error.  nLegs is private
    cout<<endl;

    Base objBase(5); 
    Derived objDerived(3); 
    Base * pBase = & objDerived ;
    //pBase->Func(); //err;Base类没有Func()成员函数
    //pBase->v = 5; //err; Base类没有v成员变量
    pBase->Print(); 
    //Derived * pDerived = & objBase; //error 
    Derived * pDerived = (Derived *)(& objBase); 
    pDerived->Print();  //慎用,可能出现不可预期的错误
    pDerived->v = 128; //往别人的空间里写入数据,会有问题
    objDerived.Print();
    cout<<endl;

    



    return 0; 
}