#include<iostream>
using namespace std;
#include "1_NodeClass.cpp"

node *takeInput(){                              // Time Complexity O(n^2)
    int data;
    cout<<"Enter Number (For exist -1): "<<endl;
    cin>>data;
    node *head = NULL;
    while(data != -1){
        node *newNode = new node(data);         // dynamic
            if(head == NULL){
                head = newNode;                 // assign add. of newNode in head
            }
            else{
                node *temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                    temp->next = newNode;
            }
        cin>>data;
    }
    return head;
}

node *takeInput_Better(){                       // Time Complexity O(n)
    int data;
    cout<<"Enter Number (For exist -1): "<<endl;
    cin>>data;
    node *head = NULL;
    node *tail = NULL;
    while(data != -1){
        node *newNode = new node(data);         
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{        
                   tail->next = newNode;
                   tail = newNode;
                }          
        cin>>data;
    }
    return head;
}

void print(node *head){
        while( head != NULL){
            cout<< head->data<<" ";
            head=head->next;
        }
}

int main(){
 
    node*head =takeInput_Better();
    cout<<"The linked list are :"<<endl;
    print(head);
 
    return 0;
}