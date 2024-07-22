#include<iostream>
#include<climits>
using namespace std;

int minSteps(int n){        // O(3^n)                  Brute-force approch
    if(n == 1){             // Base case
        return 0;
    }

    int x = minSteps(n-1);
    int y = INT_MAX, z = INT_MAX;
    if( n % 2 == 0){
        y = minSteps(n/2);
    }
    if( n % 3 == 0){
        z = minSteps(n/3);
    }
    return min(x, min(y,z)) + 1;
}

int minSteps_better(int n,int *ans){            // O(n)         Memoization, Top-down approch
    if(n == 1){
        ans[n] = 0;                             
        return 0;
    }

    if(ans[n-1] == -1){
        ans[n-1] = minSteps_better(n-1,ans); 
    }

    int y = INT_MAX, z = INT_MAX;
    if(n % 2 == 0){
        if(ans[n/2] == -1){
            ans[n/2] = minSteps_better(n/2,ans);
        }
        y = ans[n/2];
    }
    if(n % 3 == 0){
        if(ans[n/3] == -1){
            ans[n/3] = minSteps_better(n/3,ans);
        }
        y = ans[n/3];
    }
    ans[n] = min( ans[n-1], min(y,z)) + 1;
    return ans[n];
}

int minSteps_better(int n){
    int *ans = new int[n+1];
    for(int i=0; i<=n; i++){
        ans[i] = -1;
    }
    return minSteps_better(n,ans);
}

int main(){
    
    int n;
    cin>>n;
    cout<< minSteps_better(n)<<endl;
    cout<< minSteps(n)<<endl;
 
    return 0;
}