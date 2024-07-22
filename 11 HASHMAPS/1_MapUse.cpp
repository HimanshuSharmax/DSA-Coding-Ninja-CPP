#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
 
    unordered_map<string, int> ourMap;

    // Insert
    pair<string,int> p("abc", 1);
    ourMap.insert(p);
    ourMap["def"] = 2;

    // Find or access
    cout<< ourMap["abc"] <<endl;
    cout<< ourMap.at("abc") <<endl;
    cout<< ourMap.at("def") <<endl;

    cout<<"Size: "<<ourMap.size()<<endl;

 //   cout<< ourMap.at("ghi") <<endl;
    cout<< ourMap["ghi"] <<endl;        // [] insert and default val 0
    cout<<"Size: "<<ourMap.size()<<endl;

    // Check presence
    if(ourMap.count("ghi") > 0){
        cout<<"ghi is present "<<endl;
    }

    // erase
    ourMap.erase("ghi");
    cout<<"Size: "<<ourMap.size()<<endl;
 
    return 0;
}