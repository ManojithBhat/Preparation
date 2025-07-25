# Vertical Order Traversal of a Binary Tree
[Problem Link](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/)

## Problem desciption 

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

## constraints
* The number of nodes in the tree is in the range [1, 1000].
* 0 <= Node.val <= 1000

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // to store in the form 
        //{ col {row, { elemets in the oreder }}}
        map<int,map<int,multiset<int>>> m;

        //{node { row,col }}
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            root=node.first;
            int x=node.second.first;
            int y=node.second.second;

            m[x][y].insert(root->val);
            if(root->left)
            {
                q.push({root->left,{x-1,y+1}});
            }
            if(root->right)
            {
                q.push({root->right,{x+1,y+1}});
            }
        }

        vector<vector<int>> ans;
        for(auto i:m){
            vector<int> v;
            for(auto j:i.second){
                v.insert(v.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};

```

without multiset. 
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
    void solve(TreeNode* node, int x,int y,map<int,vector<pair<int,int>>> &mp){
        if(node == NULL) return;

        mp[x].push_back({y,node->val});

        solve(node->left,x - 1, y + 1, mp);
        solve(node->right,x + 1, y + 1,mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mp;
        vector<vector<int>> res;

        solve(root,0,0,mp);

        for(auto it: mp){
            sort(it.second.begin(),it.second.end());
            vector<int> tmp;

            for(int i = 0;i<it.second.size();i++){
                tmp.push_back(it.second[i].second);
            }
            res.push_back(tmp);
           
        }

        return res;
    }
};
```

## Intuition


## Approach


## Complexity
- Time complexity:


- Space complexity:
