#include<iostream>
using namespace std;
int main(){
    int i=10;
    int*p1=&i;
    int**p2=&p1;

    cout<<p2<<endl;
    cout<<&p1<<endl;

    cout<<p1<<endl;
    cout<<*p2<<endl;
    cout<<&i<<endl;

    cout<<i<<endl;
    cout<<*p1<<endl;
    cout<<**p2<<endl;
}