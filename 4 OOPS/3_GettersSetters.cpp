#include<iostream>
using namespace std;
#include "1_Class.cpp"
int main(){

    students s1;
    students *s2 = new students;

    cout<<s1.getPhn()<<endl;

    s1.setPhn(98745);
    s2 -> setPhn(75465);

    s1.displayPhn();
    s2->displayPhn();
    return 0;
}