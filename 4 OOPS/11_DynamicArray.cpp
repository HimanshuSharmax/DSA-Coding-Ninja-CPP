#include<iostream>
using namespace std;

class DynamicArray{
    int *array;
    int nextIndex,size;

    public:
    DynamicArray(){
        array = new int[5];
        nextIndex = 0;
        size = 5;
    }

    DynamicArray(DynamicArray const &d){
       // this -> array = d.array;          Shallow Copy

       this -> array = new int[d.size];         // Deep copy
       for(int i=0;i<d.nextIndex;i++){
           this -> array[i] = d.array[i];
       }
       this -> nextIndex = d.nextIndex;
       this -> size = d.size;
    }

    void insertNew(int element){
        if(nextIndex==size){
            int *newArray = new int[2*size];
            for(int i=0;i<size;i++){
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
            size *= 2;
        }
        array[nextIndex] = element;
        nextIndex++;
    }

    int get(int i){
        if(i < nextIndex){
            return array[i];
        }else{
            return -1;
        }
    }

    void add(int i,int element){
        if(i < nextIndex){
            array[i] = element;
        }else if(i == element){
            insertNew(element);
        }else{
            return;
        }
    }

    void print(){
        for(int i=0;i<nextIndex;i++){
            cout<< array[i] <<" ";
        }
        cout<<endl;
    }
};

int main(){
 
    DynamicArray d1;
    d1.insertNew(10);
    d1.insertNew(20);
    d1.insertNew(30);
    d1.insertNew(40);
    d1.insertNew(50);
    d1.insertNew(60);

    d1.print();

    DynamicArray d2(d1);                // Copy Constructor(Shallow copy)

    d1.add(0,100);
    d2.print();

    return 0;
}