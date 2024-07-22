#include<iostream>
using namespace std;

class Sem1{                 // Define this class first for friend fn calling
    public:

    void print();
    
}; 

void Back();

class Enginners{
    public:
    int x;

    protected:
    int y;

    public:
    int z;

    friend void Sem1 :: print();        // Access private and protected property

    friend void Back();

    friend class Sem1;          //(Friend class)Creating whole class friend to access all fn

};

void Sem1 :: print(){
    Enginners marks;
    marks.x = 78;
    marks.y = 59;

    cout<< marks.x <<" "<< marks.y <<endl;
}

void Back(){
    Enginners marks;
    marks.x = 0;
    marks.y = 0;

    cout<< marks.x <<" "<< marks.y <<endl;
}

int main(){
 
    Sem1 s;
    s.print();

    Back();

 
    return 0;
}