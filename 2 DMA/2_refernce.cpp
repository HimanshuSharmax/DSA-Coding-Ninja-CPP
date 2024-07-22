#include<iostream>
using namespace std;

void incremeant(int &n){
    n++;
}

int main(){
    int i = 10;

    incremeant(i);
    cout<<i<<endl; 

    int &j = i;                // & reference variable(not creating new addr)
    i++;
    cout<<j<<endl;
    j++;
    cout<<i<<endl;

    int k=100;
    j=k;
    cout<<i<<endl;
}