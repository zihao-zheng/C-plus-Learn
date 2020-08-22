#include <iostream>
using namespace std;


//成员对象和封闭类
/*
包含成员对象的类叫封闭类
任何生成封闭类对象的语句，都要让编译器明白，对象中的成员对象，是如何初始化的
*/
class CTyre//轮胎类
{
private:
    int radius;//半径
    int width;//宽度
public:
    CTyre(int r,int w):radius(r),width(w){    cout<<"CTyre constructor"<<endl;    }
    //CTyre不是用无参构造函数初始化的，必须要给两个参数
    ~CTyre(){  cout<<"CTyre destructor"<<endl;  };
};

class CEngine{//引擎类
    public:
        CEngine(){cout<<"CEngine constructor"<<endl;}
        ~CEngine(){cout<<"CEngine destructor"<<endl;}
};

class CCar{//汽车类
    private:
        int price;//价格
        CTyre tyre;
        CEngine engine;//由默认的无参构造函数进行初始化
    public:
        CCar(int p,int tr,int w);
        ~CCar(){
            cout<<"CCar destructor"<<endl;
        }
};

CCar::CCar(int p,int tr,int w):price(p),tyre(tr,w){
//对象成员的构造函数调用次序和对象成员在类中的说明次序一致，与它们在成员初始化列表中出现的次序无关
    cout<<"CCar constructor"<<endl;
};

//封闭类的复制构造函数
class A{
    public:
        A(){cout<<"default"<<endl;}
        A(A&a){cout<<"copy"<<endl;}
};
class B{    A a;    };


//常量对象，常量成员函数和常引用
/*
常量成员函数执行期间不应修改其作用的对象。因此，在常量成员函数中
不能修改成员变量的值（静态成员变量除外），也不能调用同类的非成员函数（静态成员函数除外）
因为非成员函数可能修改成员变量

两个成员函数，名字和参数表都一样，但一个是const,一个不是，算重载
*/

//函数的参数可以使用使用    引用 和 常引用  避免因调用复制构造函数引起的额外开销
//void PrintfObj(Sample & o){   }
//void PrintfObj(const Sample & o){   }     确保函数中不会无意更改o值
int main(){
    CCar car(20000,17,225);
    cout<<endl;
    B b1,b2(b1);
    cout<<endl;
    /*
    构造b1->构造b1.a->类A的无参构造函数
    用b1构造b2->用b1.a构造b2.a->调用A的复制构造函数
    */
    return 0;
}