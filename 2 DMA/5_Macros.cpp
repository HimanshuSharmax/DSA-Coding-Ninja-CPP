#include<iostream>
using namespace std;

#define PI 3.14      

int a;                     // Global var

void fun(){
    cout<<a<<endl;
    a++;
}

int main(){
    int r;
    cin>>r;
    cout<<PI*r*r<<endl;

    a=10;
    fun();
    cout<<a<<endl;
}