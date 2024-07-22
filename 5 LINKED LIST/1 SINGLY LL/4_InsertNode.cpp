#include<iostream>
using namespace std;
#include "1_NodeClass.cpp"

node *insertNode(node *head,int position,int data){
    node *newNode = new node(data);
    int count = 0;
    node *temp = head;

    if(position == 0){                                  // if we insert at 0th post.
        newNode -> next = head;
        head = newNode;
        return head;
    }

    while(temp != NULL && count < position -1){         // (temp != NULL) if we type great size w.r.t to LL
        temp = temp -> next;
        count++;
    }
    if(temp != NULL){
        // node *a = temp -> next;
        // temp -> next = newNode;
        // newNode -> next = a; 
        
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
    return head;
}

node *takeInput_Better(){                      
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
        while(head != NULL){
            cout<<head->data<<endl;
            head=head->next;
        } 
}

int main(){
 
    node*head =takeInput_Better();
 
    int position,data;
    cout<<"Enter the New Node Postion and Data: "<<endl;
    cin>>position>>data;

    head = insertNode(head,position,data);
    cout<<"The updated linked list are :"<<endl;
    print(head);

 
    return 0;
}