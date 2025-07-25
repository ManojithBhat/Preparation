# Tree Boundary Traversal

[Problem Link](https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1)

## Problem desciption 
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.

Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 


## constraints
* 1 ≤ number of nodes ≤ 105
* 1 ≤ node->data ≤ 105

## Code
```cpp
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:

    bool isleaf(Node* root) {
        if(root->left==NULL && root->right==NULL) return true;
        return false;
    }


    void addLeftBoundary(Node *root,vector<int> &res){
        Node* curr = root->left;
        while(curr){
            if(isleaf(curr)==false) res.push_back(curr->data); //pushing it only if it is not a leaf 
            if(curr->left!=NULL) curr = curr->left;
            else curr = curr->right;
        }
    }
    
   void addRightBoundary(Node *root,vector<int> &res){
       //create a temp vector as we need to give in rev fashion 
       vector<int> temp;
        Node* curr = root->right;
        while(curr){
            if(isleaf(curr)==false) temp.push_back(curr->data); //pushing it only if it is not a leaf 
            if(curr->right!=NULL) curr = curr->right;
            else curr = curr->left;
        }
        
        for(int i=temp.size()-1;i>=0;--i){
            res.push_back(temp[i]);
        }
       
   }
   
   void addLeaves(Node *root,vector<int> &res){
       //any sort of traversal but put only leaf node as a condition 
       if(isleaf(root)){
           res.push_back(root->data);
           return;
       }
       if(root->left) addLeaves(root->left,res);
       if(root->right) addLeaves(root->right,res);
   }
    
    vector <int> boundary(Node *root)
    {
        vector<int> res;
        //checking whether it is a binary tree;
        if(!root) return res;
        //checking if root is not leaf and putting that in the res
        if(!isleaf(root)) res.push_back(root->data);
        addLeftBoundary(root,res);
        addLeaves(root,res);
        addRightBoundary(root,res);
        return res;
    }
};
```

## Intuition
We need to traverse left to bottom, all the leaf node and then from right to the top. 
1. Add the root node to the result. 
2. start from the left tree, keep moving to the left, if left isn't there move to the right untill you rech the leaft node.
3. add all the leaf node. 
4. move right if it exist, else move to the left. untill you encounter the leaf, now rotate and then add all of the above result.

## Approach


## Complexity
- Time complexity: O(N)

- Space complexity:O(1)
