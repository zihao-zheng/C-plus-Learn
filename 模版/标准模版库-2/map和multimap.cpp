#include <iostream> 
#include <map> 
using namespace std; 

//multimap例题
/*
一个学生成绩录入和查询系统, 接受以下两种输入: 

Add name id score 
Query score 

1.name是个字符串,中间没有空格,代表学生姓名。id是个整数,代表学号。score是个整数,表示分数。学号不会重复,分数和姓名都可能重复。
2.两种输入交替出现。第一种输入表示要添加一个学生的信息,碰到这种输入,就记下学生的姓名、id和分数。
第二种输入表示要查询,碰到这种输入,就输出已有记录中分数比score低的最高分获得者的姓名、学号和分数。
如果有多个学生都满足条件,就输出学号最大的那个学生的信息。如果找不到满足条件的学生,则输出“Nobody”

输入样例: 
Add Jack 12  78 
Query 78 
Query 81 
Add Percy 9  81 
Add Marry 8  81 
Query 82 
Add Tom 11 79 
Query 80 
Query 81 

输出结果样例: 
Nobody 
Jack 12 78 
Percy 9 81 
Tom 11 79 
Tom 11 79


*/

class CStudent { 
    public: 
        struct CInfo //类的内部还可以定义类
        { int id; string name; }; 
        int score; 
        CInfo info; //学生的其他信息
}; 
typedef multimap<int, CStudent::CInfo> MAP_STD;

//map示例
template <class Key,class Value> 
ostream & operator <<( ostream & o, const pair<Key,Value> & p) { 
    o << "(" << p.first << "," << p.second << ")"; 
    return o; 
}


int main()    { 
    // typedef multimap<int,double,less<int> > mmid; 
    // mmid pairs; 
    // cout << "1) " << pairs.count(15) << endl; 
    // pairs.insert(mmid::value_type(15,2.7));//typedef pair<const Key, T> value_type; 
    // pairs.insert(mmid::value_type(15,99.3)); 
    // cout << "2) " << pairs.count(15) << endl;  //求关键字等于某值的元素个数
    // pairs.insert(mmid::value_type(30,111.11)); 
    // pairs.insert(mmid::value_type(10,22.22));
    // pairs.insert(mmid::value_type(25,33.333)); 
    // pairs.insert(mmid::value_type(20,9.3)); 
    // for( mmid::const_iterator i = pairs.begin(); i != pairs.end() ;i ++ ) 
    //     cout << "(" << i->first << "," << i->second << ")" << ","<<endl;

    //multimap例题
    MAP_STD mp; 
    CStudent st; 
    string cmd; 
    // while( cin >> cmd ) { 
    //     if( cmd == "Add") { 
    //         cin >> st.info.name >> st.info.id >> st.score ; 
    //         mp.insert(MAP_STD::value_type(st.score,st.info )); 
    //         //mp.insert(make_pair(st.score,st.info )); 也可以
    //     } 
    //     else if( cmd == "Query" ){ 
    //         int score; 
    //         cin >> score; 
    //         MAP_STD::iterator p = mp.lower_bound (score); 
    //         if( p!= mp.begin()) { 
    //             --p; score = p->first; //比要查询分数低的最高分
    //             MAP_STD::iterator maxp = p; 
    //             int maxId = p->second.id;
    //             for( ; p != mp.begin() && p->first == score; --p) { //遍历所有成绩和score相等的学生
    //                 if( p->second.id > maxId ) { 
    //                     maxp = p; maxId = p->second.id ; 
    //                 } 
    //             } 
    //             if( p->first == score) { //如果上面循环是因为 p == mp.begin() 
    //                                     // 而终止,则p指向的元素还要处理
    //             if( p->second.id  > maxId ) { 
    //                 maxp = p; 
    //                 maxId = p->second.id ; 
    //             } 
    //     }
    //     cout << maxp->second.name << " " << maxp->second.id << " "       
    //      << maxp->first << endl; } else //lower_bound的结果就是 begin,说明没人分数比查询分数低
    //     cout << "Nobody" << endl; 
    //     } 
    // } 
    
    typedef map<int, double,less<int> > mmid;
    mmid pairs; 
    cout << "1) " << pairs.count(15) << endl; 
    pairs.insert(mmid::value_type(15,2.7)); 
    pairs.insert(make_pair(15,99.3)); //make_pair生成一个pair对象
    cout << "2) " << pairs.count(15) << endl; 
    pairs.insert(mmid::value_type(20,9.3)); 
    mmid::iterator i; cout << "3) "; 
    for( i = pairs.begin(); i != pairs.end();i ++ ) 
        cout << * i  << ","; cout << endl; 
    cout << "4) "; 
    int n =  pairs[40];//如果没有关键字为40的元素,则插入一个
    for( i = pairs.begin(); i != pairs.end();i ++ ) 
        cout << * i  << ","; cout << endl; cout << "5) "; 
    pairs[15] = 6.28; //把关键字为15的元素值改成6.28 
    for( i = pairs.begin(); i != pairs.end();i ++ ) 
        cout << * i  << ",";

    return 0;
     
}