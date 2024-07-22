#include<iostream>
#include<queue>
#include "2_TreeNode.h"
using namespace std;

TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter data : "<<endl;
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout<<"Enter num of childrem of "<<rootData<<endl;
    cin>>n;
    for(int i = 0; i<n; i++){
        TreeNode<int>* child =  takeInput();
        root->children.push_back(child);
    }
    return root;
}

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data : "<<endl;
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size()!=0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter num of children of "<<front->data<<endl;
        cin>>numChild;
        for(int i = 0 ;i<numChild;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;  
}

void printTree(TreeNode<int> *root){
    if(root == NULL){ 
        return;
    }

    cout<< root->data <<" : ";                             // For children(data)
    for(int i=0;i<root->children.size();i++){
        cout<< root->children[i]->data <<",";
    }
    cout<<endl;

    for(int i=0;i<root->children.size();i++){             // For Parent
        printTree(root->children[i]);
    }
}

int numNodes(TreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int ans=1;
    for(int i=0 ; i<root->children.size();i++){
        ans += numNodes(root->children[i]);
    }
    return ans;
}

void printAtLevelK(TreeNode<int>* root,int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<endl;
        return;
    }
    for(int i=0 ; i<root->children.size();i++){
        printAtLevelK(root->children[i],k-1);
    }
}

void preorder(TreeNode<int>* root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    for(int i=0 ; i<root->children.size();i++){
        preorder(root->children[i]);
    }
}

void deleteTree(TreeNode<int>* root){
    for(int i=0 ; i<root->children.size();i++){
        deleteTree(root->children[i]);
    }
    delete root;
}

int main(){
 
    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *node1 = new TreeNode<int>(2);
    // TreeNode<int> *node2 = new TreeNode<int>(3);
    // TreeNode<int> *node3 = new TreeNode<int>(4); 
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // node1->children.push_back(node3);

    TreeNode<int> * root = takeInputLevelWise();
    printTree(root);
 
    cout<<"Total Node count : "<<numNodes(root)<<endl;
    numNodes(root);
    cout<<"Node Print at level 2 : "<<endl;
    printAtLevelK(root,2);
    cout<<"Preorder Tree : "<<endl;
    preorder(root);

 // deleteTree(root);
    delete(root);           // Deleting by destructor
    return 0;
}