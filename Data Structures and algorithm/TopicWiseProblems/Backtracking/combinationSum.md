# Combination Sum 2
[Problem Link](https://leetcode.com/problems/combination-sum-ii/description/?envType=daily-question&envId=2024-08-13)

## Problem desciption 
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.


### Example 3
> **Input:** candidates = [10,1,2,7,6,1,5], target = 8 <br>
> **Output:**  <br>
> [ <br>
> [1,1,6], <br>
> [1,2,5], <br>
> [1,7], <br>
> [2,6] <br>
> ] <br>

## constraints
* 1 <= candidates.length <= 100
* 1 <= candidates[i] <= 50
* 1 <= target <= 30

## Code

My Approach
```cpp

    void f(int ind,vector<int>& nums,int sum,vector<int> &arr,vector<vector<int>>&res){
        if(sum<0) return;
        if(sum==0){
            res.push_back(arr);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            arr.push_back(nums[i]);
            f(i+1,nums,sum-nums[i],arr,res);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>arr;
        sort(candidates.begin(),candidates.end());
        f(0,candidates,target,arr,res); 
        return res;
    }


```
A better one !!!
```cpp
class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& c, int index, int target, vector<int>& path) {
        if(index >= c.size() || target <= 0) {
            if(target == 0) ans.push_back(path);
            return;
        }
        
        //pick the current element 
        path.push_back(c[index]);
        solve(c, index + 1, target - c[index], path);
        path.pop_back();

        //do not pick the curr element as well as those element which is same as the curr element in the subsequent index 
        while(index + 1 < c.size() && c[index + 1] == c[index]) index++;
        solve(c, index + 1, target, path);
    } 
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        vector<int> path;
        solve(c, 0, target, path);
        return ans;
    }
};


```

## Intuition
This question is of backtraking as we are supposed to find all the combination ( not only the length or any parameter ). <br>

 This question is an extension of combination sum-1, here we are supposed to find the subset which has sum equal to the given target but it should be unique candidate. The question is what is an unique candidate? take an example of 1,1,1,3,3 when we have choosen 1 as our first element and another 1 from 1st index,we are not supposed to take 1 from the 2nd index bc it generates the same subset, i.e [1,1] and [1,1], to avoid this problem, we go by the approach of subsequence formation and not the traditional pick not pick condition, and while looping we check for condition if(i>ind && nums[i]==nums[i-1]). the reason for taking i>ind and not i>=ind is that when we are in the position ind, we are supposed to take that index even tho the prev ele was same

## Approach
A usual pick not pick problem with the added conditions that whenever there is a similar element in the next iteration. 

## Complexity
- Time complexity: O(2*^n)

- Space complexity: O(n*m)
