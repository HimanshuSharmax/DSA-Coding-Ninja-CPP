#include<iostream>
using namespace std;
// #include "1_QueueUsingArray.h"
#include "3_DynamicQueue.h"
int main(){
 
    QueueUsingArray<int> obj1(5);
    obj1.enqueue(10);
    obj1.enqueue(20);
    obj1.enqueue(30);
    obj1.enqueue(40);
    obj1.enqueue(50);
    obj1.enqueue(60);

    cout<< obj1.front()<<endl;
    cout<< obj1.dequeue()<<endl;
    cout<< obj1.front()<<endl;
    cout<< obj1.dequeue()<<endl;
    cout<< obj1.getSize()<<endl;
    cout<< obj1.isEmpty()<<endl;
 
    return 0;
}