#include<bits/stdc++.h>
using namespace std;

// void printVector(vector<pair<int,int>> &v){
//     cout<<"Size: "<<v.size()<<endl;   
//     for(int i=0; i<v.size(); i++){
//         cout<< v[i].first <<" "<<v[i].second<<endl;
//     } 
//     cout<<endl;
// }

void printVector(vector<int> &v){
    cout<<"Size: "<<v.size()<<endl;   
    for(int i=0; i<v.size(); i++){
        cout<< v[i]<<" ";
    } 
    cout<<endl;
}

int main(){
 
    // vector<pair<int,int>> v = {{1,1},{2,2}};
    // printVector(v);

    // vector<pair<int,int>> v1;

    // int n;
    // cout<<"Enter size of vector:"<<endl;
    // cin>>n;
    // for(int i=0; i<n; i++){
    //     int x,y;
    //     cin>>x>>y;
    //     v1.push_back({x,y});    
    // }
    // printVector(v1);


// Array of vectors

    int numOfvertor;
    cout<<"Enter size of Arrays of vector:"<<endl;
    cin>>numOfvertor;
    vector<int> v5[numOfvertor]; 
    for(int i=0; i<numOfvertor; i++){
        int sizeOfVector;
        cin>>sizeOfVector;
        for(int j=0; j<sizeOfVector; j++){
            int x;
            cin>>x;
            v5[i].push_back(x);
        }
        for(int i=0; i<numOfvertor; i++){
            printVector(v5[i]);
        }    
    }
 
    return 0;
}