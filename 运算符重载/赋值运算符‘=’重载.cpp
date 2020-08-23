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
        ~String(){delete[]str;}
};
String & String::operator=(const char*s)
{   //重载“=”以使得 obj="hello"能够成立
    delete[]str;
    str=new char[strlen(s)+1];
    strcpy(str,s);
    return * this;
}

int main(){
    String s;
    s="Good Luck,";//等价于s.operator=("Good Luck,");
    cout<<s.c_str()<<endl;
    //String s2="hello!";//error,这是一条初始化语句，不是一条赋值语句
    s="Shenzhou 8!";//等价于 s.operator=("Shenzhou 8!");
    cout<<s.c_str()<<endl;
    return 0;
}