# Linked List in Binary Tree
[Problem Link](https://leetcode.com/problems/linked-list-in-binary-tree/description/?envType=daily-question&envId=2024-09-07)

## Problem desciption 
Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

### Example 1
>**Input:** head = [4,2,8],<br> root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]<br>
**Output:** true<br>
**Explanation:** Nodes in blue form a subpath in the binary Tree.


## constraints
* The number of nodes in the tree will be in the range [1, 2500].
* The number of nodes in the list will be in the range [1, 100].
* 1 <= Node.val <= 100 for each node in the linked list and binary tree.

## Code
```cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool check(TreeNode* tnode, ListNode* lnode) {
        if (lnode == NULL)
            return true;
        if (tnode == NULL)
            return false;

        if (tnode->val == lnode->val) {
            return check(tnode->left, lnode->next) ||
                   check(tnode->right, lnode->next);
        }
        return false;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == NULL)
            return false;
        if (root->val == head->val) {
            if (check(root, head))
                return true;
        }
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

```

## Intuition
The intution is just like word search in grid, we will perform the inorder traversal and whenver we encounter a particular node with the value of the head node of linked list, then we perform the search for that point, we move to the next nodes ( that is left and right with passing lnode->next) if the value of curr tree node and linked list node mathces or else we return false.
The base condition is that if we encounter NULL for the linked list node we return true as we have reached the end of linked list, and the other base condition is that if we reached the trees null we return false as we have exhausted tree but still we did not find the linked list elements, it is crucial to place the first condition above the second as thre could be situation where the both the linked list and tree could reach null at the first place and we ensure that true is returned.

## Approach


## Complexity
- Time complexity: O(n2)


- Space complexity: O(h)
