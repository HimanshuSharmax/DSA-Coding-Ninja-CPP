#include<iostream>
using namespace std;

void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int arr[],int si,int ei){

    int pivot = arr[ei];
    int i = si-1;

    for (int j=si;j<ei;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,ei);
    return i+1;
}

void quickSort(int arr[],int si,int ei){
    if(si<ei){
        int pi = partition(arr,si,ei);
        quickSort(arr,si,pi-1);
        quickSort(arr,pi+1,ei);
    }
}

int main(){
 
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<"Enter the no. of elements : "<<endl;
    int * arr = new int[n];     
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }

    // int arr[]={26,25,14,96,53};
    quickSort(arr,0,n-1);
    cout<<"The sorted array is : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
 
return 0;
}   