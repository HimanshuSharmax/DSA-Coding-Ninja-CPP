#include<iostream>
using namespace std;
#include "1_VehicleClass.cpp"             // By default access modifier is PRIVATE

class car : public vehicle{          // Inherit publically so its inherit only public modifiers
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
   //     cout<<"Max Speed: "<< maxSpeed <<endl;      // Private property doesn't inherit 
    }
};

class bike : protected vehicle{       //(Multiple) Inherit Protected so its convert public into protected so both are protected
    public:
    int numGears;

    void print(){                       
        cout<<"Num Tyres: "<< numTyres <<endl;
        cout<<"Color: "<< color <<endl;
        cout<<"Num Gears: "<< numGears<<endl;
    }
};

class BMW : public car{                 //(MultiLevel) First inherit, vehicle -> car -> BMW

    public:

    BMW(){
        cout<<"BMW Default Constructor!"<<endl;
    }
    ~BMW(){
        cout<<"BMW Destructor!"<<endl;
    }
};

int main(){
 
//    vehicle v;

 //   v.color = "Blue";
 //   v.maxSpeed = 120;                      // Private property doesn't inherit 
 //   v.numTyres = 4;                        // Protectes is assecable only through there drived(child) class

    // car c;
    // c.color = "Red";
    // c.numGears = 5;
 //   c.numTyres = 4;
 //   c.print();


    // bike b;
    // b.color = "Black";                // Public convert into protected
    // b.numGears = 6;
    // b.numTyres = 2;
    // b.print();

    BMW obj;

 
    return 0;
}