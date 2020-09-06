#include <string> 
#include <iostream> 
#include <sstream> 
using namespace std;

/*
可以将字符赋值给string对象
string s;
s='n';
*/

string input("Input test 123 4.7 A"); 
istringstream inputString(input); 
string string1, string2; 
int i; 
double d; 
char c; 
inputString >>string1 >> string2 >> i >> d >> c; 
cout << string1 << endl << string2 << endl; 
cout << i << endl << d << endl << c <<endl; 
long L; 
    if(inputString >> L) cout << "long\n"; 
    else cout << "empty\n"; 
/*输出: 
Input 
test 
123 
4.7 
A 
empty
*/ 
ostringstream outputString; 
int a = 10; 
outputString << "This " << a << "ok" << endl; 
cout << outputString.str();