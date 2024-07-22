#include<iostream>
using namespace std;
#include "1_NodeClass.cpp"

void insertAtHead(node* &head,int data){
    node *newNode = new node(data);

    if(head==NULL){
        newNode->next = newNode;
        head = newNode;
        return;
    }

    node*temp = head;
    while(temp->next != head){
        temp = temp->next; 
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtTail(node* &head,int data){

    if(head==NULL){
        insertAtHead(head,data);
        return;
    }

    node* newNode = new node(data);
    node*temp = head;

    while(temp->next != head){
        temp = temp->next; 
    }
    temp->next = newNode;
    newNode->next = head;
}

void display(node* head){
    node* temp = head;

    do{
        cout<< temp->data<<" ";
        temp=temp->next;
    } while(temp!=head);            // using do while becoz to print upto last elemenet
    cout<<endl;
}

int main(){
 
    node *head = NULL;
    insertAtTail(head,11);
    insertAtTail(head,22);
    insertAtTail(head,33);
    insertAtTail(head,44);
    display(head);

    insertAtHead(head,5);
    display(head);
 
    return 0;
}