#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicates(int* arr, int size){
    vector<int> output;
    unordered_map<int, bool> seenNum;           // <key,value>
    for(int i=0 ; i<size ; i++){
        if(seenNum.count(arr[i]) > 0 ){
            continue;
        }
        seenNum[arr[i]] = true;                 // O(n)
        output.push_back(arr[i]);
    }
    return output;
}

int main(){
    int arr[] = {1,2,3,3,2,1,4,3,6,5,5};
    vector<int> output = removeDuplicates(arr, 11);
    for(int i=0 ; i<output.size() ; i++){
        cout<< output[i]<<endl;
    }

    return 0;
}