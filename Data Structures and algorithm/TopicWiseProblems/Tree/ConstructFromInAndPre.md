# Construct Binary Tree from Preorder and Inorder Traversal
[Problem Link](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

## Problem desciption 
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

### Example 1:

**Input:** preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]<br>
**Output:** [3,9,20,null,null,15,7]


## constraints
* 1 <= preorder.length <= 3000
* inorder.length == preorder.length
* -3000 <= preorder[i], inorder[i] <= 3000
* preorder and inorder consist of unique values.
* Each value of inorder also appears in preorder.
* preorder is guaranteed to be the preorder traversal of the tree.
* inorder is guaranteed to be the inorder traversal of the tree.

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
    void createMap(vector<int> &inorder,unordered_map<int,queue<int>> &mp){
        int n = inorder.size();
        for(int i = 0;i<n;i++){
            mp[inorder[i]].push(i);
        }
    }

    TreeNode* solve(vector<int> &preorder,vector<int> &inorder,int &index,int startInd, int endInd,unordered_map<int,queue<int>> &mp){
        int n = preorder.size();
        if(index == n or startInd > endInd){
            return NULL;
        }

        int nodeVal = preorder[index++];
        TreeNode* node = new TreeNode(nodeVal);

        int pos = mp[nodeVal].front();
        mp[nodeVal].pop();

        node->left = solve(preorder,inorder,index,startInd,pos-1,mp);
        node->right = solve(preorder,inorder,index,pos+1,endInd,mp);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        int preIndexStart = 0, preIndexEnd = preorder.size() - 1;
        unordered_map<int,queue<int>> mp;

        createMap(inorder,mp);
        return solve(preorder,inorder,index,preIndexStart,preIndexEnd,mp);
    }
};
```

## Intuition
In preorder it is node-left-right and in inorder it is left-node-right, <br>
so traverse from the left to right in the preorder find the position in the inorder and then call tree builiding function left and right of the found position, stop it at the time when you have no element or the index crosses the queue is used to handle any duplicate elements that could be found in the tree constrction.

## Complexity
- Time complexity: O(N)


- Space complexity: O(N)
