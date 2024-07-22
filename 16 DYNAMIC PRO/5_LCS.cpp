#include<iostream>
using namespace std;

int LCS(string s, string t){                    // O(3^n),  Brute-force 
    // base case
    if(s.size() == 0 || t.size() == 0){
        return 0;
    }

    // recursive cal{l
    if(s[0] == t[0]){
        return 1 + LCS(s.substr(1), t.substr(1));
    }else{
        int a = LCS(s.substr(1), t);
        int b = LCS(s, t.substr(1));
        int c = LCS(s.substr(1), t.substr(1));
        return max(a, max(b,c));
    }
}


int LCS_better(string s, string t, int ** ans){         //  Time = O(m*n), Space = O(m*n),  Memoization
    // base case
    if(s.size() == 0 || t.size() == 0){
        return 0;
    }

    int m = s.size();
    int n = t.size();
    
    if(ans[m][n] != -1){
        return ans[m][n];
    }

    if(s[0] == t[0]){
        ans[m-1][n-1] = LCS_better(s.substr(1), t.substr(1), ans);
        ans[m][n] = 1 + ans[m-1][n-1];
    }else{
        ans[m][n-1] = LCS_better(s, t.substr(1),ans);
        ans[m-1][n] = LCS_better(s.substr(1), t,ans);
        ans[m][n] = max( ans[m][n-1], ans[m-1][n] );
    }
    return ans[m][n];
}

int LCS_better(string s, string t){
    int m = s.size();
    int n = t.size();
    int **ans = new int*[m+1];
    for(int i=0; i<=m; i++){
        ans[i] = new int[n+1];
        for(int j=0; j<=n; j++){
        ans[i][j] = -1;
        }
    }
    return LCS_better(s,t,ans);
}


int LCS_dp(string s,string t){        //  Time = O(m*n), Space = O(m*n),  DP
    int m = s.size();
    int n = t.size();
    int **ans = new int*[m+1];
    for(int i=0; i<=m; i++){
        ans[i] = new int[n+1];
    }

    for(int j=0; j<=n; j++){        // First row Filling 0
        ans[0][j] = 0;
    }
    for(int i=0; i<=m; i++){        // First col Filling 0
        ans[i][0] = 0;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[m-i] == t[n-j] ){
            ans[i][j] = 1 + ans[i-1][j-1];
        }else{
            ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
        }
        } 
    }
    return ans[m][n];
}

int main(){
 
    string s,t;
    cout<<"Enter string:"<<endl;
    cin>>s>>t;

  // string s= "abceg";
  // string t= "cdg";

    cout<< LCS_dp(s,t)<<endl;
    cout<< LCS_better(s,t)<<endl;
    cout<< LCS(s,t)<<endl;
 
    return 0;
}