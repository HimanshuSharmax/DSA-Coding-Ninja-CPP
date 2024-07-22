#include<bits/stdc++.h>
using namespace std;

void print(set<string> &s){
    for(string val : s){
        cout<< val << endl;
    }
    // for(auto it=s.begin(); it!=s.end(); ++it){
    //     cout<< (*it) << endl;
    // }
}
void print(unordered_set<string> &s){
    for(string val : s){
        cout<< val << endl;
    }
}
void print(multiset<string> &s){
    for(string val : s){
        cout<< val << endl;
    }
}

int main(){
 
// ORDERED SET

    set<string> s;
    s.insert("babc");       // O(logn)
    s.insert("abcd");
 
    auto it = s.find("abcd");    // Iterator
    if(it != s.end()){
        cout<< (*it)<<endl;
    }
    s.erase(it);

    print(s);    


/* Given N string, print unique strings in lexiographical(increaing) order with their frequency 
    N <= 10^5
   |S| <=100 */ 

   set<string> s1;
   int n;
   cout<<"Enter size of string: "<<endl;
   cin>>n;
   for(int i=0; i<=n; ++i){
       string str;
        cin>> str;
        s1.insert(str);
   }
   cout<<"The string are:"<<endl;
    for(auto val : s1){
        cout<< val <<endl;  
    } 


// UNORDERED SET

    unordered_set<string> s5;
    s5.insert("Him");       // O(1)
    s5.insert("anshu");
 
    auto itt = s5.find("abcd");    // o(1)
    if(itt != s5.end()){
        cout<< (*itt)<<endl;
    }
    s5.erase(itt);

    print(s5);   


/* Given N string and Q queries.In each query you are given a string print yes if string is present
    N <= 10^6
   |S| <=100 
   Q <= 10^6 */

    unordered_set<string> s2;
   int num;
   cout<<"Enter size of string: "<<endl;
   cin>>num;
   for(int i=0; i<=num; ++i){
       string str;
        cin>> str;
        s2.insert(str);
   }
   cout<<"How many string you find:"<<endl; 
    int q;
    cin>>q;
    while (q--){
        string str;
        cin>>str;
        if(s2.find(str) == s2.end()){
            cout<<"NOT FOUND!"<<endl;
        }else{
            cout<<"FOUNDED!"<<endl;
        }
    }


// MULTI SET

    multiset<string> s7;
    s7.insert("babc");       // O(logn)
    s7.insert("abcd");
    s7.insert("abcd");
 
    auto iter = s7.find("abcd");    // Iterator
    if(iter != s7.end()){
        cout<< (*iter)<<endl;
    }
    s7.erase(iter);

    print(s7);

    return 0;  
}