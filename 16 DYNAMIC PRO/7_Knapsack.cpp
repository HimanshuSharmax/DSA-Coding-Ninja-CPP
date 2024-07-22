#include<iostream>
using namespace std;

int Knapsack(int *weight,int* value, int n, int maxWeight){             
    // base case
    if( n == 0 || maxWeight == 0){
        return 0;
    }

    if(weight[0] > maxWeight){
        return Knapsack(weight + 1,value + 1,n-1,maxWeight);
    }

    // Recursive call
    int x = Knapsack(weight + 1,value + 1,n - 1,maxWeight - weight[0]) + value[0];
    int y = Knapsack(weight + 1,value + 1,n - 1,maxWeight);

    return max(x,y);
}

int main(){
 
    int n;
    int weights[] = {5,1,8,9,2};
    int values[] = {4,10,2,3,1};
    int w = 15;
    cout<<Knapsack(weights,values,5,w)<<endl; 
    
    return 0; 
}