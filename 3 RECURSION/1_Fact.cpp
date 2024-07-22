#include<iostream>
using namespace std;

// int factorial(int n){
//     cout<<n<<endl;
//     if (n==0){
//         return 1;
//     }
//     int smallout= factorial(n-1);
//     return n* smallout;
// }

int factorial(int n){
    if(n==0){
        return 1;
    }
    return n * factorial(n-1);

}

int sum(int n){                            // Sum of n natural numbers
    if(n==0){
        return 0;
    }
    return n + sum(n-1);
}

int main()
{
    int n;
    cout<<"Enter a number "<<endl;
    cin>>n;
    cout<<"The fact of number "<<n<<" is " <<factorial(n)<<endl;
    return 0;
}