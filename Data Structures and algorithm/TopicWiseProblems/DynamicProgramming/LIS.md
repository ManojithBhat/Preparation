# Longest Increasing Subsequence
[Problem Link](https://leetcode.com/problems/longest-increasing-subsequence/)

## Problem desciption 
Given an integer array nums, return the length of the longest strictly increasing 
subsequence.

### Example 1:
> 
> **Input:** nums = [10,9,2,5,3,7,101,18]<br>
> **Output:** 4<br>
> **Explanation:** The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
> 

## constraints
* 1 <= nums.length <= 2500
* -104 <= nums[i] <= 104

## Code

Memoisation code

```cpp

 int solve(int ind,int prev, vector<int>&nums,vector<vector<int>> &dp){
        if(ind == nums.size()) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1]; //we have to use prev+1 as we cannot use -1 in the index.

        int pick = 0;
        if(prev == -1 || nums[prev] < nums[ind]){
            pick = 1 + solve(ind+1,ind,nums,dp);
        }
        //In the call we should pass prev and not -1;
        int notPick = solve(ind+1,prev,nums,dp);
        return dp[ind][prev+1] = max(notPick,pick);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        //memoization 
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1 ,-1));
        return solve(0,-1,nums,dp);
    }

```
Tabulation
```cpp
      int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); 
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int ind = n-1;ind>=0;ind--){
            for(int prev = ind-1;prev>=-1;prev--){
                int pick = 0;
                if(prev == -1 || nums[prev] < nums[ind]){
                    pick = 1 + dp[ind+1][ind+1];
                }
                int notPick = dp[ind+1][prev+1];
                dp[ind][prev+1] = max(pick,notPick);
            }
        }

        return dp[0][0];
      }

```

Optimised approach 
```cpp

   int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
       
        vector<int> dp(n+1,1); //atlease 1 element will be the increasing sequence
        int incSeq = 0;
        for(int ind = 0 ;ind< n;ind++){
            for(int prev = 0;prev<ind;prev++){
                if(nums[prev] < nums[ind]){
                    dp[ind] = max(dp[ind],1+dp[prev]);
                }
            }
            incSeq = max(incSeq,dp[ind]);
        }

        return incSeq;
    }

```

There is also another way to do it by the binary search. 

## Intuition
The intution for the longest increasing subsequence is that we need to find a subsequence that is increasing.

**Memoisation**
Here we keep 2 variables prev ( which stores the prev index of the increasing subsequecne ) and the current index. 
By the usual logic of pick and notPick, where we choose the curr element only when the prevElement choosen ( but passed as an index hence it is nums[prev] < nums[ind]) or the prev is -1 ( thisis the first element to be choosen ).
In the notPick case we do not take this element and pass the prev index as it is.


**Tabulation**
Here we need to employee the concept of index shifting, as it is not possible to keep an array index of negative we shift our scale by 1 so that prv =- 1 accomodate, we also keep a dp array of size n+1,n+1 to accomodate index+1 case.<br>
Here we increment all the parameter that has negative dependencies ( for example prev here) . in the pick case we use dp[ind+1][ind+1].
By using the same logic as memoisation we calculate the LIS, and return the value stored at dp[0][-1+1].


**Space Optimisation**
```We note that the dp[i] represent the LIS length till the index i```
Which means the value till i is counted then we can use the same for the next subsequent index.<br>
we calculate the LIS till there and update the dp[i] value when we got a prevIndex ( 0 -> ind) such that nums[prevIndx] < nums[currIndx]. and then we take max of all the dp values to get the answer. 

> Note : Do a dry run on the example test case for better clarity. Do draw the tabular code as well as 1D dp.
> Do take care to send the prevIdx in the memoisation code and not the -1 in the not Pick condition.
> As it involves index there is a high chance of getting runtime error, pay a special attention and use shifted index concept in the prev variable. 


## Complexity
- Time complexity: O(N^2)


- Space complexity: O(N^2) + O(N) - memoization code, O(N^2) for tabulation and O(N) for space optimised one.
