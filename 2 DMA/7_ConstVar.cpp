#include<iostream>
using namespace std;
int main(){
    const int i=10;        // Const int
    int const a=20;
    
    int j=12;
    const int &k=j;        // const reference from a non const int
    j++;

    cout<<k<<endl;
    cout<<j<<endl;

    int const x=10;       // const reference from a const int
    int const &y = x;

    
}