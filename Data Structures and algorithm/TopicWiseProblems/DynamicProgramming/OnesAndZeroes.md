# Ones and Zeroes
[Problem Link](https://leetcode.com/problems/ones-and-zeroes/description/)

## Problem desciption 
You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

### Example 1:

>**Input:** strs = ["10","0001","111001","1","0"], m = 5, n = 3<br>
>**Output:** 4<br>
>**Explanation:** The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.<br>
>Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.<br>
>{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.<br>

## constraints
* 1 <= strs.length <= 600
* 1 <= strs[i].length <= 100
* strs[i] consists only of digits '0' and '1'.
* 1 <= m, n <= 100

## Code 
Memoization code 
```cpp
class Solution {
public:
    int solve(int ind,int m,int n,vector<string>&strs,vector<vector<vector<int>>> &dp){ //N
        int size = strs.size();
        if(ind == size || m < 0 || n < 0) return 0;
        if(dp[ind][m][n]!=-1) return dp[ind][m][n];
        int pick = INT_MIN,notPick = INT_MIN;
        int numZeros = 0,numOnes = 0;
        for(int i = 0;i<strs[ind].size();i++){ //m*n
            if(strs[ind][i]=='1') numOnes++;
            if(strs[ind][i]=='0') numZeros++;
        }

        if(numZeros <= m && numOnes <= n){
            pick = 1 +  solve(ind+1,m-numZeros,n-numOnes,strs,dp);
        }
            notPick =  solve(ind+1,m,n,strs,dp);
        
        return dp[ind][m][n] = max(notPick,pick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> dp(size+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,m,n,strs,dp);
    }
};

```

## Intuition


## Approach


## Complexity
- Time complexity:  O(N*m*n)

- Space complexity:
