#include<iostream>
using namespace std;

int editDistsnce(string s, string t){               // O(3^n),  Brute-force 
    // Base case
    if(s.size() == 0 || t.size() == 0){
        return max(s.size(), t.size());
    }

    if(s[0] == t[0]){
        return editDistsnce(s.substr(1),t.substr(1));
    }else{
        // Insert
        int x = editDistsnce(s.substr(1), t) + 1;
        // Delete
        int y = editDistsnce(s, t.substr(1)) + 1;
        // Replace
        int z = editDistsnce(s.substr(1), t.substr(1)) + 1;
 
        return min(x, min(y,z));
    }

}


int editDistance_better(string s, string t, int ** ans){       //  Time = O(m*n), Space = O(m*n),  Memoization
   if(s.size() == 0 || t.size() == 0){
        return max(s.size(), t.size());
    }

    int m = s.size();
    int n = t.size();
    
    if(ans[m][n] != -1){
        return ans[m][n];
    }

    if(s[0] == t[0]){
        ans[m][n] = editDistance_better(s.substr(1), t.substr(1), ans);

    }else{
        ans[m-1][n] = editDistance_better(s.substr(1), t,ans);
        ans[m][n-1] = editDistance_better(s, t.substr(1),ans);
        ans[m-1][n-1] = editDistance_better( s.substr(1), t.substr(1),ans );

        ans[m][n] = 1 + min(ans[m-1][n], min( ans[m][n-1],ans[m-1][n] ));
    }
    return ans[m][n];     
}

int editDistance_better(string s, string t){
    int m = s.size();
    int n = t.size();
    int **ans = new int*[m+1];
    for(int i=0; i<=m; i++){
        ans[i] = new int[n+1];
        for(int j=0; j<=n; j++){
        ans[i][j] = -1;
        }
    }
    return editDistance_better(s,t,ans);
}


int editDistance_dp(string s,string t){        //  Time = O(m*n), Space = O(m*n),  DP
    int m = s.size();
    int n = t.size();
    int **ans = new int*[m+1];
    for(int i=0; i<=m; i++){
        ans[i] = new int[n+1];
    }

    for(int j=0; j<=n; j++){        // First row Filling
        ans[0][j] = j;
    }
    for(int i=0; i<=m; i++){        // First col Filling 
        ans[i][0] = i;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[m-i] == t[n-j] ){
            ans[i][j] =  ans[i-1][j-1];
        }else{
            ans[i][j] = min(ans[i-1][j], min(ans[i][j-1], ans[i-1][j-1] )) + 1;
        }
        } 
    }
    return ans[m][n];
}

int main(){
 
    string s,t;
    cout<<"Enter string:"<<endl;
    cin>>s>>t;

    cout<< editDistance_dp(s,t)<<endl;
    cout<< editDistance_better(s,t)<<endl;
    cout<< editDistsnce(s,t)<<endl;
 
    return 0;
}