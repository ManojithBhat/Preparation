# Cousins in Binary Tree II
[Problem Link](https://leetcode.com/problems/cousins-in-binary-tree-ii/description/)

## Problem desciption 
Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root node to it.

**Input:** root = [5,4,9,1,10,null,7]<br>
**Output:** [0,0,0,7,7,null,11]<br>
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.<br>
- Node with value 5 does not have any cousins so its sum is 0.<br>
- Node with value 4 does not have any cousins so its sum is 0.<br>
- Node with value 9 does not have any cousins so its sum is 0.<br>
- Node with value 1 has a cousin with value 7 so its sum is 7.<br>
- Node with value 10 has a cousin with value 7 so its sum is 7.<br>
- Node with value 7 has cousins with values 1 and 10 so its sum is 11.<br>


## constraints
* The number of nodes in the tree is in the range [1, 105].
* 1 <= Node.val <= 104

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int, int> mp;
        queue<TreeNode*> q;

        q.push(root);
        int lvl = 0;
        while (!q.empty()) {
            int n = q.size();

            int sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    sum += node->left->val;
                    q.push(node->left);
                }
                if (node->right) {
                    sum += node->right->val;
                    q.push(node->right);
                }
            }
            mp[lvl] = sum;
            lvl++;
        }

        q.push(root);
        root->val = 0;
        lvl = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                int levelSum = mp[lvl];
                int sum = 0;
                if (node->left) {
                    sum += node->left->val;
                }
                if (node->right) {
                    sum += node->right->val;
                }
                if (node->left) {
                    node->left->val = levelSum - sum;
                    q.push(node->left);
                }
                if (node->right) {
                    node->right->val = levelSum - sum;
                    q.push(node->right);
                }
            }
            lvl++;
        }
        return root;
    }
};

```


## Complexity
- Time complexity: O(2N)


- Space complexity: O(2N)
