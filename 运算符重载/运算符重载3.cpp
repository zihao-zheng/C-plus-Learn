#include <iostream>
using namespace std;

//流插入运算符和流提取运算符的重载
//cout是在iostream中定义的ostream类的对象
class CStudent{
    public: int nAge;
};
ostream&operator<<(ostream&o,const CStudent &s){    //ostream&o,如果不写&，则编译不过，是因为一些其他的原因
    o<<s.nAge;
    return o;
}

//假定c是Complex复数类的对象,现在希望写“cout << c;”,
//就能以“a+bi”的形式输出c的值,写“cin>>c;”,
//就能从键盘接受“a+bi”形式的输入,并且使得c.real = a,c.imag = b。

class Complex   { 
    double real,imag; 
    public:
     Complex( double r=0, double i=0):real(r),imag(i){ }; 
     friend ostream & operator<<( ostream & os, const Complex & c); 
     friend istream & operator>>( istream & is,Complex & c);   
}; 
ostream & operator<<( ostream & os,const Complex & c) { 
    os << c.real << "+" << c.imag << "i"; //以"a+bi"的形式输出
    return os; 
} 
istream & operator>>( istream & is,Complex & c) {
     string s; is >> s;  //将"a+bi"作为字符串读入, “a+bi” 中间不能有空格
     int pos = s.find("+",0); 
     string sTmp = s.substr(0,pos); //分离出代表实部的字符串
     c.real = atof(sTmp.c_str()); //atof库函数能将const char*指针指向的内容转换成 float 
     sTmp = s.substr(pos+1, s.length()-pos-2);  //分离出代表虚部的字符串
     c.imag = atof(sTmp.c_str()); 
     return is; 
}

//重载类型转换运算符
class Complex1 {
     double real,imag;
      public:
       Complex1(double r=0,double i=0):real(r),imag(i) { }; 
       operator double () { 
           return real;
        } //重载强制类型转换运算符 double 
};


int main(){
    CStudent s;
    s.nAge=5;
    cout<<s<<"hello"<<endl;

    Complex c;
    int n;
    cin >> c >> n;
    cout << c << "," << n;
    //输入13.2+133i 87
    //输出13.2+133i,87

    Complex1 c1(1.2,3.4); 
    cout << (double)c1 << endl; //输出 1.2 
    double n = 2 + c1; //等价于 double n=2+c.operator double() 
    cout << n; //输出 3.2

    
    return 0;
}