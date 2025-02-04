#include<iostream>
#include<queue>
using namespace std;

int main(){
 
  //  priority_queue<int> pq;                                  // by default it is max pq (parent>child)
    priority_queue<int, vector<int>, greater<int> > pq;        // for min Use greater by default (parent<child)
    pq.push(16);
    pq.push(1);
    pq.push(167);
    pq.push(7);
    pq.push(45);
    pq.push(32);

    cout<<"Size: "<<pq.size()<<endl;
    cout<<"Top: "<<pq.top()<<endl;          // Get max

    while(!pq.empty()){
        cout<< pq.top() <<endl;
        pq.pop();
    }
 
    return 0;
}