#include<iostream>
using namespace std;
// #include "1_Class.cpp"
#include "3_ModifiedClass.cpp"

int main(){
    StackUsingArray obj;          // creating obj
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);
    obj.push(50);

    cout<<obj.top()<<endl;

    cout<<obj.pop()<<endl;
    cout<<obj.pop()<<endl;
    cout<<obj.pop()<<endl;

    cout<<obj.size()<<endl;
    cout<<obj.isEmpty()<<endl;

 
    return 0;
}
