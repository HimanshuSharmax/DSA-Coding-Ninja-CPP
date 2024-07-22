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
class Queue{
    Node<T> *head;
    Node<T> *tail;
    int size;

    public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void enqueue(T element){
        Node<T> *newNode = new Node<T>(element);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T dequeue(){
        if(isEmpty()){
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head -> next;
        delete temp;
        size --;
        return ans;
    }

    T front(){
        if(isEmpty()){
            return 0;
        }
        return head->data;
    }
};

int main(){
 
    Queue<int> obj1;
    obj1.enqueue(10);
    obj1.enqueue(20);
    obj1.enqueue(30);
    obj1.enqueue(40);
    obj1.enqueue(50);
    obj1.enqueue(60);

    cout<< obj1.front()<<endl;
    cout<< obj1.dequeue()<<endl;
    cout<< obj1.front()<<endl;
    cout<< obj1.dequeue()<<endl;
    cout<< obj1.getSize()<<endl;
    cout<< obj1.isEmpty()<<endl;
 
    return 0;
}