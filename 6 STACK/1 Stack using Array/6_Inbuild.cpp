#include<iostream>
#include<stack>                 // Made with Template 
using namespace std;
int main(){

    stack<int> obj1;
    obj1.push(10);
    obj1.push(20);
    obj1.push(30);
    obj1.push(40);
    obj1.push(50);

    cout<< obj1.top() <<endl;
    obj1.pop();
    cout<< obj1.top() <<endl;
    cout<< obj1.size() <<endl;
    cout<< obj1.empty() <<endl;

    return 0;
}