#include <iostream>
using namespace std;

int n=4;
int  & SetValue(){  return n;   }

//函数参数为常量指针时，可避免函数内部不小心改变该指针指向的内容
void MyPrintf(const char*p){
    //strcpy(p,"this"); //error,strcpy默认第一个参数为char *,而const char *不能转化为char *
    printf("%s",p);
}

int main(){
    // int n;
    // int & r=n;   //引用是从一而终的
    // r=4;
    // cout<<r<<endl;
    // cout<<n<<endl;
    // n=5;
    // cout<<r<<endl;


    //不能通过常引用修改引用的内容
    int n1=100;
    const int & r=n1;
    //r=200;//错误
    n1=300;//没问题


    SetValue()=40;
    cout<<n<<endl;
    //const int和const int & 是两个不同的类型


    //定义常量是，多用const少用define，因为const有类型，便于类型检查
    //不能通过常量指针修改其指向的内容，但常量指针的指向可以变化


    //不能把常量指针赋值给非常量指针，反之可以
    const int * p1;
    int * p2;
    p1=p2;  //ok
    //p2=p1;  //error
    p2=(int *)p1;//ok,强制类型转换


    //动态内存分配与释放 new和delete
    int * pn;
    pn=new int;
    *pn=5;

    int * pm;
    pm=new int[10];

    int * p=new int[20];
    p[0]=1;
    delete []p;
    


    return 0;
}