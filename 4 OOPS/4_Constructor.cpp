#include<iostream>
using namespace std;
#include "1_Class.cpp"

int main(){
 
    phone obj1;                         // Default const.
    obj1.display();                         

    phone obj2(90245);                  // Parametrized const.
    obj2.display();

    phone obj3(997744,25);
    obj3.display();

    phone *obj4 = new phone(86547);     // Parametrized const.(dynamically)
    obj4 -> display();

    phone obj5(9457,20,2303);
    cout<<"Address of object5 : "<< &obj5<<endl;
    obj5.display();
 
    return 0;
}