#include<iostream>
using namespace std;
#include "1_NodeClass.cpp"

void print(node *head){
    node *temp = head;

        while( temp != NULL){
            cout<< temp->data<<" ";
            temp=temp->next;
        }

    temp = head;
        while( temp != NULL){
            cout<< temp->data<<" ";
            temp=temp->next;
        }
}

int main(){
 
    node n1(10);            // Statically
    node *head = &n1;       // Storing add. of head node

    node n2(20);
    node n3(30);
    node n4(40);
    node n5(50);

    n1.next = &n2;          
    n2.next = &n3;          
    n3.next = &n4;          
    n4.next = &n5;

    print(head);          

 //   n1.next = &n2;          // Conneting two nodes

 //   cout<< n1.data <<" "<< n2.data<<endl;


    // node *n10 = new node(30);    // Dynamiclly 
    // node *head = n10;

    // node *n11 = new node(40);    // Conneting nodes(n4 becoz this alredy stores add. value)
    // n10 -> next = n11;        


    return 0;
}