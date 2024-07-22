#include<iostream>
using namespace std;
#include "1_NodeClass.cpp"

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

void insertAtHead(node * &head,int data){
    node *newNode = new node(data);
    newNode->next = head;

    if(head !=NULL){
       head->prev = newNode;
    }
    head = newNode;
}

void insertAtTail(node * &head,int data){

    if(head==NULL){
        insertAtHead(head,data);
        return;
    }

    node *newNode = new node(data);
    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next; 
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void display(node *head){
    node * temp = head;
    while (temp !=NULL){
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
 
    node * head = NULL;
    insertAtTail(head,10);
    insertAtTail(head,20);
    insertAtTail(head,30);
    insertAtTail(head,40);
    display(head);
    insertAtHead(head,5);
    display(head);
 
    return 0;
}