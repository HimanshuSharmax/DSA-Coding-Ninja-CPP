// Inplace Heat = doesn't required extra space,In given space algo  O(1)

#include<iostream>
using namespace std;

void inplaceHeatSort(int input[] , int n){
    // Build the heap in input array
    for(int i=1 ; i<n ; i++){

        int childIndex = i;                                 // CI - 1 / 2
        while(childIndex  > 0){
        int parentIndex = (childIndex - 1) / 2;

        if(input[childIndex] < input[parentIndex]){               // Up-Heapify
            int temp = input[childIndex];
            input[childIndex] = input[parentIndex];
            input[parentIndex] = temp;
        }else{
            break;
        }
        childIndex = parentIndex;
        } 
    }

    // Remove elements for sorting
    int size = n;

    while(size > 1){
        int temp = input[0];                    //Swap first and last but don't remove last
        input[0] = input[size-1];
        input[size-1] = temp;
        size--;

        int parentIndex = 0;                                // Down-heapify
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while( leftChildIndex < size ){
            int minIndex = parentIndex;
            if(input[minIndex] > input[leftChildIndex]){
                minIndex = leftChildIndex;
            }
            if( rightChildIndex < size && input[rightChildIndex] < input[minIndex]){
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex){
                break;
            }
            int temp = input[minIndex];
            input[minIndex] = input[parentIndex];
            input[parentIndex] = temp;
            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }

}

int main(){
    
    int input[] = {5,1,2,0,8};
    inplaceHeatSort(input,5);
    for(int i=0; i<5; i++){
        cout<< input[i] <<" ";
    }
    cout<<endl;
 
    return 0;
}