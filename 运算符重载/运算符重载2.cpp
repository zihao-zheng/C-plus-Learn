#include <iostream>
using namespace std;

//运算符重载为友元函数
/*
一般情况下，将运算符重载为类的成员函数，是较好的选择
但有时，重载为成员函数不能满足使用需求，重载为普通函数，又不能访问类的私有成员，所以需要将运算符重载为友元
*/
class Complex{
    double real,imag;
    public:
        Complex(double r,double i):real(r),imag(i){ };
        Complex operator+(double r){//能解释c+5,相当于c=c.operator+(5),但不能解释5+c
            return Complex(real+r,imag);
        }
        friend Complex operator+(double r,const Complex & c);
};
Complex operator+(double r,const Complex & c){//将+重载为普通函数，使   5+c 成立
    return Complex(c.real+r,c.imag);
}


//可变长数组类的实现


class  CArray { 
    int size; //数组元素的个数
    int *ptr; //指向动态分配的数组
    public: CArray(int s = 0);     //s代表数组元素的个数
            CArray(CArray & a);
            ~CArray(); 
            void push_back(int v); //用于在数组尾部添加一个元素v 
            CArray & operator=( const CArray & a); //用于数组对象间的赋值
            int length() { return size; } //返回数组元素个数
            int & operator[](int i)  //返回值为 int 不行!不支持 a[i] = 4 
            {//用以支持根据下标访问数组元素,
              // 如n = a[i] 和a[i] = 4; 这样的语句
              //一个函数的调用的返回值，如果不是引用，则不能将其写在左边
              //非引用的函数返回值不可以作为左值使用
              return ptr[i];
            }
};

CArray::CArray(int s):size(s) {//构造函数
    if( s == 0) 
        ptr = NULL; 
    else ptr = new int[s];
}  

CArray::CArray(CArray & a)   {//复制构造函数
     if( !a.ptr) {
          ptr = NULL; 
          size = 0;
          return; 
          }
      ptr = new int[a.size];
       memcpy( ptr, a.ptr, sizeof(int ) * a.size);
        size = a.size; 
}

CArray::~CArray() {  //析构函数
    if( ptr) 
    delete [] ptr; 
     } 

CArray & CArray::operator=( const CArray & a) { //保证 a2 = a3 成立，两边都是CArray对象 
     //赋值号的作用是使“=”左边对象里存放的数组,大小和内容都和右边的对象一样
     if( ptr == a.ptr) //防止a=a这样的赋值导致出错
        return * this; 
     if( a.ptr == NULL) {//如果a里面的数组是空的
           if( ptr ) delete [] ptr;//需要将ptr指向的数组释放
            ptr = NULL; 
            size = 0;
             return * this; 
    }
    if( size < a.size) { //如果原有空间够大,就不用分配新的空间
        if(ptr)         
        delete [] ptr;
        ptr = new int[a.size]; 
    }
    memcpy( ptr,a.ptr,sizeof(int)*a.size); 
    size = a.size; 
    return * this; 
} // CArray & CArray::operator=( const CArray & a)
void CArray::push_back(int v) {  //在数组尾部添加一个元素
    if( ptr) { 
        int * tmpPtr = new int[size+1]; //重新分配空间
        memcpy(tmpPtr,ptr,sizeof(int)*size); //拷贝原数组内容
        delete [] ptr; 
        ptr = tmpPtr;
    } 
    else  //数组本来是空的
        ptr = new int[1]; 
    ptr[size++] = v; //加入新的数组元素
}


int main(){
    CArray a; //开始里的数组是空的
    //要用动态分配的内存来存放数组元素，需要一个指针成员变量
    for( int i = 0;i < 5;++i) 
        a.push_back(i); 
    CArray a2,a3; 
    a2 = a; //要重载“=”
    for( int i = 0; i < a.length(); ++i ) 
        cout << a2[i] << " " ; //重载[]
    a2 = a3; //a2是空的
    for( int i = 0; i < a2.length(); ++i ) //a2.length()返回0 
        cout << a2[i] << " "; 
    cout << endl; 
    a[3] = 100; 
    CArray a4(a);//要自己写复制构造函数 
    for( int i = 0; i < a4.length(); ++i ) 
        cout << a4[i] << " ";
    return 0;
}