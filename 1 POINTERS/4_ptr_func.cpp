#include<iostream>
using namespace std;

void print(int*a){
    cout<<*a<<endl;
}

void incrementPointer(int*a){
    a=a+1;
}

void increment(int*a){
    (*a)++;
}

int sum(int r[],int size){
    cout<<sizeof(r)<<endl;
    return 0;
}

int main(){
    int i=10;
    int*p=&i;

    print(p);

    cout<<p<<endl;
    incrementPointer(p);
    cout<<p<<endl;

    cout<<*p<<endl;
    increment(p);
    cout<<*p<<endl;

    int r[10];
    cout<<sizeof(r)<<endl;
    cout<<sum(r,10)<<endl;

}