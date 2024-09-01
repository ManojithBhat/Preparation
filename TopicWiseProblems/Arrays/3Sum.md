# 3 Sum
[Problem Link](https://leetcode.com/problems/3sum/submissions/1375163036/)

## Problem desciption 

Given an integer array nums, return all the triplets [nums [i], nums [j], nums such that
i
!= j, i != k' and j != k, and nums [i] + nums[jl + nums [k]
Notice that the solution set must not contain duplicate triplets.

## constraints


## Code
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());

        for(int i = 0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int s = i+1;
            int e = n - 1;
            
            while(s<e){
                int sum = nums[i];
                sum += (nums[s] + nums[e]);
                if(sum == 0){
                    res.push_back({nums[i],nums[s],nums[e]}); 
                    s++;
                    e--;
                    while(s<e && nums[s] == nums[s - 1]) s++;
                    while(s<e && nums[e] == nums[e  + 1] ) e--;
                }
                else if(sum < 0){
                    s++;
                }else e--;
            }
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
