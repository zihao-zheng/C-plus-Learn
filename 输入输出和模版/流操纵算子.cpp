/*
• 整数流的基数:流操纵算子dec（十进制）,oct（八进制）,hex（十六进制）,setbase（指定进制），这类流操纵算子长效，一经设置，只要后面不改，就一直起作用
• 浮点数的精度(precision,setprecision) （有效数字，保留位数）（长效）
• 设置域宽(setw,width) （一次性）
• 用户自定义的流操纵算子

使用流操纵算子需要 #include <iomanip>

控制输入输出的格式

指定输出浮点数的有效位数(非定点方式输出时) 
指定输出浮点数的小数点后的有效位数(定点方式输出时) 
多出的位数采取四舍五入的方式
定点方式:小数点必须出现在个位数后面
*/


/*
设置域宽
•设置域宽(setw,width) 
两者功能相同,一个是成员函数,另一个是流操作算子,调用方式不同: 
cin >> setw(4); 或者 cin.width(5); 
cout << setw(4); 或者 cout.width(5)
宽度设置的有效性是一次性的，每次读入和输出之前都要设置宽度


*/

/*
用户自定义流操纵算子，返回值必须是 ostream 的引用

*/


#include <iostream> 
#include <iomanip> 
using namespace std;

ostream & tab(ostream &output){
        return output<<'\t';
}

int main() { 
    double x = 1234567.89,y = 12.34567; 
    int n = 1234567; 
    int m = 12; 
    cout << setprecision(6) << x << endl << y << endl << n << endl << m;

    cout << setiosflags(ios::fixed) << setprecision(6)//设置小数点后保留6位
     << x << endl << y << endl << n << endl << m<<endl<<endl; 

    cout << setiosflags(ios::fixed) << setprecision(6) << x << endl << //默认为非定点方式输出，改为定点方式输出
    resetiosflags(ios::fixed)  << x ;//取消改为定点方式输出

    //设置域宽
    // int w = 4;     
    // char string[10];    
    // cin.width(5);//输入的域宽为5，因为考虑'\0',所以实际上只读入了四个字符
    // while(cin >> string){ 
    //     cout.width(w++); 
    //     cout << string << endl; //第2次要输出5个字符，而此时String中仅有4个字符，故在前面补空格(缺省情况下补空格)
    //     cin.width(5); 
    // }
    /*
    Sample Input
    1234567890
    
    Sample Output
    1234
     5678
        90

    */
    cout<<endl;
    cout<<"aa"<<tab<<"bb"<<endl;//cout为什么能与 ostream & 发生运算？因为iostream里对<<进行了重载

    cout<<"aa\tbb"<<endl;

    
    return 0; 
    }