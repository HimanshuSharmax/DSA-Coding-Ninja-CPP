#include<iostream>
#include<climits>
using namespace std;                    // O(n^2)

int findMinVertex(int *distance, bool* visited,int numOfver){

    int minVertex = -1;
    for(int i=0; i<numOfver; i++){
        if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void Dijkstra(int ** edges,int numOfver){
    int* distance = new int[numOfver];
    bool* visited = new bool[numOfver];

    for(int i=0 ; i<numOfver; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[0] = 0;
    for(int i=0 ; i<numOfver-1; i++){

        int minVertex = findMinVertex(distance, visited, numOfver);
        visited[minVertex] = true;
        for(int j=0 ; j<numOfver; j++){
            if(edges[minVertex][j] != 0  &&  !visited[j]) {
                int dist = distance[minVertex] + edges[minVertex][j];
                if(dist < distance[j]){
                    distance[j] = dist;
                }
            }    
        }
    }

    // For Printing
    cout<<endl;
    cout<<"The Dijkstra's Algo are- "<<endl;
    for(int i=0; i<numOfver; i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    delete[] visited;
    delete[] distance;
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
    Dijkstra(edges,NumOfVertices);

    for(int i=0; i<NumOfVertices; i++){
        delete[] edges[i];
    }
    delete [] edges;
 
    return 0;
}