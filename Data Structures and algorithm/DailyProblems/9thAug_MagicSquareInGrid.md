# Magic Square in grid

## Problem desciption 
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
<br>
Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?
<br>
Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

## constraints
* row == grid.length
* col == grid[i].length
* 1 <= row, col <= 10
* 0 <= grid[i][j] <= 15

## Code
```cpp

class Solution {
public:
    bool isGrid(int r, int c, vector<vector<int>>& grid) {
        unordered_set<int> st;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[i + r][j + c];
                if (num < 1 || num > 9 || st.count(num))
                    return false;
                else
                    st.insert(num);
            }
        }

        int sum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];

        for (int i = 0; i < 3; i++) {

            if (grid[r + i][c ] + grid[r + i][c + 1] + grid[r + i][c + 2] !=
                sum)
                return false;
            if (grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != sum)
                return false;
        }

        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != sum)
            return false;
        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != sum)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (isGrid(i, j, grid))
                    cnt++;
            }
        }
        return cnt;
    }
};

```

## Intuition
In this particular question the brute force is itself the optimal one
<br>
we are supposed to check all the 3*3 matrix and check for the specified condition

## Complexity
- Time complexity: O(n*m) ( we are using O(1) time in calculation)


- Space complexity: O(1)
