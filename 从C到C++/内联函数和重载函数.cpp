#include <iostream>
using namespace std;

//内联函数
inline int Max(int a,int b){
    if(a>b) return a;
    return b;
}
//函数重载
//函数名相同，参数表不同


//函数的缺省参数
/*
C++中，定义函数的时候可以让最右边的连续若干个参数有缺省值，
那么调用函数的时候，若相应位置不写参数，参数就是缺省值
*/
void func(int x1,int x2=2,int x3=3){}


int main(){
    func(10);//func(10,2,3);
    func(10,8);//func(10,8,3);
    //func(10,,8)//error,只能最右边的连续若干个参数缺省
    
    return 0;
}