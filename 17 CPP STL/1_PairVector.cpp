#include<bits/stdc++.h>             // import every C++ header file.
using namespace std;
int main(){
 
//PAIR

    pair <int,string> p;
   // p = make_pair(15,"abc");
    p = {45,"xyz"};
    cout<< p.first<<" "<<p.second<<endl;

    pair <int,string> &p1 = p;          // &p1 call by references(same value), not use & (copy the value)
    p1.first = 108;
    cout<< p.first<<" "<<p.second<<endl;

    int a[] = {1,2,3};
    int b[] = {11,22,33};
    pair<int,int> p_array[3];
    p_array[0] = {1,11};
    p_array[1] = {2,22};
    p_array[2] = {3,33};
    for(int i=0; i<3; i++){
        cout<< p_array[i].first<<" "<<p_array[i].second<<endl;
    }

    swap(p_array[0],p_array[2]);
    for(int i=0; i<3; i++){
        cout<< p_array[i].first<<" "<<p_array[i].second<<endl;
    }


// VECTOR

    vector<int> v;              // Dynamic in size initial with 0(continue memory allocate) 
    int n;
    cout<<"Enter value for vector array: "<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);     // Push the value in end of vector O(1)
    }

    cout<<"Size: "<<v.size()<<endl;     // For printing O(1)
    for(int i=0; i<v.size(); i++){
        cout<< v[i] <<" ";
    }
    cout<<endl;

    vector<int> v1(10,4);           // (size, pre fill)
    v1.push_back(77);
    for(int i=0; i<v1.size(); i++){
        cout<< v1[i] <<" ";
    }
    cout<<endl;
    
    vector<int> v2 = v1;        // Copy the vector O(n), if don't want copy then use &  
    v2.push_back(99);
    for(int i=0; i<v2.size(); i++){
        cout<< v2[i] <<" ";
    }  
    cout<<endl;


    return 0;
}