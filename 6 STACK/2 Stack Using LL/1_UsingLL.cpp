#include<iostream>
using namespace std;
template <typename T>

class Node{
    public:
    T data;
    Node<T> *next;

    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack{
    Node<T> *head;
    int size;              // Num of elements present in stack

    public:

    Stack(){
        head = NULL;
        size = 0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void push(T element){
        Node<T> *newNode = new Node<T>(element);
        newNode -> next = head;
        head = newNode;     
        size++;
    }

    T pop(){
        if(isEmpty()){
            cout<<"Stack is empty";
            return 0;
        }
        T ans = head -> data;
        Node<T> *temp = head;
        head = head -> next;
        delete temp;
        size --;
        return ans; 
    }

    T top(){
        if(isEmpty()){
            cout<<"Stack is empty";
            return 0;
        }
        return head->data;
    } 
};

int main(){
 
    Stack<int> obj;          // creating obj
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);
    obj.push(50);

    cout<<obj.top()<<endl;

    cout<<obj.pop()<<endl;
    cout<<obj.pop()<<endl;
    cout<<obj.pop()<<endl;

    cout<<obj.getSize()<<endl;
    cout<<obj.isEmpty()<<endl;
 
    return 0;
}