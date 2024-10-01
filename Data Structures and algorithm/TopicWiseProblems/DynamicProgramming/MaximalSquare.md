# Maximal Square
[Problem Link](https://leetcode.com/problems/maximal-square/)

## Problem desciption 
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

### Example 1
**Input:** matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]<br>
**Output:** 4<br>

## constraints
* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 300
* matrix[i][j] is '0' or '1'.

## Code
```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxSide = 0;
        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
               if(matrix[i][j] == '1'){
                  if(i==0 || j==0 ){
                    dp[i][j] = 1;
                  }else{
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                  }
                  maxSide = max(maxSide,dp[i][j]);
               }
            }
        }
        return maxSide*maxSide;
    }
};
```

## Intuition
It is a dynamic programming approach where we check for the maximum side we can get till nums[i][j] by checking  the 3 boxes before 


## Complexity
- Time complexity: O(N*M)


- Space complexity: O(N*M)
