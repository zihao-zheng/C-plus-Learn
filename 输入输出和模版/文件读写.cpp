//运行前删掉out.txt文件

#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;



int main(){
    //创建文件

//     ofstream outFile("clients.dat", ios::out|ios::binary);//创建文件
//     /*
//     – clients.dat”要创建的文件的名字
//     – ios::out 文件打开方式,以写文件的方式打开
//         • ios:out 输出到文件, 覆盖原有内容
//         • ios::app  输出到文件, 保留原有内容,总是在尾部添加
//     – ios::binary 以二进制文件格式打开文件
//     */

//    //也可以先创建ofstream对象,再用 open函数打开
//    ofstream fout; 
//    fout.open("test.out",ios::out|ios::binary);//以二进制方式打开
//    //判断是否打开成功
//     if(!fout){
//         cout << "File open error!"<<endl; 
//     }
//     //文件名可以给出绝对路径,也可以给相对路径。没有交代路径信息, 就是在当前文件夹下找文件（可执行程序所在文件夹即为当前文件夹）
//     //      " ..\\..\\tmp\\mydir\\some.txt " 当前文件夹的父文件夹的父文件夹下面的tmp子文件夹里面的…. 
//     //      mac系统书写方式参考  /Users/zhangqilin/Desktop/workspace/vscode/C++学习/输入输出和模版/out.txt
//     //      .. 表示上一层文件夹
//     //文件的读写指针
//     ofstream fout("a1.out",ios::app); //以添加方式打开
//     long location = fout.tellp();      //取得写指针的位置
//     location = 10; 
//     fout.seekp(location); // 将写指针移动到第10个字节处
//     fout.seekp(location,ios::beg); //从头数location     seekp是ofstream的一个成员函数，能把文件的写指针移动到指定位置
//     fout.seekp(location,ios::cur); //从当前位置数location 
//     fout.seekp(location,ios::end); //从尾部数location 

//     ifstream fin("a1.in",ios::ate); //打开文件,定位文件指针到文件尾
//     long location = fin.tellg();   //取得读指针的位置
//     location = 10L; //L标识代表宽字符
//     fin.seekg(location); // 将读指针移动到第10个字节处
//     fin.seekg(location,ios::beg); //从头数location 
//     fin.seekg(location,ios::cur); //从当前位置数location 
//     fin.seekg(location,ios::end); //从尾部数location
    //location 可以为负值

    //字符文件读写
    /*
     因为文件流也是流,所以流的成员函数和流操作算子也同样适用于文件流。
     写一个程序,将文件 in.txt 里面的整数排序后,输出到out.txt


    */
    // vector<int> v; //v是一个可变长的int数组
    // ifstream srcFile("in.txt",ios::in); 
    // ofstream destFile("out.txt",ios::out); 
    // int x; 
    // while( srcFile >> x ) 
    //     v.push_back(x); 
    // sort(v.begin(),v.end()); 
    // for( int i = 0;i < v.size();i ++ ) 
    //     destFile << v[i] << " "; 
    // destFile.close(); 
    // srcFile.close();
    
    //二进制文件读写
    //二进制读文件
    /*
    ifstream 和 fstream的成员函数: istream& read (char* s, long n); 
    将文件读指针指向的地方的n个字节内容,读入到内存地址s,然后将文件读指针向后移动n字节 
    (以ios::in方式打开文件时,文件读指针开始指向文件开头) 。
    */
    istream& read (char* s, long n); 
    //二进制写文件
    /*
    ofstream 和 fstream的成员函数: istream& write (const char* s, long n); 
    将内存地址s处的n个字节内容,写入到文件中写指针指向的位置, 
    然后将文件写指针向后移动n字节(以ios::out方式打开文件时,文件写指针开始指向文件开头, 以ios::app方式打开文件时,文件写指针开始指向文件尾部 ) 。
    */
    istream& write (const char* s, long n);

    //在文件中写入和读取一个整数
    ofstream fout("some.dat", ios::out | ios::binary); 
    int x1=120; 
    fout.write( (const char *)(&x1), sizeof(int) ); 
    fout.close(); 
    ifstream fin("some.dat",ios::in | ios::binary); 
    int y1; 
    fin.read((char * ) & y1,sizeof(int)); 
    fin.close(); 
    cout << y1 <<endl;

    return 0;
}