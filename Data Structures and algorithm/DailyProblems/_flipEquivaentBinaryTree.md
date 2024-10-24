# Flip Equivalent Binary tree
[Problem Link](https://leetcode.com/problems/flip-equivalent-binary-trees/solutions/)

## Problem desciption 
For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.


### Example 1
**Input:** root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
**Output:** true
**Explanation:** We flipped at nodes with values 1, 3, and 5.


## constraints
* The number of nodes in each tree is in the range [0, 100].
* Each tree will have unique node values in the range [0, 99].

## Code
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root1, TreeNode* root2){
        
        if(root1 == NULL || root2 == NULL) return root1 == root2;
        if(root1->val != root2->val ) return false;

        int l1=-1,r1=-1,l2=-1,r2=-1;
        if(root1->left) l1 = root1->left->val; 
        if(root1->right) r1 = root1->right->val;
        if(root2->left ) l2 = root2->left->val;
        if(root2->right) r2 = root2->right->val;

        if(l1 == r2 && l2 == r1){ 
            TreeNode* temp =root2->left;
            root2->left = root2->right;
            root2->right =  temp;
        }else if(l1 != l2 || r1 != r2) return false;

        if(solve(root1->left,root2->left)==false || solve(root1->right,root2->right)==false) return false;
        return true;
    }


    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return true;
        
        bool res =  solve(root1,root2);
        return res;

    }
};
```

## Intuition
MY intution was to go like check equivalent binary tree, there the we checked for left and right of the binary tree, as there is an addn constraint that the nodes is flipped i just check if they are flipped, if they are flipped then i will interchange the left and right subtree and proceed.

## Approach
Recurstion

## Complexity
- Time complexity: O(N)


- Space complexity: O(N)
