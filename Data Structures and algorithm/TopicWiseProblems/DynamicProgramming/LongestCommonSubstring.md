# Longest Common Substring
[Problem Link](https://www.geeksforgeeks.org/problems/longest-common-substring1452/1)

## Problem desciption 
You are given two strings str1 and str2. Your task is to find the length of the longest common substring among the given strings.

### Example 1
> **Input:** str1 = "ABCDGH", str2 = "ACDGHR"<br>
> **Output:** 4<br>
> **Explanation:** The longest common substring is "CDGH" which has length 4.
> 

## constraints
* 1<= str1.size(), str2.size()<=1000
* Both strings may contain upper and lower case alphabets.

## Code
```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int j=0;j<=m;j++) dp[0][j] = 0;
        int ans = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1]; // Characters match, increment substring length
                ans = max(ans, val); // Update the maximum substring length found so far
            }
               else dp[i][j] = 0;
            }
        }
        return ans;
    }
};

```

## Intuition
The intution is similar to the Longest increasing subsequence but in the case of substring we need to make sure that the string is continous.

But how do we make sure this ? 
The key idea is to use the tabulation code of the LCS along with the concept of shifted indices to achieve this.

> Special Note : 
> Tabulation code for string questions are important. Make sure to revise again and again.<br>
> Memoisation code is top down apporach and tabular code is bottom up ( hence base cases need to be defined mostly at the intial columns and initial row ).<br>
> If the base cases are zero then no need to initialise, if it isnt then we need to add separately ( make sure of overalapping intervals, for example if you have rows initialised to 1 and columns to 0 then it is better that we initialise the columns to zero and rows later ( as 1 is overwrittn for intersection of rows and columns )).
> <br>

If the character are same (note i-1 and j-1 index), then we increament from the prevRow,prevCol value and take max of these values, if at any point the character are different then we break as we need substring and again go back to zero.


## Complexity
- Time complexity: O(n*m)


- Space complexity: O(n*m)
