#include<bits/stdc++.h>
using namespace std;

void print(map<int,string> &m){
    cout<< m.size() <<endl;
    for(auto &pr : m){                 // PRINT =  O(log(n))
        cout<< pr.first<<" "<<pr.second<<endl;
    }
}

void print(unordered_map<int,string> &m){
    cout<< m.size() <<endl;
    for(auto &pr : m){                 // PRINT =  O(log(n))
        cout<< pr.first<<" "<<pr.second<<endl;
    }
}

int main(){
 
// ORDERED MAP

    map<int,string> m;           // Implementation by tree 
    m[1] = "abc";                // INSERT = O(log(n)), Depend on key if it is string then- {string.size() * logn}
    m[5] = "cdc";
    m[3] = "acd";
    m.insert({4,"afg"}); 

    // map<int,string> :: iterator it;
    // for(it = m.begin(); it != m.end(); ++it){
    //     cout<< it->first <<" "<< it->second<<endl;
    // }

    print(m);

    auto it = m.find(5);                // FIND = O(log(n))
    if(it == m.end()){
        cout<<"Not found"<<endl;
    }else{
        cout<< (*it).first <<" "<< it->second <<endl;
    }

    m.erase(it);
    print(m);
    
    
/* Given N string, print unique strings in lexiographical(increaing) order with their frequency 
    N <= 10^5
   |S| <=100 */

   map<string,int> m1;
   int n;
   cout<<"Enter size of string: "<<endl;
   cin>>n;
   for(int i=0; i<=n; ++i){
       string s;
        cin>> s;
       // m1[s] = m1[s] + 1;
        m1[s] ++;
   }
   cout<<"The string & there frequency are:"<<endl;
    for(auto pr : m1){
        cout<< pr.first<<" "<<pr.second<<endl;  
    }



// UNORDERED MAP

    unordered_map<int,string> m2;    // Implementation by hashmap
    m2[1] = "abc";                // INSERT = O(1), Depend on key if it is string then- {string.size() * logn}
    m2[5] = "cdc";
    m2[3] = "acd";
    m2.insert({4,"afg"}); 
    cout<<"UnOrdered Map-"<<endl;
    print(m2);


/* Given N string and Q queries.In each query you are given a string print freq of that string 
    N <= 10^6
   |S| <=100 
   Q <= 10^6 */

    unordered_map<string,int> m3;
   int num;
   cout<<"Enter size of string: "<<endl;
   cin>>num;
   for(int i=0; i<=num; ++i){
       string s;
        cin>> s;
       // m1[s] = m1[s] + 1;
        m3[s] ++;
   }
   cout<<"Enter The query of string:"<<endl;

    int q;
    cin>>q;
    while (q--){
        string s;
        cin>>s;
        cout<< m3[s] <<endl;
    }


    return 0;
}


