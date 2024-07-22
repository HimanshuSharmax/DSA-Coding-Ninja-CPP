#include<iostream>
using namespace std;
int main(){
    int i=10;
    int * p = &i;

    cout<<sizeof(p)<<endl;
    cout<<i<<endl;
    cout<<&i<<endl;        // print addr of i   (addr of i and p same)
    cout<<p<<endl;         // print addr of p
    cout<<*p<<endl;        // print value of i

    i++;
    cout<<i<<endl;
    cout<<*p<<endl;        

    int a=i;                // Here i and *p same
    a++;
    cout<<a<<endl;
    cout<<*p<<endl; 

    i=256;
    cout<<i<<endl;
    cout<<*p<<endl; 
    *p=4799;
    cout<<i<<endl;
    cout<<*p<<endl; 

    (*p)++;
    cout<<i<<endl;
    cout<<*p<<endl; 

    int * q =p;
    cout<<*q<<endl;





    



    
}