## diamter of the tree 

# Problem desciption 
<!-- Describe the problem  -->
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

### Example 1:

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

### Example 2:

Input: root = [1,2]
Output: 1

# Code
```

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
    
    int solve(TreeNode* node,int &dia){
        if(node==NULL) return 0;
        int left = solve(node->left,dia);
        int right = solve(node->right,dia);
       dia = max(dia,left+right);
        return 1+ max(left,right);
    
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        solve(root,dia);
        return dia;
    }
};

```

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The diameter is defined as the max distance between any two nodes. so the first thought that can come to mind is we may find the vertical distance but that doesnt work, the other approach is that being in the particular node, we may try to add the left height and the right height, the naive approach could be to find the sum of left and right height for the left and right subtree but that would be a n2 soln , combining the logic of finding the height of the tree, can be a better one 

# Approach
<!-- Describe your approach to solving the problem. -->
Similar to finding the max height of the tree

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$O(n)$$ - as we are traversing the tree once and finding the max among all 

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$O(n)$$ if we try to take the recurssion stack space else it is $$O(1)$$