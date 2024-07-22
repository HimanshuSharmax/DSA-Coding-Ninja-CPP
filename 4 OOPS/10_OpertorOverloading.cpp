#include<iostream>
using namespace std;

class fraction{
    private :
    int numerator,denominator;

    public :

    fraction(int numerator,int denominator){
       this -> numerator = numerator;
       this -> denominator = denominator; 
    }

    void print(){
        cout<<this -> numerator <<"/"<<denominator<<endl;
    }

    fraction operator+(fraction const f2){                       // Opertor overloading  
        int finalDeno = denominator * f2.denominator;
        int x = finalDeno / denominator;
        int y = finalDeno / f2.denominator;

        int finalNum = x * numerator + (y * f2.numerator);

        fraction fNew(finalNum,finalDeno);                 // Opertor overloading
        return fNew;
    }

    fraction operator*(fraction const f2){
        int n = numerator * f2.numerator;
        int d = denominator * f2.denominator;
        fraction fNew(n,d);
        return fNew;
    }  

    void operator++(){                                 // Pre-Increment
        numerator = numerator + denominator;
    } 

    bool operator==(fraction const f2){
        return (numerator==f2.numerator && denominator==f2.denominator);
    }
};

int main(){
 
    fraction f1(10,2);
    fraction f2(15,4);

    fraction f3 = f1 + f2;              // By operator Overloading
 
    f1.print();
    f2.print();
    f3.print();

    fraction f4 = f1 * f2;
    f1.print();
    f2.print();
    f4.print();

    ++f1;                               // Pre-increment
    f1.print();

    if(f1==f2){
        cout<<"Equal";
    }else{
        cout<<"Not equal";
    }
 
    return 0;
}