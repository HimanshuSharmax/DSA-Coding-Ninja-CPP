#include<iostream>
using namespace std;

inline int max(int a,int b){     // inline fun
    return (a>b) ? a : b;
}

int sum(int a[],int size, int startIndex=0){      // Here startIndex=0 is default arg
    int ans=0;
    for(int i=startIndex ; i<size; i++){
        ans=ans+a[i];
    }
    return ans;
}

int sum1(int num1,int num2,int num3=0,int num4=0){
    return num1+num2+num3+num4;
}

int main(){
    int p,q;
    cin>>p>>q;

    int c=(p>q) ? p :q;
    cout<<"Max Num for the fun is :"<<c<<endl;

    int x=12,y=45;
    int z = max(x,y);
    cout<<"Max num is : "<<z<<endl;

    int n, a[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<"Enter the num of starting Index for sum: "<<endl;
    cin>>n;
    cout<<"The sum is : " << sum(a,10,n) <<endl;

    int num1,num2,num3,num4;
    cout<<"Enter the num for sum(max 4 digit number): "<<endl;
    cin>>num1>>num2>>num3>>num4;
    cout<<"The sum is : "<<sum1(num1,num2,num3,num4)<<endl;

}