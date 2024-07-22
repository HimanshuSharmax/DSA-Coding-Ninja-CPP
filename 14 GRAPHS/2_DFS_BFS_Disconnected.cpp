#include<iostream>
#include<queue>
using namespace std;

void printDFS(int** edges, int numOfVer, int startingVer, bool* visited ){
    cout<< startingVer <<endl;
    visited[startingVer] = true;                      // Marked as visited

    for(int i=0; i<numOfVer; i++){
        if(i == startingVer){
            continue;
        }
        if(edges[startingVer][i] == 1){              // 0-2 so not call 2-0
            if(visited[i] == 1){
                continue;                  // Skip
            }
            printDFS(edges,numOfVer,i,visited);
        }
    }
}


void printBFS(int** edges, int numOfver, int startingVer,bool* visited){
    queue<int> pendingVertices;

    pendingVertices.push(startingVer);
    visited[startingVer] = true;
    while( !pendingVertices.empty()){
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout<< currentVertex <<endl;
        for(int i=0; i<numOfver; i++){
            if(i == currentVertex){
                continue;
            }
            if(edges[currentVertex][i] == 1 && !visited[i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}


void BFS_Disconnected(int ** edges, int numOfver){

    bool* visited = new bool[numOfver];                 // When No visited so marked false
    for(int i=0; i<numOfver; i++){
        visited[i] = false;
    }

    for(int i=0; i<numOfver; i++){
        if(!visited[i])
        printBFS(edges,numOfver,i,visited);
    }
    delete [] visited;
}


void DFS_Disconnected(int ** edges, int numOfver){

    bool* visited = new bool[numOfver];                 // When No visited so marked false
    for(int i=0; i<numOfver; i++){
        visited[i] = false;
    }

    for(int i=0; i<numOfver; i++){
        if(!visited[i])
        printDFS(edges,numOfver,i,visited);
    }
    delete [] visited;
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
        int first,second;
        cout<<"Enter First and Second Edges: "<<endl;
        cin>>first>>second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }

    bool* visited = new bool[NumOfVertices];
    for(int i=0; i<NumOfVertices; i++){
        visited[i] = false;
    }
    
    cout<<endl;
    cout<<"The DFS Diconnected Graphs are: "<<endl;
    BFS_Disconnected(edges, NumOfVertices);

    cout<<endl;
    cout<<"The BFS Diconnected Graphs are: "<<endl;
    DFS_Disconnected(edges, NumOfVertices);


    delete[] visited;
    for(int i=0; i<NumOfVertices; i++){
        delete[] edges[i];
    }
    delete [] edges;
 
    return 0;
}