# House Robber 
[Problem Link](https://leetcode.com/problems/house-robber)

## Problem desciption 
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

### Example 1:

>  **Input:** nums = [1,2,3,1]<br>
>  **Output:** 4<br>
>  **Explanation:** Rob house 1 (money = 1) and then rob house 3 (money = 3).<br>
Total amount you can rob = 1 + 3 = 4.

## constraints
* 1 <= nums.length <= 100
* 0 <= nums[i] <= 400

## Code
```cpp
class Solution {
public:
    int solve(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind == 0)
            return nums[ind];
        if (ind < 0)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int notPick = 0 + solve(ind - 1, nums, dp);
        int pick = nums[ind];
        if (ind > 1) {
            pick += solve(ind - 2, nums, dp);
        }

        return dp[ind] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n,-1);
        // return solve(n-1,nums,dp);

        vector<int> dp(n, 0);

        dp[0] = nums[0];
        for (int ind = 1; ind < n; ind++) {
            int notPick = 0 + dp[ind - 1];
            int pick = nums[ind];
            if (ind > 1) {
                pick += dp[ind - 2];
            }

            dp[ind] = max(pick, notPick);
        }

        return dp[n-1];
    }
};
```

## Intuition
A pick and not pick condition with one more extra constraint added to it.


## Approach


## Complexity
- Time complexity: O(n)


- Space complexity:O(n)
