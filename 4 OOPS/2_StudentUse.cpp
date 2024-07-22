#include<iostream>
using namespace std;

#include "1_Class.cpp"             // Include student class 

int main(){
 
    students s1;                     // Creating objects statically
    students s2,s3,s4;

    s1.uid = 2303;
    s1.age = 21;
    s1.cgpa = 8;
    cout<< s1.uid <<endl;
    cout<< s1.age <<endl;
    cout<< s1.cgpa <<endl;

    s1.display();                  // Calling function


    students * s5 = new students;    // Creating objects dynamically

    (*s5).uid = 2316;
    (*s5).age = 20;
    (*s5).cgpa = 7;

    s5 -> uid = 2317;             //  (*s5). or s5 -> are same
    s5 -> age = 20;
    s5 -> cgpa = 7;

    cout<< (*s5).uid <<endl;
    cout<< (*s5).age <<endl;
    cout<< (*s5).cgpa <<endl;

    s5 ->display();
 
    return 0;
}