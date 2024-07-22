#include<iostream>
#include<queue>
#include "1_BinaryTreeNode.h"
using namespace std;

pair<int, int> heightDiameter(BinaryTreeNode<int>* root){           //Inbuild pair class
    if(root == NULL){
        pair<int,int> p;                                            // Time Complexity O(n)
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int,int> leftAns = heightDiameter(root->left);
    pair<int,int> rightAns = heightDiameter(root->right);
    int lh = leftAns.first;
    int rh = rightAns.first;
    int ld = leftAns.second;
    int rd = rightAns.second;

    int height = 1 + max(lh,rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter data(for NULL -1) : "<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
   
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int leftChildData;
        cout<<"Enter left Child of "<<front->data<<endl;
        cin>>leftChildData;
        if(leftChildData != -1){
           BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
           front->left = child;
           pendingNodes.push(child);
        }

        int rightChildData;
        cout<<"Enter right Child Data "<<front->data<<endl;
        cin>>rightChildData;
        if(rightChildData != -1){
           BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
           front->right = child;
           pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" : ";
    if(root->left !=NULL){
        cout<<"L("<<root->left->data<<")"<<" ";
    }
    if(root->right !=NULL){
        cout<<"R("<<root->right->data<<")";
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

int numNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right);
}

int main(){
 
    BinaryTreeNode<int> * root = takeInputLevelWise();
    printTree(root);
    cout<<"Total Nodes: "<< numNodes(root)<<endl;

    pair<int,int> p = heightDiameter(root);
    cout<<"Height: "<< p.first<<endl;
    cout<<"Diameter: "<< p.second<<endl;
    delete root;
 
    return 0;
}