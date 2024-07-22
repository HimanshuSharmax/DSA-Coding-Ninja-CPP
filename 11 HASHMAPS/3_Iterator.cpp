#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

int main(){
 
    // For unordered Map
    unordered_map<string, int> ourMap;
    ourMap["abc1"] = 1;
    ourMap["abc2"] = 2;
    ourMap["abc3"] = 3;
    ourMap["abc4"] = 4;
    ourMap["abc5"] = 5;
    ourMap["abc6"] = 6;

    unordered_map<string,int> :: iterator it = ourMap.begin();
    while(it != ourMap.end()){
        cout<<"Key: "<< it->first <<", Value: "<<it->second<<endl;      // it->first(pair->first)
        it++;
    }

        // find
    unordered_map<string,int> :: iterator it2 = ourMap.find("abc2");
  //  ourMap.erase(it2, it2 + 3);      //(begin,end) , it2...it+2
    

    // For vector
    vector<int> v;
    v.push_back(11);
    v.push_back(22);
    v.push_back(33);
    v.push_back(44);
    v.push_back(44);

    vector<int> :: iterator it1 = v.begin();
    while(it1 != v.end()){
        cout<< *it1 <<endl;
        it1++;
    }
    
    return 0;
}