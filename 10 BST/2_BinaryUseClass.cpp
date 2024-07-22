#include<iostream>
#include<queue>
#include<climits>
#include "1_BinaryTreeNode.h"
using namespace std;

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

void printBetweenK1K2(BinaryTreeNode<int>* root, int k1, int k2){
    if(root == NULL){
        return;
    }
    if(root->data >= k1 && root->data <= k2){
        cout<< root->data <<endl;
    }
    if(root->data > k1){
        printBetweenK1K2(root->left,k1,k2);
    }
    if(root->data<=k2){
        printBetweenK1K2(root->right,k1,k2);
    }
}

int maximum(BinaryTreeNode<int>* root){
     if(root==NULL){
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
int minimum(BinaryTreeNode<int>* root){
    if(root==NULL){
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root){                  // Complexity = best-O(nlogn)   worst=O(n^2)
    if(root == NULL){                                   // This Time Comp = O(n*h)    ,{h=height}
        return true;
    }
    int leftMax = maximum(root->left);
    int RightMin =minimum(root->right);
    bool output = (root->data > leftMax) && (root->data <= RightMin) && isBST(root->left) && isBST(root->right);
    return output;
}

class isBSTclass{
    public:
    bool isBST;
    int minimum;
    int maximum;    
};

isBSTclass isBSTobject(BinaryTreeNode<int>* root){              // O(n)
    if (root==NULL){
        isBSTclass output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    isBSTclass leftoutput = isBSTobject(root->left);
    isBSTclass rightoutput = isBSTobject(root->right);
    int minimum = min(root->data, min(leftoutput.minimum, rightoutput.minimum));
    int maximum = max(root->data, max(leftoutput.maximum, rightoutput.maximum));
    bool isBSTfinal = (root->data > leftoutput.maximum) && (root->data <= rightoutput.minimum) && leftoutput.isBST && rightoutput.isBST;
    isBSTclass output;
    output.minimum = minimum;
    output.maximum = maximum;
    output.isBST = isBSTfinal;
    return output;
}

bool isBSTconstraint(BinaryTreeNode<int>*root, int min = INT_MIN, int max = INT_MAX){
    if(root==NULL){                                                    // O(n)
        return true;
    }
    if(root->data < min || root->data > max){
        return false;
    }
    bool isLeftok = isBSTconstraint(root->left, min ,root->data - 1);
    bool isRightok = isBSTconstraint(root->right, root->data , max);
    return isLeftok && isRightok;
}
vector<int>* getRootToNodePath(BinaryTreeNode<int>* root,int Data){
    if(root==NULL){
        return NULL;
    }
    if(root->data == Data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int>* leftOutput = getRootToNodePath(root->left, Data);
        if(leftOutput !=NULL){
            leftOutput->push_back(root->data);
            return leftOutput;
        }
    
    vector<int>* RightOutput = getRootToNodePath(root->right, Data);
        if(RightOutput !=NULL){
            RightOutput->push_back(root->data);
            return RightOutput;
        }
        else{
            return NULL;
        }
    
}
int main(){
        // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
        // 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int> *root = takeInputLevelWise();
    // printTree(root);
    // cout<<"Print Between 2-5 is: "<<endl;
    // printBetweenK1K2(root,2,5);
 
    //  cout<< "Is Bst? : "<<isBST(root)<<endl;

       // BinaryTreeNode<int> * root = new BinaryTreeNode<int>(out);
       //  isBSTobject(root);

    // cout<< "Is Bst(constraints)? : "<<isBSTconstraint(root);
    // delete root;

    vector<int>* output = getRootToNodePath(root,8);
    for(int i = 0; i< output->size(); i++){
        cout<< output->at(i)<<endl;
    }
    delete output;
 
    return 0;
}