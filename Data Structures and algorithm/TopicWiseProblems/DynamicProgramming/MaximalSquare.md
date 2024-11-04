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

memoisation
```cpp
class Solution {
public:
    int n,m;
    int solve(int i,int j,vector<vector<char>> &matrix,vector<vector<int>> &dp){
        if( i >= n or j >= m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(matrix[i][j] == '0') return 0;

        int right = solve(i+1,j,matrix,dp);
        int down = solve(i,j+1,matrix,dp);
        int diag = solve(i+1,j+1,matrix,dp);

        return dp[i][j] =  1 + min(right,min(diag,down));
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        int maxSide = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));

        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                maxSide = max(maxSide,solve(i,j,matrix,dp));
            }
        }
        return maxSide*maxSide;
    }
};
```

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
