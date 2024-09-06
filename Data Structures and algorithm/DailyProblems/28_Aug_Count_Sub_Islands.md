# Count Sub Islands
[Problem Link]()

## Problem desciption 
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands

### Example 1

> **Input:** grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]<br>
**Output:** 3<br>
**Explanation:** In the picture above, the grid on the left is grid1 and the grid on the right is grid2.<br>
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.<br>


## constraints
* m == grid1.length == grid2.length
* n == grid1[i].length == grid2[i].length
* 1 <= m, n <= 500
* grid1[i][j] and grid2[i][j] are either 0 or 1.

## Code
```cpp
class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>> &vis,bool &flag){
        vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();

        int row[4] = {0,1,-1,0};
        int col[4] = {-1,0,0,1};

        for(int i = 0;i<4;i++){
            int nrow = row[i] + r;
            int ncol = col[i] + c;

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol]){
                if(grid[nrow][ncol] == 1) flag = true;
                if(grid[nrow][ncol] == 1 || grid[nrow][ncol] == 2){
                    dfs(nrow,ncol,grid,vis,flag);
                }
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int n = grid1.size();
        int m = grid1[0].size();

        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++){
                if(grid1[i][j] == 1 && grid2[i][j]==1) grid2[i][j] = 2;
            }

        int count = 0;

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid2[i][j] == 2 && !vis[i][j]){
                    bool flag = false;
                    dfs(i,j,grid2,vis,flag);
                    if(flag) continue;
                    count++;
                }
            }
        }
        return count;
    }
};

```

## Intuition
The problem involves finding subisland, so when can something be subisland, when both have 1's in common, so we mark all those island whcih is common, then we perform DFS to find the number of islands marked with 2's that are not connected with 1's.

## Approach
Keep a flag which is marked true only when there is 1 adjacent to any 2 present in the matrix. This condition is specified in the problem. if the flag is set we just continue to search for another subisland or else we increment the counter.

## Complexity
- Time complexity: O(n*m)


- Space complexity: O(n*m)
