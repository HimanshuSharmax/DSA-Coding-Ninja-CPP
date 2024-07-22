#include<string>
#include<iostream>
using namespace std;

class teacher{
    public:
    string name;
    string age;

    void print(){
        cout<<"Teacher"<<endl;
    }
};

class student{
    public:
    string name;

    void print(){
        cout<<"Student"<<endl;
    }
};

class TA : public teacher, public student{
    public:
 //   string name;

    void print(){
        cout<<"TA"<<endl;
    }
};

int main(){

    TA a;

    a.teacher :: print();
    a.student :: print();

    a.print();

    a.student :: name = "Himanshu";
}