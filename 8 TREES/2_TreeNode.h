#include<vector>
using namespace std;
template <typename T>

class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data){                   // Constructor
        this->data = data;
    }

    ~TreeNode(){                        // Destructor
        for(int i = 0 ;i<children.size();i++){
            delete children[i];
        }
    }

};