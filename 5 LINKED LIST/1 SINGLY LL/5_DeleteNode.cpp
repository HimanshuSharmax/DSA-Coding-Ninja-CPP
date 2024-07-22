#include<iostream>
using namespace std;
#include "1_NodeClass.cpp"

node *deleteNode(node *head,int i){
    node *newNode;
    int count = 0;
    node *temp = head;

    if(i == 0){                                  // if we delete at 0th post.
        node *temp = head;
        head = head -> next;
        delete temp;
        return head;
    }

    while(temp != NULL && count < i -1){         // (temp != NULL) if we type great size w.r.t to LL
        temp = temp -> next;
        count++;
    }
    if(temp != NULL){
        node *a = temp ->next;
        temp ->next = a ->next;
        delete a;
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
 
    int i;
    cout<<"Enter the delete Node Postion : "<<endl;
    cin>>i;

    head = deleteNode(head,i);
    cout<<"The updated linked list are :"<<endl;
    print(head);
 
    return 0;
}