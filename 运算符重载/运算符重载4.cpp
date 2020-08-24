#include <iostream>
using namespace std;

//自增、自减运算符的重载
class CDemo { 
    private : 
        int n; 
    public: 
        CDemo(int i=0):n(i) { } 
        CDemo & operator++();      //用于前置形式
        CDemo operator++( int );   //用于后置形式
        operator int ( ) { return n; } 
        friend CDemo & operator--(CDemo & ); 
        friend CDemo operator--(CDemo & ,int);    
}; 
CDemo & CDemo::operator++() { //前置 ++ 
    n ++; 
    return * this; 
}  // ++s即为: s.operator++(); 
CDemo CDemo::operator++( int k ) { //后置 ++ 
    CDemo tmp(*this); //记录修改前的对象
    n ++; 
    return tmp; //返回修改前的对象
} // s++即为: s.operator++(0); 
CDemo & operator--(CDemo & d) {//前置-- 
    d.n--; 
    return d; 
} //--s即为: operator--(s); 
CDemo operator--(CDemo & d,int) {//后置-- 
    CDemo tmp(d); 
    d.n --; 
    return tmp;  
} //s--即为: operator--(s, 0);


int main(){
    CDemo d(5); 
    cout << (d++ ) << ",";  //等价于 d.operator++(0); 
    cout << d << ","; 
    cout << (++d) << ",";   //等价于 d.operator++(); 
    cout << d << endl; 
    cout << (d-- ) << ",";  //等价于 operator--(d,0); 
    cout << d << ","; 
    cout << (--d) << ",";   //等价于 operator--(d); 
    cout << d << endl; 

    return 0;
}