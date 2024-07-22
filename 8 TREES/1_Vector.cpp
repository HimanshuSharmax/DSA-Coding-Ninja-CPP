#include<iostream>
#include<vector>
using namespace std;
int main(){
 
    vector<int> *v1 = new vector<int>();         // Dynamically
    vector<int> v;                               // Statically

    for(int i = 0; i<66;i++){
        cout<<"Capacity: "<< v.capacity()<<endl;
        cout<<"Size: "<< v.size()<<endl;
        v.push_back(i+1);
    }

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[3] = 1001;
    v[4] = 1001;

    v.push_back(40);
    v.push_back(50);


    /*    cout<< v[0] <<endl;
    cout<< v[1] <<endl;
    v[1] = 25;
    cout<< v[1] <<endl;
    cout<< v[2] <<endl;
    cout<< v[3] <<endl;
    cout<< v[4] <<endl;
    cout<< v[5] <<endl;
    cout<< v[6] <<endl;

    cout<< v.at(3) <<endl;
    cout<< v.at(6) <<endl;
    */


    for(int i = 0; i<v.size(); i++){
        cout<< v[i] <<endl;
    }
    cout<<"Size : "<<v.size()<<endl;
    v.pop_back();
    cout<<"Size after pop_back  : "<<v.size()<<endl;

    return 0;
}