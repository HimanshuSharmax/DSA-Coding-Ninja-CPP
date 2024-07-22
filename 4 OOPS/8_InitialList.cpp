#include<iostream>
using namespace std;

class student{
    public:
    int age;
    const int uid;
    int &x;                  // age ref. var(inti. list)

    student(int r,int a) : uid(r), age(a), x(this->age){        // Initialization list

    }
};

int main(){
 
    student s1(2303,20);
    s1.age=21;           

    return 0;
}