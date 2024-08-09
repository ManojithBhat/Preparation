## LCS Of Binary Search Tree


## Problem desciption 
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”


### Example 1:
> **Input:** root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
> <br>
> **Output:** 6
> <br>
>**Explanation:** The LCA of nodes 2 and 8 is 6.


### Example 2:

> **Input:** root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
> <br>
> **Output:** 2
> <br>
> **Explanation:** The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.


## Constraints:

* The number of nodes in the tree is in the range [2, 105].
* -109 <= Node.val <= 109
* All Node.val are unique.
* p != q
* p and q will exist in the BST.



# Code
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(TreeNode* node, TreeNode* p,TreeNode* q){
        if(node==NULL) return NULL;

        if(node->val > p->val && node->val > q->val){
            return solve(node->left,p,q);
        }
        if(node->val < p->val && node->val < q->val){
            return solve(node->right,p,q);
        }
        return node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};

```

# Intuition
Event though the same procedure for finding the LCA of the binary tree could be used here, but utilising the property of the binary search tree should be a prime point.
It is worth noting that the LCA of the BST would be less than one of the element and greater than the another, if we encounter a node whose value is greater than both of the value then we need to look to the left of the tree, similarly if the value of the node is lesser than both of the value, then we need to go to the right of the tree.
3. if we encounter any node whose value is in between both of the given value, then that would be our required LCA

# Approach
The intution itsef describes the approach 

# Complexity
- Time complexity:O(n) - at the worth case 

- Space complexity:O(logn) - at max it could go upto the depth of the tree 
