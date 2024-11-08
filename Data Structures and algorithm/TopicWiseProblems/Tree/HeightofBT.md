# Height of the tree


## Problem desciption 
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

### Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

### Example 2:
Input: root = [1,null,2]
Output: 2
 

## Constraints:

-The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100


## Code
```
    class Solution {
    public:
        int solve(TreeNode* node){
            if(node==NULL) return 0;
            int left = solve(node->left);
            int right = solve(node->right);
            return 1+max(left,right);
        }

        int maxDepth(TreeNode* root) {
            return solve(root);
        }
    };

```

## Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
To compute the height of the tree - it is basically the height of the left sub tree + height of the right subtree + 1 (curr node)
taking this idea into consideration we can use a recursive algorithm where we basically traverse to left and then right to compute the corresponding height and return 1 + lh + rh and when node is null we return 0

we can also do this by level order traversal - but we end up having the space which is equal to the nodes in the leaf node 

## Approach
<!-- Describe your approach to solving the problem. -->
using recursion 

## Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
O(n) - as we are traversing through the whole tree

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
O(1) - as we are not extra  space except the recursion stack space 