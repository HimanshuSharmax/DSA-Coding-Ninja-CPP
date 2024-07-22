#include<iostream>
using namespace std;
int main(){
 
    string s = "Himanshu";
    cout<< s <<endl;

    string *sp = new string;              // creating string dynamically
    *sp = "abc";
    cout<< sp <<endl;
    cout<< *sp <<endl;

    string s1;
    cout<<"Enter string : "; 
    getline(cin,s1);                      // for removing sapce 
    cout<< s1 <<endl;

    s1 = "sharma";
    cout<< s1[0] <<endl;
    s1[0] = 'a';
    cout<< s1[0] <<endl;
 
    string s2 = s + s1;
    cout<< s2 <<endl;
    cout<< s2.size() <<endl;
    cout<< s2.substr(4) <<endl;
    cout<< s2.substr(4,5) <<endl;

    return 0;
}