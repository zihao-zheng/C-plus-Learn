#include <iostream>
#include <string>
using namespace std;

//构造函数
//不能有返回值（void也不行）
/*复制构造函数，形如   XX::XX( X& )或X::X(const X& )
复制构造函数被调用的三种情形：用一个类赋值另一个类、函数参数中包含类，函数返回值中包含类（后两种情况需要生成一个临时的对象）
*/
//this指针的作用
class Complex
{
public:
    double real,imag;
    void Print(){
        cout<<real<<","<<imag<<endl;
    }
    Complex AddOne(){
        this->real++;
        this->Print();
        return *this;
    }
    Complex(double r,double i):real(r),imag(i){};
   // ~Complex();
};

class A{
    int i;
    public:
        void Hello(){cout<<"hello"<<endl;}
       // void Hello(){cout<<"hello"<<endl;}出现error,因为不存在"this->i"
};

/*      c++静态成员函数里，为何不能直接使用this指针？
静态成员函数并不是针对某个类的实例对象，而是属于整个类的，为所有的对象实例所共有。
他在作用域的范围内是全局的，独立于类的对象之外的。他只对类内部的静态成员变量做操作。
当实例化一个类的对象时候，里面不存在静态成员的。this指针是相当于一个类的实例的指针，this是用来操作对象实例的内容的，
既然静态成员函数和变量都是独立于类的实例对象之外的，他就不能用this指针。也不能操作非静态成员。再有你要想想设计静态成员的用意在哪里，就会更加明了了

static函数属于类不属于对象（对象里不分配内存），this是对象的指针（指向的是对象分配的内存，所以this访问不到static函数）。
*/


/*静态成员
静态成员变量是放在对象外的，为所有对象所共享，静态成员不需要通过对象就能访问
sizeof()不计算静态成员变量
静态成员变量是全局变量，哪怕一个对象也不存在，类的静态成员变量也存在
！！！必须在定义类的文件中对静态成员变量进行一次声明或初始化，否则虽然编译能通过，链接却不能通过

在静态成员函数中，不能访问非静态成员函数和非静态成员变量

*/

class CRectangle{
    private:
        int w,h;
        static int nTotalArea;
        static int nTotalNumber;//静态成员变量
    public:
        CRectangle(int w_,int h_);
        CRectangle(CRectangle & r);
        ~CRectangle();
        static void PrintTotal();//静态成员函数

};

CRectangle::CRectangle(int w_,int h_){//构造函数
    w=w_;
    h=h_;
    nTotalNumber++;
    nTotalArea+=w*h;
}

CRectangle::~CRectangle(){//析构函数
    nTotalNumber--;
    nTotalArea-=w*h;
}

void CRectangle::PrintTotal(){
    cout<<nTotalNumber<<","<<nTotalArea<<endl;
}

int CRectangle::nTotalNumber=0;
int CRectangle::nTotalArea=0;

//这里看似完美，其实有致命缺陷
/*
我们忽略了复制构造函数，如果用到了复制构造函数，则不走无参构造函数，
nTotalNumber,nTotalArea不会增加，而消亡时走析构函数，这两项减小，故最终这两项的值比实际情况要小。
因此，我们需要为CRectangle类写一个复制构造函数
c++中，必须先声明，后使用，故在写复制构造函数前，必须在类里写上复制构造函数的声明
*/
CRectangle::CRectangle(CRectangle & r){//复制构造函数
       w= r.w; h = r.h;
       nTotalNumber++;
       nTotalArea+=w*h;
    }



int main(){
    Complex c1(1,1),c2(0,0);
    c2=c1.AddOne();
    cout<<endl;
    A*p=NULL;
    p->Hello();
    cout<<endl;

    CRectangle  r1(3,3); 
    CRectangle  r2(2,2);
    //cout<<CRectangle::nTotalNumber;//wrong,static变量归类所私有
    CRectangle::PrintTotal();
    r1.PrintTotal();
    cout<<endl;


    return 0;
}