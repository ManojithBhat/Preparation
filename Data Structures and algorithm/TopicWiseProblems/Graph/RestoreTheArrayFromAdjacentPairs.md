# Restor the array from the adjacent pairs
[Problem Link](https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/)

## Problem desciption 
There is an integer array nums that consists of n unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in nums.

You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.

It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.

Return the original array nums. If there are multiple solutions, return any of them.

### Example 1:

**Input:** adjacentPairs = [[2,1],[3,4],[3,2]]<br>
**Output:** [1,2,3,4]<br>
**Explanation:** This array has all its adjacent pairs in adjacentPairs.<br>
Notice that adjacentPairs[i] may not be in left-to-right order.<br>

## constraints
* nums.length == n
* adjacentPairs.length == n - 1
* adjacentPairs[i].length == 2
* 2 <= n <= 105
* -105 <= nums[i], ui, vi <= 105
* There exists some nums that has adjacentPairs as its pairs.

## Code
```cpp
class Solution {
public:
    void dfs(int node,unordered_map<int,int> &vis,unordered_map<int,vector<int>> &adj,vector<int>&res){
        vis[node]++;
        res.push_back(node);
        for(auto child: adj[node]){
            if(vis.find(child)==vis.end()){
                dfs(child,vis,adj,res);
            }
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {

        int n = adjacentPairs.size();
        unordered_map<int,vector<int>> adj(n);
        int start = 0;

        for(auto it: adjacentPairs){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        //look for the node that has only one element in the adj list
        for(auto it: adj){
            if(it.second.size() == 1){
                start = it.first;
                break;
            }
        }
        //perform the dfs traversal from this node 
        vector<int> res;
        unordered_map<int,int> vis;
        dfs(start,vis,adj,res);
        return res;
    }
};

```

## Intuition
The idea was to construct the graph from the given 2D array by converting it into the adjacency list and then find the probable last element in the array that is the node with only one element and then perform the dfs to construct the entire array. 
* we cannot use the normal visited array as it contains negative elements, so use either set or map.

## Approach


## Complexity
- Time complexity:
 O(N)

- Space complexity: O(N)
