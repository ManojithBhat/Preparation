# Maximum Number of Moves in a Grid
[Problem Link](https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/?envType=daily-question&envId=2024-10-29)

## Problem desciption 
You are given a 0-indexed m x n matrix grid consisting of positive integers.

You can start at any cell in the first column of the matrix, and traverse the grid in the following way:

From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
Return the maximum number of moves that you can perform.

Example 1:


Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]<br>
Output: 3<br>
Explanation: We can start at the cell (0, 0) and make the following moves:<br>
- (0, 0) -> (0, 1).<br>
- (0, 1) -> (1, 2).<br>
- (1, 2) -> (2, 3).<br>
It can be shown that it is the maximum number of moves that can be made.<br>

## constraints
* m == grid.length
* n == grid[i].length
* 2 <= m, n <= 1000
* 4 <= m * n <= 105
* 1 <= grid[i][j] <= 106

## Code
```cpp
class Solution {
public:
 
    int n ;
    int m ;
    int solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if( j == m-1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int r = 0,c = 0,l=0;
        if(i-1 >=0 && grid[i-1][j+1] > grid[i][j]){
            l = 1 + solve(i-1,j+1,grid,dp);
        }
        if(grid[i][j+1] > grid[i][j]){
            c = 1 + solve(i,j+1,grid,dp);
        }
        if(i+1 < n && grid[i+1][j+1] > grid[i][j]){
            r = 1 + solve(i+1,j+1,grid,dp);
        }

        return dp[i][j] = max(r,max(l,c));
    }

    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxMove = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i = 0;i<n;i++){
            maxMove = max(maxMove,solve(i,0,grid,dp));
        }
        return maxMove;
    }
};
```

## Intuition
A Simple grid based question with one condition and traversal from left to right

## Complexity
- Time complexity: O(m*n)


- Space complexity: O(m*n)
