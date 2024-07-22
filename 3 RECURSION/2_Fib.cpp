#include<iostream>
using namespace std;

// int fib(int n){
//     if(n==0){
//         return 0;
//     }
//     if(n==1){
//         return 1;
//     }
//     int smallOut1 = fib(n-1);
//     int smallOut2 = fib(n-2);
//     return smallOut1 +smallOut2;
// }

int fib(int n){
    if(n==0 || n==1){        // base case
        return n;
    }
    return fib(n-1) + fib(n-2);
}
int main()
{   int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    cout<<"The fibonacci series of postion "<<n<<" is "<<fib(n)<<endl;
    
    return 0;
}




