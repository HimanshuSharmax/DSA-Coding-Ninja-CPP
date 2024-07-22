#include<iostream>
using namespace std;
#include "1_NodeClass.cpp"

void deleteAtHead(node * &head){
    node *toDelete = head;
    head = head->next;
    head->prev = NULL;
    delete toDelete;
}

void deletion(node * &head, int position){

    if(position==1){                      // For delete first node
        deleteAtHead(head);
        return;
    }
    node * temp = head;
    int count = 1;
    while(temp != NULL && count!=position){
        temp = temp->next;
        count ++;
    }
    temp->prev->next = temp->next;

    if(temp->next !=NULL){                  // FOR delete last node
        temp->next->prev = temp->prev;  
    }

    delete temp;
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

    deletion(head,3);
    display(head);
 
    return 0;
}