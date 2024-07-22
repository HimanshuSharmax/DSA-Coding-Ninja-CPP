#include<iostream>
#include<climits>
using namespace std;

int minCostPath(int **input,int m, int n,int i,int j){         //  O(3^n), Brute-force
    // Base case
    if(i == m-1 && j == n-1){
        return input[i][j];
    }
    if(i >= m || j >= n){
        return INT_MAX;
    }

    // Recursive calls
    int x =minCostPath(input,m,n, i, j+1);      // [0][1]
    int y =minCostPath(input,m,n, i+1, j+1);    // [1][1]
    int z =minCostPath(input,m,n, i+1, j);      // [1][0]

    // Small cal   
    int ans = min(x, min(y,z)) + input[i][j];
    return ans;
}

int minCostPath(int **input,int m, int n){
    return minCostPath(input, m, n, 0, 0);
}


int minCostPath_better(int **input,int m, int n,int i,int j,int **ans){       //  Time = O(m*n), Space = O(m*n),  Memoization
    // Base case
    if(i == m-1 && j == n-1){
        return input[i][j];
    }
    if(i >= m || j >= n){
        return INT_MAX;
    }

    // Recursive calls
    if(ans[i][j] != -1){
        return ans[i][j];
    }
    int x =minCostPath_better(input,m,n, i+1, j,ans);      // [1][0]
    if( x < INT_MAX){
        ans[i+1][j] = x;
    }
    int y =minCostPath_better(input,m,n, i+1, j+1,ans);    // [1][1]
    if( y < INT_MAX){
        ans[i+1][j+1] = y;
    }
    int z =minCostPath_better(input,m,n, i, j+1,ans);      // [0][1]
    if( z < INT_MAX){
        ans[i][j+1] = z;
    }

    ans[i][j] = min(x, min(y,z)) + input[i][j];
    return ans[i][j];
}

int minCostPath_better(int **input,int m, int n){
    int **ans = new int*[m];
    for(int i=0; i<m; i++){
        ans[i] = new int[n];
        for(int j=0; j<n; j++){
        ans[i][j] = -1;
        }
    }
    return minCostPath_better(input, m, n, 0, 0,ans);
}


int minCostPath_DP(int **input, int m,int n){             //  Time = O(m*n), Space = O(m*n),  DP
    int **ans = new int*[m];
    for(int i=0; i<m; i++){
        ans[i] = new int[n];
    }
    
    ans[m-1][n-1] = input[m-1][n-1];                        // fill last shell first
    
    for(int i=n-2; i>=0; i--){
        ans[m-1][i] = input[m-1][i] + ans[m-1][i+1];        // Last row
    }

    for(int j=m-2; j>=0; j--){
        ans[j][n-1] = input[j][n-1] + ans[j+1][n-1];        // Last col
    }

    for(int i=m-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            ans[i][j] = input[i][j] + min(ans[i][j+1], min(ans[i+1][j+1], ans[i+1][j] ));
        }
    }
    return ans[0][0];
    
}

int main(){
 
    int m,n;
    cout<<"Enter NumOf M & N matrix:"<<endl;
    cin>>m>>n;

    int **input = new int*[m];
    cout<<"Enter M*N matrix:"<<endl;
    for(int i=0; i<m; i++){
        input[i] = new int[n];
        for(int j=0; j<n; j++){
        cin>>input[i][j];
        }
    }
    
    cout<< minCostPath_DP(input,m,n)<<endl;
    cout<< minCostPath_better(input,m,n)<<endl;
    cout<< minCostPath(input,m,n)<<endl;

    return 0;
}