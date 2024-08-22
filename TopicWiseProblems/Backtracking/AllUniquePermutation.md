# All Unique Permutations of an array
[Problem Link](https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/0)

## Problem desciption 
Given an array arr[] of length n. Find all possible unique permutations of the array in sorted order. A sequence A is greater than sequence B if there is an index i for which Aj = Bj for all j<i and Ai > Bi.

### Example 1 
**Input:** 
n = 3<br>
arr[] = {1, 2, 1}<br>
**Output:** 
1 1 2<br>
1 2 1<br>
2 1 1<br>
**Explanation:**
These are the only possible unique permutations<br>
for the given array.<br>

## constraints
* 1 ≤ n ≤ 9

## Code
```cpp
class Solution {
  public:
    void solve(int ind,vector<int>&arr,vector<int> &res,set<vector<int>>&ans,vector<int>&vis){
        if(ind == arr.size()){
            ans.insert(res);
            return;
        }        
        
        for(int i=0;i<arr.size();i++){
            if(!vis[i]){
                vis[i] = 1;
                res.push_back(arr[i]);
                solve(ind+1,arr,res,ans,vis);
                vis[i] = 0;
                res.pop_back();
            }
        }
    }
  
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<int> vis(n,0);
        vector<int> res;
        set<vector<int>>ans;
        solve(0,arr,res,ans,vis);
        
        vector<vector<int>> final;
        for(auto it: ans){
            final.push_back(it);
        }
        
        return final;
    }
};

```

## Intuition
This problem is similar to the generate all permutation, but the only changes is we need to generate all the unique permutation, for this we keep a set which stores all the element only once, and then we transfer everything to the array .


## Complexity
- Time complexity: O(n!*n)
 

- Space complexity: O(n!*n)
