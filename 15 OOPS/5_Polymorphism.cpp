#include<iostream>
using namespace std;                      //  Virtual func are present in base class & overReaden in drived class

class Vehicles{
    public:
    string color;

    void print(){                           
        cout<<"Vehicle Print Function"<<endl;
    }

    virtual void print1(){                           // Virtual for Run-time polymorphism
        cout<<"Vehicle Print Function wth of Virtual"<<endl;
    }

 //   virtual void print2() = 0;   // Pure Virtual fn (Now its become Abstract class, So we don't create any obj of this class)

};

class car : public Vehicles{         
    public:
    int numGears;

    void print(){                               // Function Overriding (Compile-time polymorphism)
        cout<<"Car Print Function "<<endl;
    }

    void print1(){                               
        cout<<"Car Print Function wth of Virtual"<<endl;
    }
};

int main(){
 
    Vehicles v;
    car c;
    
    v.print();
    c.print();
 
    Vehicles *v1 = new Vehicles;

    Vehicles *v2;
    // v2 = &v;
    v2 =&c;

    v1 -> print();
    v2 -> print();        // Compilie-time polymorphism, its call its parent

    v2 -> print1();

    return 0;
}