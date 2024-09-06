# Minimum Number of Days to Disconnect Island
[Problem Link](https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/?envType=daily-question&envId=2024-08-11)

## Problem desciption 
You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.

The grid is said to be connected if we have exactly one island, otherwise is said disconnected.

In one day, we are allowed to change any single land cell (1) into a water cell (0).

Return the minimum number of days to disconnect the grid.

### Example 1

> **Input:** grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]<br>
> **Output:** 2<br>
> **Explanation:** We need at least 2 days to get a disconnected > grid.
> Change land grid[1][1] and grid[0][2] to water and get 2 > disconnected island.

## constraints
* m == grid.length
* n == grid[i].length
* 1 <= m, n <= 30
* grid[i][j] is either 0 or 1.

## Code
```cpp
class Solution {
public:
     void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
        vis[i][j] = 1;
        
        int row[4] = {0,1,-1,0};
        int col[4] = {1,0,0,-1};

        int n = grid.size();
        int m = grid[0].size();

        for(int k=0;k<4;k++){
            int nrow = row[k]+i;
            int ncol = col[k]+j;

            if(nrow>=0 && nrow<n && ncol<m && ncol>=0 && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(nrow,ncol,grid,vis);
            }
        }
    }

    int numIslands(vector<vector<int>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    islands++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = numIslands(grid);
        if(islands > 1 || islands == 0) return 0;

        //if there exist one island then we need to check if by adding 1 or 2 ( this is the maximum it can go) 
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    int island = numIslands(grid);
                    if(island>1 || island == 0) return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};

```

## Intuition
The important observation here no matter what number of days cannot excede 2. Either it could be 0, 1, 2. <br>
* Hence, if the # of island is 0 or greater than 1 then we return 0
* If the above condition did not work then we do a brute force by changing every 1 marked cell to 0 and then reverting back
* If this did not happen then the answer would be 2 for sure. 


## Approach
Similar to Number of islands.

## Complexity
- Time complexity: O((m*n)2) - Number of island takes O(m*n) and iterating through all of them making one of the grid element takes (m*n)


- Space complexity: O(1) 
