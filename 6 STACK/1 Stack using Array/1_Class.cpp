#include<iostream>
#include<climits>                     // for using INT_MIN
using namespace std;

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;

    public:

    StackUsingArray(int totalSize){
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }
    
    int size(){                      // return the number of elements present in stack
        return nextIndex;
    }

    bool isEmpty(){
        /*
        if(nextIndex == 0){
            return true;
        }else{
            return false;
        } */
        return nextIndex == 0;
    }

    void push(int element){                             // insert element
        if (nextIndex == capacity){
            cout <<"Stack is full"<< endl;
            return;
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
