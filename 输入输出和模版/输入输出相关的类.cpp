/*
 cin对应于标准输入流,用于从键盘读取数据,也可以被重定向为从文件中读取数据。
 cout对应于标准输出流,用于向屏幕输出数据,也可以被重定向为向文件写入数据。


判断输入流结束
int x; 
while(cin>>x){ 
    …..
}

 如果是从文件输入,比如前面有freopen(“some.txt”,”r”,stdin); 那么,读到文件尾部,输入流就算结束
 如果从键盘输入,则在单独一行输入Ctrl+Z代表输入流结束
*/

/*
istream & getline(char * buf, int bufSize); 从输入流中读取bufSize-1个字符到缓冲区buf,或读到碰到‘\n’为止(哪个先到算哪个)。
istream & getline(char * buf, int bufSize,char delim); 从输入流中读取bufSize-1个字符到缓冲区buf,或读到碰到delim字符为止(哪个先到算哪个)。
两个函数都会自动在buf中读入数据的结尾添加\0’。,‘\n’或delim都不会被读入buf,但会被从输入流中取走。如果输入流中‘\n’或delim之前的字符个数达到或超过了bufSize个,就导致读入出错,其结果就是:虽然本次读入已经完成,但是之后的读入就都会失败了。
可以用 if(!cin.getline(…)) 判断输入是否结束

istream类


*/
#include <iostream> 
using namespace std; 

int main(){ 

    //输出重定向
    int x,y; 
    cin >> x >> y; 
    freopen("test.txt","w",stdout);  //将标准输出重定向到 test.txt文件
    if( y == 0 )  //除数为0则在屏幕上输出错误信息
        cerr << "error." << endl; 
    else  
        cout << x /y ; //输出结果到test.txt 

    //输入重定向
    double f; 
    int n; 
    freopen("t.txt","r",stdin);  //cin被改为从 t.txt中读取数据
    cin >> f >> n; 
    cout << f << "," <<n << endl;

    return 0; 
}