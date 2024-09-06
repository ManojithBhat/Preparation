# Lowest Common Ancestor of the binary tree 


## Problem desciption 
<!-- Describe the problem  -->
Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

### Example 1:

Input:
n1 = 2 , n2 = 3  
       1 
      / \ 
     2   3
Output: 1
Explanation:
LCA of 2 and 3 is 1.

### Example 2:

Input:
n1 = 3 , n2 = 4
           5    
          /    
         2  
        / \  
       3   4
Output: 2
Explanation:
LCA of 3 and 4 is 2. 

### Example 3:

Input:
n1 = 5 , n2 = 4
           5    
          /    
         2  
        / \  
       3   4
Output: 5
Explanation:
LCA of 5 and 4 is 5. 
Your Task:
You don't have to read, input, or print anything. Your task is to complete the function lca() that takes nodes, n1, and n2 as parameters and returns the LCA node as output. 



### Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105


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

        if(node == p || node == q) return node;

        TreeNode* left = solve(node->left,p,q);
        TreeNode* right = solve(node->right,p,q);

        if(left != NULL &&  right == NULL ) return left;
        else if(left == NULL && right !=NULL) return right;
        else if(left == NULL && right == NULL ) return NULL;
        else return node; 
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};

```

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
We are required to return the node that is common to both node given, the way to do this is to traverse and whenever we encounter either of the required node, we return it, at every call we are checking whether there is some returned value from the previous call
2. if we have any return value ( if either of the left or right and the root ( as this is the LCA))

# Approach
<!-- Describe your approach to solving the problem. -->
Recursive approach with 
1. base case - if the node is null then return 
2. call left and right recursion call which returns some node
3. check if there is a return value ( node ) exist 
4. return the node 

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->