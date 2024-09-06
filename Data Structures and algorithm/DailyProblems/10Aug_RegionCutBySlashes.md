# Region cut by slashes

[problem link](https://leetcode.com/problems/regions-cut-by-slashes/description/)

## Problem desciption 
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.


## constraints
* n == grid.length == grid[i].length
* 1 <= n <= 30
* grid[i][j] is either '/', '\', or ' '.

## Code
```cpp

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {
        vis[i][j] = 1;

        int row[4] = {0, 1, -1, 0};
        int col[4] = {1, 0, 0, -1};

        int n = grid.size();
        int m = grid[0].size();

        for (int k = 0; k < 4; k++) {
            int nrow = row[k] + i;
            int ncol = col[k] + j;

            if (nrow >= 0 && nrow < n && ncol < m && ncol >= 0 &&
                grid[nrow][ncol] == 0 && grid[nrow][ncol]!=1 && !vis[nrow][ncol]) {
                dfs(nrow, ncol, grid, vis);
            }
        }
    }

    int regionsBySlashes(vector<string>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int regions = 0;

        vector<vector<int>> matrix(3 * n, vector<int>(3 * m, 0));

         for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '/') {
                    matrix[i*3][j*3 + 2] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3] = 1;
                } else if(grid[i][j] == '\\') {
                    matrix[i*3][j*3] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3+2] = 1;
                }
            }
        }


        //apply the concept of number of islands 
        vector<vector<int>> vis(3*n,vector<int>(3*m,0));
        for (int i = 0; i < 3*n; i++) {
            for (int j = 0; j < 3*m; j++) {
                if (matrix[i][j] == 0 && !vis[i][j]) {
                    regions++;
                    dfs(i,j,matrix,vis);
                }
            }
        }
        return regions;
    }
};

```

## Intuition

The observation here is we convert every character to a 3*3 matrix such that 

> / represents <br>
> 0 0 1 <br> 
> 0 1 0 <br>
> 1 0 0
> 

> and \ ie \\\ represents <br>
> 1 0 0 <br> 
> 0 1 0 <br>
> 0 0 1

The problem is converted to question of connected island and by counting the number of regions with '0' we can calculate the number of regions.

## Complexity
- Time complexity: O(3n*3m) - O(n*m)


- Space complexity: O(3n*3m) - O(n*m)
