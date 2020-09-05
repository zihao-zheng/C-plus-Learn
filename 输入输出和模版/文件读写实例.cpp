#include <iostream>
#include <fstream>
using namespace std;

//从键盘输入几个学生的姓名的成绩,并以二进制文件形式保存
struct Student{
    char name[20];
    int score;
};


int main(){
    Student s; 
    //写入信息
    // ofstream OutFile( "students.dat",ios::out|ios::binary); 
    // while( cin >> s.name >> s.score ) 
    //     OutFile.write( (char * ) & s, sizeof( s) ); 
    // OutFile.close();
    /*输入
    Tom 60 
    Jack 80 
    Jane 40 
    <^Z+回车>
    */
   //读取信息
    ifstream inFile("students.dat",ios::in | ios::binary ); 
    if(!inFile) { 
        cout << "error" <<endl; 
        return 0; 
    } 
    while( inFile.read( (char* ) & s, sizeof(s) ) ) { 
        int readedBytes = inFile.gcount(); //看刚才读了多少字节
        cout << s.name << " " << s.score << endl; 
    } 
    inFile.close();
    //修改信息
    fstream iofile( "students.dat", ios::in|ios::out|ios::binary); 
    if( !iofile) { 
        cout << "error" ; return 0; 
    } 
    iofile.seekp( 2 * sizeof(s),ios::beg);  //定位写指针到第三个记录
    iofile.write("Mike",strlen("Mike")+1); //+1是为了写\0
    iofile.seekg(0,ios::beg); //定位读指针到开头
    while( iofile.read( (char* ) & s, sizeof(s)) ) 
        cout << s.name << " " << s.score << endl; 
    iofile.close();

    return 0;
}