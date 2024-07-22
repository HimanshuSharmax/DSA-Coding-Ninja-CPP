#include<iostream>
#include<cstring>                     // For string file
using namespace std;

class student{
    char *name;
    int age;

    public :
    student(char *name,int age){
        this ->name = name;                // Shallow copy(copy 0th index add.)
        this -> age = age;       

        this -> name = new char[strlen(name) + 1];          // DEEP copy(copy whole array)
        strcpy(this->name, name);
    }
    void display(){
        cout<<"Name is : "<<name<<", "<<"Age is : "<<age<<endl;
    }
};

int main(){
 
    char name[]= "Himanshu S";
    student obj1(name,21);
    obj1.display();

    name[9]='V';
    student obj2(name,25);
    obj2.display();
 
    obj1.display();             // Shallow copy
    return 0;
}