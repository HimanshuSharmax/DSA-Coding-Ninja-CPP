#include<iostream>
using namespace std;
#include<cmath>

int balancedBTs(int h){              // O(2^n)
    if(h <= 1){
        return 1;
    }

    int mod = (int) (pow(10,9) + 7);        // (ans % 10^9 +7)      To store big value 
    int x = balancedBTs(h-1);
    int y = balancedBTs(h-2);

    int temp1 = (int) (( (long)(x) * x) % mod);         // First convert into long then typecast to int
    int temp2 = (int) ((2* (long)(x) * y) % mod);
    int ans =(temp1 + temp2) % mod;

  //  int ans = x*x + 2*x*y;
    return ans;
}

int main(){
 
    int h;
    cin>>h;
    cout<< balancedBTs(h)<<endl;
 
    return 0;
}