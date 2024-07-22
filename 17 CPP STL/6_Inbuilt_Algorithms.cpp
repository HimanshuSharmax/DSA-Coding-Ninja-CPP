#include<bits/stdc++.h>
using namespace std;
int main(){
 
    int size;
    cin>> size;
    vector<int> v(size);
    for(int i=0; i<=size; ++i){
        cin>>v[i];
    }
    
    int min = *min_element(v.begin()+1 , v.end());      // ALL O(n)
    cout<< "Min- "<< min <<endl;
    int max = *max_element(v.begin() , v.end());        // For array (v,v+size)
    cout<< "Max- "<< max <<endl;
    int sum = accumulate(v.begin() , v.end(),0);
    cout<< "Sum- "<< sum <<endl;
    int ct = count(v.begin() , v.end(),14);
    cout<< "count- "<< ct <<endl;
    auto it = find(v.begin(),v.end(),10);
    if(it != v.end()){
        cout<<"Founded "<< *it<<endl;
    }else{
        cout<< "Element not found"<<endl;
    }

    reverse(v.begin(),v.end());
    for(auto val : v){
        cout<< "Reverse Vector- "<< val<<endl;
    }

    string s ="asgidi";
    reverse(s.begin(),s.end());
    cout<<"Reversed String- "<<endl;


    
 
    return 0;
}