#include <iostream>
#include <iomanip>
using namespace std;



int main(){
    int n1 = 141; 
    //1) 分别以十六进制、十进制、八进制先后输出 n  
    cout << "1) " << hex << n1 << " " << dec << n1 << " " << oct << n1 << endl; 
    double x1 = 1234567.89,y1 = 12.34567; 
    //2) 保留5位有效数字
    cout << "2) " << setprecision(5) << x1 << " " << y1 << " " << endl; 
    //3) 保留小数点后面5位
    cout << "3) " << fixed << setprecision(5) <<  x1 << " " << y1 << endl ; //如果超出，四舍五入；如果不够，补0
    //4) 科学计数法输出,且保留小数点后面5位
    cout << "4) " << scientific << setprecision(5) <<x1 << " " << y1 << endl;//scientific表示必须用科学计数法
    //5) 非负数要显示正号,输出宽度为12字符,宽度不足则用'*'填补
    cout << "5) " << showpos << fixed << setw(12) << setfill('*') << 12.1 << endl; //showpos表示非负数显示正号
    //6) 非负数不显示正号,输出宽度为12字符,宽度不足则右边用填充字符填充
    cout << "6) " << noshowpos << setw(12) << left << 12.1 << endl; //noshowpos表示非负数不显示正号
    //7) 输出宽度为12字符,宽度不足则左边用填充字符填充
    cout << "7) " << setw(12) << right << 12.1 << endl; 
    //8) 宽度不足时,负号和数值分列左右,中间用填充字符填充
    cout << "8) " << setw(12) << internal << -12.1 << endl; 
    cout << "9) " << 12.1 << endl;


    return 0;
}