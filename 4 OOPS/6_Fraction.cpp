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

    void add(fraction f2){
        int finalDeno = denominator * f2.denominator;
        int x = finalDeno / denominator;
        int y = finalDeno / f2.denominator;

        int finalNum = x * numerator + (y * f2.numerator);
        numerator = finalNum;
        denominator = finalDeno;
    }

    void multiply(fraction f2){
        numerator = numerator * f2.numerator;
        denominator = denominator * f2.denominator;
    }
    
};

int main(){
 
    fraction f1(10,2);
    fraction f2(15,4);

    f1.add(f2);
 
    f1.print();
    f2.print();

    f1.multiply(f2);
    f1.print();
    f2.print();
 
    return 0;
}