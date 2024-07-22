#include<bits/stdc++.h>
using namespace std;
int main(){
 
    vector<int> v ={1,2,3,4,5,6};
    for(int i=0; i<v.size(); i++){
        cout<< v[i]<<" ";
    } 
    cout<<endl;

//    vector<int> :: iterator it = v.begin();         // end()-> next of last , This line we use auto in loop
//    cout<<(*it)<<endl;
//    cout<<(*(it+3))<<endl;

    for(auto it=v.begin(); it!=v.end(); ++it){
        cout<< (*it)<<endl;
    }

    for(int &value : v){             //  Range based loops
        cout<< value<<" ";
    }cout<<endl;

    vector<pair<int,string>> vp = {{2303,"Himanshu"},{2316,"abc"}};
    for(auto &value : vp){             //  Range based loops
        cout<< value.first<<" "<<value.second<<endl;;
    }

    auto a = 2.2;           // Dynamically ditermine the datatype
    cout<< a <<endl;
 
    return 0;
}