#include<iostream>
#include <algorithm>                        // For inbuild sort

using namespace std;

class Edge{                  // BY UNION-FIND ALGO = O(ElogE + EV) -> ElogE for sorting, EV for cycle detection
    public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

int findParent(int vertex, int *parent){
    if(parent[vertex] == vertex){
        return vertex;
    }
    return findParent(parent[vertex], parent);
}

void Kruskals(Edge* input, int numOfver, int numOfedge){
    // sort the input array - ascending onder based on weights
    sort(input, input+numOfedge, compare);          // Inbuild sort(staring, staring+ending)

    // Create output
    Edge* output = new Edge[numOfver - 1];

    int *parent = new int[numOfver];       // Union-Find algo for kruskals
    for(int i=0; i<numOfver ; i++){
        parent[i] = i;              // for now every vertex parent itself
    }

    int count = 0;
    int i = 0;
    while(count != numOfver - 1){
        Edge currentEdge = input[i];

        // check if we can add the  currentEdge in MST(Min Spanning tree) or not
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if(sourceParent != destParent){
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }

    // Printing MST
    cout<<endl;
    cout<<"The MST are- "<<endl;
    for(int i=0; i<numOfver-1 ; i++){
        if(output[i].source < output[i].dest){
            cout<< output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }else{
            cout<< output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;            
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

    Edge* input = new Edge[NumOfEdge];

    for(int i=0; i<NumOfEdge; i++){
        int s,d,w;
        cout<<"Enter Source, Dest. and Weights: "<<endl;
        cin>> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;      
    }

    Kruskals(input, NumOfVertices, NumOfEdge);

 
    return 0;
}