# Minimum Number of Operations to Sort a Binary Tree by Level
[Problem Link](https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/?envType=daily-question&envId=2024-12-23)

## Problem desciption 
You are given the root of a binary tree with unique values.

In one operation, you can choose any two nodes at the same level and swap their values.

Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.

The level of a node is the number of edges along the path between it and the root node.

 

## Example 1:
**Input**: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]<br>
**Output**: 3<br>
**Explanation**:<br>
- Swap 4 and 3. The 2nd level becomes [3,4].<br>
- Swap 7 and 5. The 3rd level becomes [5,6,8,7].<br>
- Swap 8 and 7. The 3rd level becomes [5,6,7,8].<br>
We used 3 operations so return 3.<br>
It can be proven that 3 is the minimum number of operations needed.<br>


## constraints
* The number of nodes in the tree is in the range [1, 105].
* 1 <= Node.val <= 105
* All the values of the tree are unique.

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
    int binarySearch(vector<int>& nums, int x) {

        int n = nums.size();
        int l = 0, e = n - 1;

        while (l <= e) {
            int mid = (l + e) / 2;

            if (nums[mid] == x) {
                return mid;
            } else if (nums[mid] < x) {
                l = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;
    }

    int solve(vector<int>& nums) {
        vector<int> a = nums;
        sort(a.begin(), a.end());
        int n = nums.size();

        int swapCnt = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == a[i])
                continue;

            while (nums[i] != a[i]) {
                int idx = binarySearch(a, nums[i]);
                swap(nums[idx], nums[i]);
                swapCnt += 1;
            }
        }

        return swapCnt;
    }

    int minimumOperations(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        int num = 0;

        while (!q.empty()) {
            int size = q.size();

            vector<int> v;
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();

                v.push_back(node->val);
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }

           
            num += solve(v);
            
        }

        return num;
    }
};
```

## Intuition
The problem can be broked down into minumum swaps to sort the array, get the numbers of the level in the tree.
sort the array, first check if the number is same in both the a and nums, if yes, then just move on, else until you have both of them equal, by binary search, search the index and swap. it 

## Approach


## Complexity
- Time complexity:


- Space complexity:
