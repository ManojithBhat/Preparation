
/*

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Input: p = [1,2,1], q = [1,1,2]
Output: false

Input: p = [1,2,3], q = [1,2,3]
Output: true

Input: p = [1,2], q = [1,null,2]
Output: false

*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL) return p == q;
       if(p->val != q->val) return false;
        return (isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));
    }
};

/*
intution : 
    In this problem we are given 2 binary trees and we need to check if they are same or not. so the first thing that comes to mind is to use the recursive approach. we have to traverse ( it could be in any of the order ) if at all the nodes they have same structure and same value then we can say that they are same, if one of them is null and the other is not null then we can say they are not the same, 
    however if both are null then they could be same, so we deal with this situation in a single base case that is if p==NULL or q==NULL then return p==q.
    
    time complexity : O(N) as we are traversing the tree only once.
    space complexity : O(1) as we are not using any extra space.
    
    pitfall : in the base case we have to check if p==NULL or q==NULL then return p==q. if we check if p==NULL then return p==q then it will throw an error as p is null and we are checking the value of p.

*/