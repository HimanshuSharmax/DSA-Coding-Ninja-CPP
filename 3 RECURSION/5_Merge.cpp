#include<iostream>
using namespace std;

void merge(int arr[],int si,int mid,int ei){

    int a1=mid-si+1;                 // for array size
    int a2=ei-mid;

    int a[a1],b[a2];                 //  Temp array

    for(int i=0 ; i<a1 ;i++ ){
        a[i]=arr[si+i];
    }
    for(int i=0 ; i<a2 ;i++ ){
        b[i]=arr[mid+1+i];
    } 

    int i=0,j=0,k=si;
    while(i<a1 && j<a2){            // Both true
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++; i++;
        }
        else{
            arr[k]=b[j];
            k++; j++;   
        }
    }

    while(i<a1){
        arr[k]=a[i];
        k++; i++;
    }
    while(i<a2){
        arr[k]=b[j];
        k++; j++;
    }
}

void mergeSort(int arr[],int si,int ei){
    if(si<ei){
        int mid = (si+ei)/2;
        mergeSort(arr,si,mid);
        mergeSort(arr,mid+1,ei);

        merge(arr,si,mid,ei);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<"Enter the no. of elements : "<<endl;
    int * arr = new int[n];     
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }

    // int arr[]={26,25,14,96,53};
    mergeSort(arr,0,n-1);
    cout<<"The sorted array is : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
   
    return 0;
}   