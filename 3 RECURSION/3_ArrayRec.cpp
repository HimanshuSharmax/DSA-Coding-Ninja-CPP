#include<iostream>
using namespace std;

bool sorted(int arr[],int size){
    if(size==1){
        return 1;
    }
    bool restArr = sorted(arr+1,size-1);
    return (arr[0] < arr[1]  && restArr);             // Both true then true
}

int main(){  
    // int arr[]={1,2,3,4,5};

    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    cout<<"Enter the no. of elements : "<<endl;
    int * array = new int[size];     
    for (int i=0;i<size;i++){
        cin>>array[i];
    }
    cout<<sorted(array,size);   
    return 0;
}