#include<iostream>
using namespace std;
#include "1_Class.cpp"
int main(){
 
    phone obj1(92001,25);
    obj1.display();

    phone obj2(obj1);           // Copy Const.
    obj2.display();

    phone *obj3 = new phone(78456,36);
    obj3 -> display();

    phone obj4(*obj3);
    phone *obj5 = new phone(*obj3);
    phone *obj6 = new phone(obj1);

    *obj3 = obj1;               // copy assignment opertor(=)

    phone obj7 = obj1;

    delete obj3;
    delete obj5;
    delete obj6;
 
    return 0;
}