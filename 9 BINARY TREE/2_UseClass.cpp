#include<iostream>
#include<queue>
#include "1_BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter data(for NULL -1) : "<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
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

void inOrder(BinaryTreeNode<int>* root){            // InOder: L->Node->R
    if(root==NULL){
        return;
    } 
    inOrder(root->left);
    cout<< root->data <<" ";
    inOrder(root->right);
}

int main(){
 
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    // BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    // root->left = node1;
    // root->right = node2;

 // BinaryTreeNode<int>* root = takeInput();
    BinaryTreeNode<int>* root = takeInputLevelWise();

    printTree(root);
    cout<<"Total Nodes: "<< numNodes(root) <<endl;

    cout<<"InOder Traversal: ";
    inOrder(root);
    delete root;
 
    return 0;
}