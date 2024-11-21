# Count unguarded Cells in the grid
[Problem Link](https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/)

## Problem desciption 
You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.

Return the number of unoccupied cells that are not guarded.

### Example 1
> **Input:** m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]<br>
> **Output:** 7<br>
> **Explanation:** The guarded and unguarded cells are shown in red and green respectively in the above diagram.<br>
> There are a total of 7 unguarded cells, so we return 7.<br>


## constraints
* 1 <= m, n <= 105
* 2 <= m * n <= 105
* 1 <= guards.length, walls.length <= 5 * 104
* 2 <= guards.length + walls.length <= m * n
* guards[i].length == walls[j].length == 2
* 0 <= rowi, rowj < m
* 0 <= coli, colj < n
* All the positions in guards and walls are unique.

## Code
```cpp
class Solution {

public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards,vector<vector<int>>& walls) {

        vector<vector<int>> grid(n, vector<int>(m, 0));
        int cnt = 0;

        for (auto it : guards) {
            grid[it[0]][it[1]] = 1; // guard mark it as 1
            cnt++;
        }

        for (auto it : walls) {
            grid[it[0]][it[1]] = 2; // wall mark it as 2
            cnt++;
        }

        for (int k = 0; k < guards.size(); k++) {
            // it is a guard
            // check for above cells
            int i = guards[k][0];
            int j = guards[k][1];
            int row = i - 1, col = j;
            while (row >= 0 && grid[row][col] != 2 && grid[row][col] != 1) {
                if (grid[row][col] != 3)
                    cnt++;
                grid[row][col] = 3;
                row--;
            }
            row = i + 1;
            col = j;
            while (row < n && grid[row][col] != 2 && grid[row][col] != 1) {
                if (grid[row][col] != 3)
                    cnt++;
                grid[row][col] = 3;
                row++;
            }
            row = i;
            col = j - 1;
            while (col >= 0 && grid[row][col] != 2 && grid[row][col] != 1) {
                if (grid[row][col] != 3)
                    cnt++;
                grid[row][col] = 3;
                col--;
            }
            col = j + 1;
            row = i;
            while (col < m && grid[row][col] != 2 && grid[row][col] != 1) {
                if (grid[row][col] != 3)
                    cnt++;
                grid[row][col] = 3;
                col++;
            }
        }
        return n * m - cnt;
    }
};

```

## Intuition
Normal simulation problem

## Approach


## Complexity
- Time complexity: O(n*N*M) where n is the number of guards in the cell


- Space complexity:O(N*M)
