#include<iostream>
using namespace std;

int fibo(int n){                            // O(2^n)     Brute-force approch
    if(n <= 1){
        return n;
    }
    int a = fibo(n-1);
    int b = fibo(n-2);
    return a+b;
}

int fibo_Better(int n, int *ans){            // O(n) , Memoization(save cal for nxt) Top-down approch
    if(n <= 1){
        ans[n] = n;     // Save the ans
        return n;
    }

    if(ans[n-1] == 0){
        ans[n-1] = fibo_Better(n-1,ans);
    }
    if(ans[n-2] == 0){
        ans[n-2] = fibo_Better(n-2,ans);
    }

    ans[n] = ans[n-1] + ans[n-2];
    return ans[n];
    
}

int fibo_Better(int n){
    int * ans = new int[n +1];
    for(int i=0; i<=n; i++){
        ans[i] = 0;
    }
    return fibo_Better(n,ans);
}

int  fibo_DP(int n){                    // O(n) ,DP Bottom-up Approch
    int * ans = new int[n +1];
    ans[0] = 0;
    ans[1] = 1;
    for(int i=2; i<=n; i++){
        ans[i] = ans[i-1] + ans[i-2];
    }
    return ans[n];
}

int main(){
 
    int n;
    cin>>n;

    cout<< fibo_Better(n)<<endl;
    cout<< fibo(n)<<endl;
    cout<< fibo_DP(n)<<endl;
 
    return 0;
}