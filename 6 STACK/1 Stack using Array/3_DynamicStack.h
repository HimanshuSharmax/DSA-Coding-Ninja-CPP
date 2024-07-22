// Header file don't contain Main

#include<iostream>
#include<climits>                     // for using INT_MIN
using namespace std;

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;

    public:

    StackUsingArray(){
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
    }
    
    int size(){                      // return the number of elements present in stack
        return nextIndex;
    }

    bool isEmpty(){
        return nextIndex == 0;
    }

    void push(int element){                             // insert element
        if (nextIndex == capacity){
            int *newData = new int[2*capacity];
            for(int i=0 ; i<capacity; i++){
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
        } 
        data[nextIndex] = element;
        nextIndex++;
    }

    int pop(){                                         // delete element
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }

};
