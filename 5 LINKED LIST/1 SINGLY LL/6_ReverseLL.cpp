#include<iostream>
using namespace std;
#include "1_NodeClass.cpp"

node *reverse(node *head){                      // Time Complexity O(n^2)
    if(head == NULL || head->next == NULL){             // Base case
        return head;
    }
    node *SmallAnsHead = reverse(head->next);   

    node *temp = SmallAnsHead;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;

    return SmallAnsHead;
}

/*
class Pair{
    public:
    node *head;
    node *tail;
};

Pair reverse_better(node *head){                // Time Complexity O(n)
    if(head == NULL || head->next == NULL){             
        Pair ans;                                 // creating object of class
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair SmallAnsHead = reverse_better(head->next);   
    SmallAnsHead.tail -> next = head;
    head -> next = NULL;
    
    Pair ans;
    ans.head = SmallAnsHead.head;
    ans.tail = head;
    return ans;
}

node *reversell_better(node *head){
    return reverse_better(head).head;
}
*/

node *reverse_better(node * head){              // Time Complexity O(n)
    if(head == NULL || head->next == NULL){             
        return head;
    }
    node *SmallAnsHead = reverse_better(head->next);   

    node *tail = head -> next;
    tail->next = head;
    head->next = NULL;

    return SmallAnsHead;
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

    head = reverse_better(head);
    cout<<"The Reversed linked list are :"<<endl;
    print(head);
 
    return 0;
}