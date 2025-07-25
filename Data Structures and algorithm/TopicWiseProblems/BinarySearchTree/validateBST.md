# Validate Binary Search Tree

[Problem Link](https://leetcode.com/problems/validate-binary-search-tree/description/)

## Problem desciption 
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees


## constraints
* The number of nodes in the tree is in the range [1, 104].
* -231 <= Node.val <= 231 - 1

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
    bool solve(TreeNode* root, long mini, long maxi){
        if(root == NULL) return true;
        if(root->val <= mini || root->val >= maxi) return false;

        return solve(root->left, mini, root->val ) && solve(root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MIN,LONG_MAX);
    }
};

```

## Intuition
1. Check for each node and the range in which it has be present. if its out of range return false. else true.
2. use LLONG min and max

## Approach


## Complexity
- Time complexity:


- Space complexity:
