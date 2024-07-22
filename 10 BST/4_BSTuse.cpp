#include<iostream>
#include<queue>
#include "3_BinarySearchTree.h"
using namespace std;

int main(){
    BST obj;
    obj.insertData(10);         // BST all Operation = O(h)
    obj.insertData(5);          // insertion = O(h)
    obj.insertData(20);         // deletion = O(h)
    obj.insertData(7);
    obj.insertData(3);
    obj.insertData(15);
    obj.printTree();

    obj.deleteData(10);
    obj.printTree();
    return 0;
}