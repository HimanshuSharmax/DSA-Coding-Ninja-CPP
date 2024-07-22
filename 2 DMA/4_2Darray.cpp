#include<iostream>
using namespace std;
int main(){
    int row,col;
    cout<<"Enter no. of Rows and Colummn"<<endl;
    cin>>row>>col;

    int ** array =new int*[row];
    for(int i=0;i<row;i++){
        array[i] = new int[col];
        for(int j=0;j<col;j++){
            cin>>array[i][j];
        }
    }
    for(int i=0;i<row;i++){           // For delete heap memory(row)
        delete [] array[i];
    }
    delete []array;

}