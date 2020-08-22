#include <iostream>
using namespace std;

//友元
//可以将一个类的成员函数（包括构造、析构函数）说明为另一个类的友元
//友元类之间的关系不能传递，不能继承
/*
//友元函数
class CCar;//提前声明，以便后面的CDriver类使用
class CDriver{
    public:
        void ModifyCar(CCar*pCar);//改装汽车
        
};
class CCar{
    private:
        int price;
    friend int MostExpensiveCar(CCar cars[],int total);//声明友元
    friend void CDriver::ModifyCar(CCar*pCar);//声明友元
};
void CDriver::ModifyCar(CCar*pCar){
    pCar->price+=1000;//汽车改装后价值增加
}
int MostExpensiveCar(CCar cars[],int total){
    //求最贵的汽车的价格
    int tmpMax=-1;
    for(int i=0;i<total;i++)
        if(cars[i].price>tmpMax)
            tmpMax=cars[i].price;
    return tmpMax;
}
*/
//友元对象
class CCar{
    private:
        int price;
    friend class CDriver;
};
class CDriver{
    
    public:
    CCar myCar;
        void ModifyCar(){
            //改装汽车
            myCar.price+=1000;//因为是友元，才可访问price
        }
};





int main(){

    return 0;
}