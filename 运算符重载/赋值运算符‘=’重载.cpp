#include <iostream>
using namespace std;

/*
有时，我们希望赋值运算符两边的类型可以不匹配
赋值运算符“=”只能重载为成员函数

*/

class String{
    private:
        char * str;
    public:
        String ():str(new char[1]){str[0]=0;}
        const char*c_str(){return str;}
        String & operator = (const char*s);
        String & operator = (const String &s);
        String(String&s);
        ~String(){delete[]str;}
};
String & String::operator=(const char*s)//重载“=”以使得 obj="hello"能够成立
{   
    delete[]str;
    str=new char[strlen(s)+1];
    strcpy(str,s);
    return * this;
}

// //浅拷贝和深拷贝
// class String{
//     private:
//         char*str;
//     public:
//         String():str(new char[1]){str[0]=0;}
//         const char*c_str(){return str;}
//         String&operator =(const char*s){
//             delete[]str;
//             str=new char[strlen(s)+1];
//             strcpy(str,s);
//             return * this;
//         }
//     String(String&s);
//     ~String(){delete[]str;}
// };
//如果不定义自己的运算符，那么s1=s2实际上导致s1.str和s2.str指向同一个地方
//因此，要在class String里添加成员函数
// String&String:: operator =(const String&s){
//     delete[]str;
//     str=new char[strlen(s.str)+1];
//     strcpy(str,s.str);
//     return * this;
// }

//这样就够了吗？
/*不够！
考虑以下情形：
String s;
s="Hello";
s=s;
因此，还要先判断等号两端的对象是否相同
*/
String&String:: operator =(const String&s){//重载使得   对象=对象   能够成立
    if(this==&s){
        return * this;
    }
    delete[]str;
    str=new char[strlen(s.str)+1];
    strcpy(str,s.str);
    return * this;
}

//上面的String类是否就没有问题了？
//还有问题
/*
考虑到有时会在直接初始化一个对象，而不是赋值一个对象，所以要重写复制构造函数
*/
String::String(String&s){//这里不用判断当前对象是否和现有对象一样，因为当前对象刚刚生成
    str=new char[strlen(s.str)+1];
    strcpy(str,s.str);
}


int main(){
    String s;
    s="Good Luck,";//等价于s.operator=("Good Luck,");
    cout<<s.c_str()<<endl;
    //String s2="hello!";//error,这是一条初始化语句，不是一条赋值语句
    s="Shenzhou 8!";//等价于 s.operator=("Shenzhou 8!");
    cout<<s.c_str()<<endl;

    String s1,s2;
    s1="this";
    s2="that";
    s1=s2;
    return 0;
}