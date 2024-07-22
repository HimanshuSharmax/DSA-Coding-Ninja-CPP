#include<iostream>
using namespace std;

class student{
    public :
    int uid;
    int age;

    static int totalStudents;

    student(){
        totalStudents++;
    }
};

int student :: totalStudents = 0;          // initialze static data members 

int main(){
 
    student s1,s2,s3,s4;
    
    cout<< s1.uid <<endl;
    cout<< student :: totalStudents <<endl;
 
    return 0;
}