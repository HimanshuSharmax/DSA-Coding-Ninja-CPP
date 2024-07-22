#include<iostream>
using namespace std;
int main(){
    int *p = new int;             // Dynamic allo store in HEAP
    *p=10;
    cout<<*p<<endl;
    
    delete p;                    // if not required then delete

    double *pd= new double;
    char* c=new char;

    int* arr1 = new int[50];     // Declare array   (200bytes on Heap and 8 bytes on stack)
    delete [] arr1;              // In case array


    int n;
    cout<<"Enter the no. of elements"<<endl;
    cin>>n;
    int* arr2 = new int[n];      // For user input
    for (int i=0;i<n;i++){
        cin>>arr2[i];
    }
    int max=-1;
    for (int i=0;i<n;i++){
        if(max < n[i]){
            max = n[i];
        }
    }
    cout<< max <<endl;
    return 0;
}