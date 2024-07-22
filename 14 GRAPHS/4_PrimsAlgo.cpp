#include<iostream>
#include<climits>
using namespace std;                     // BY  Adjacency Matrix    d= O(n^2) ,n = no of ver

int findMinVertex(int* weights, bool* visited, int numOfver){

    int minVertex = -1;
    for(int i=0; i<numOfver; i++){
        if(!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void Prims(int** edges, int numOfVer){

    int* parent = new int[numOfVer];
    int* weights = new int[numOfVer];
    bool* visited = new bool[numOfVer];

    for(int i=0; i<numOfVer; i++){
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    parent[0] = -1;
    weights[0] = 0;

    for(int i=0; i<numOfVer; i++){                                   // O(n-1)
        // Find min vertex
        int minVertex = findMinVertex(weights, visited, numOfVer);   // O(n * n-1)
        visited[minVertex] = true;

        // Explore un-visited neighbours
        for(int j=0; j<numOfVer; j++){                               // O(n * n-1)
            if(edges[minVertex][j] != 0  &&  !visited[j]){
                if(edges[minVertex][j] < weights[j]){
                    weights[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    // For Printing
    cout<<endl;
    cout<<"The MST are- "<<endl;
    for(int i=1; i<numOfVer; i++){
    if(parent[i] < i){
        cout<< parent[i] <<" "<< i <<" "<<weights[i]<<endl;
    }else{
        cout<< i <<" "<< parent[i] <<" "<<weights[i]<<endl;
    }
    }
}

int main(){
 
    int NumOfVertices;
    cout<<"Enter Num Of Vertices: "<<endl;
    cin>>NumOfVertices;
    int NumOfEdge;
    cout<<"Enter Num Of Edges: "<<endl;
    cin>> NumOfEdge;

    int** edges = new int*[NumOfVertices];          // Adjacency Matrix
    for(int i=0; i<NumOfVertices; i++){
        edges[i] = new int[NumOfVertices];
        for(int j=0; j<NumOfVertices; j++){         // For removing grabage
            edges[i][j] = 0;
        }
    }

    for(int i=0; i<NumOfEdge; i++){
        int first,second,weight;
        cout<<"Enter First, Second Edges and Weights: "<<endl;
        cin>>first>>second>>weight;
        edges[first][second] = weight;
        edges[second][first] = weight;
    }
    cout<<endl;
    Prims(edges,NumOfVertices);

    for(int i=0; i<NumOfVertices; i++){
        delete[] edges[i];
    }
    delete [] edges;
 
    return 0;
}