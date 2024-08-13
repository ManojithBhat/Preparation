# Longest Common Subsequence 

[Problem Link]()

## Problem desciption 
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

## constraints
1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.

## Code
```cpp

class Solution {
public:
    int solve(int i,int j,string text1,string text2,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]){
            return dp[i][j] = 1+ solve(i-1,j-1,text1,text2,dp);
        }
        return dp[i][j] = 0+max(solve(i,j-1,text1,text2,dp),solve(i-1,j,text1,text2,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,text1,text2,dp);
    }
};

```

## Intuition


## Approach


## Complexity
- Time complexity: O(max(M,N))


- Space complexity:
