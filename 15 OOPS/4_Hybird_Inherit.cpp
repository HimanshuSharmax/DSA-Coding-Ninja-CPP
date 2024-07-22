#include<iostream>                                       //         A           
#include<string>                                         //     B       C      Multilevel
using namespace std;                                     //         D          Multiple
#include"1_VehicleClass.cpp"                             //    Hybird (Diamand)

class car : virtual public vehicle{          // Inherit publically so its inherit only public modifiers
    public:
    int numGears;

    car() : vehicle(75){                              // Implicit child class call its parent class constructor first
        cout<<"Car's Default Constructor!"<<endl;
    }
    ~car(){
        cout<<"Car's Destructor!"<<endl;
    }

    void print(){
        cout<<"Num Tyres: "<< numTyres <<endl;
        cout<<"Color: "<< color <<endl;
        cout<<"Num Gears: "<< numGears<<endl;
    }
};

// virtual two class pass one copy
class truck :virtual protected vehicle{       // Inherit Protected so its convert public into protected so both are protected
    public:
    int numGears;

    truck(){
        cout<<"Truck's default constructor"<<endl;
    }
    void print(){
        cout<<"Truck Print func"<<endl;
    }
};

class Bus : public car, public truck{    
    public:

    Bus(){
        cout<<"Bus's default constructor"<<endl;
    }
};

int main(){
 
    Bus b;

    b.car :: print();
    b.truck :: print();
 
    return 0;
}