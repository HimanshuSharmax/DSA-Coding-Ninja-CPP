#include<iostream>
#include<climits>   
using namespace std;
template <typename Template>

class StackUsingArray{
    Template *data;
    int nextIndex;
    int capacity;

    public:

    StackUsingArray(){
        data = new Template[4];
        nextIndex = 0;
        capacity = 4;
    }
    
    int size(){                                      // return the number of elements
        return nextIndex;
    }

    bool isEmpty(){
        return nextIndex == 0;
    }

    void push(Template element){                          // insert element
        if (nextIndex == capacity){
            Template *newData = new Template[2*capacity];
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

    Template pop(){                                        // delete element
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    Template top(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};

int main(){
 
    StackUsingArray<char> obj;          
    obj.push(95);
    obj.push(96);
    obj.push(97);
    obj.push(98);
    obj.push(99);

    cout<<obj.top()<<endl;

    cout<<obj.pop()<<endl;
    cout<<obj.pop()<<endl;
    cout<<obj.pop()<<endl;

    cout<<obj.size()<<endl;
    cout<<obj.isEmpty()<<endl;
 
    return 0;
}