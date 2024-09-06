# Surrounded Regions
[Problem Link](https://leetcode.com/problems/surrounded-regions/description/)

## Problem desciption 

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.


### Example 1:

>**Input:** board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]<br>
>**Output:** [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]<br>


## constraints
* m == board.length
* n == board[i].length
* 1 <= m, n <= 200
* board[i][j] is 'X' or 'O'.

## Code
```cpp
class Solution {
public:
    void dfs(int r,int c,vector<vector<char>> &board,vector<vector<int>> &vis){
        int n = board.size();
        int m = board[0].size();
        vis[r][c] = 1;

        int row[4]= {0,1,-1,0};
        int col[4] = {-1,0,0,1};

        for(int i = 0; i<4;i++){
            int nrow = r + row[i];
            int ncol = c + col[i];

            if(nrow >=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow,ncol,board,vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i = 0;i<n;i++){
            if(board[i][0] == 'O' && !vis[i][0] ) dfs(i,0,board,vis);
            if(board[i][m-1]=='O' && !vis[i][m-1]) dfs(i,m-1,board,vis);
        }

        for(int j = 1;j<m-1;j++){
            if(board[0][j] == 'O' && !vis[0][j] ) dfs(0,j,board,vis);
            if(board[n - 1][j]=='O' && !vis[n - 1][j]) dfs(n-1,j,board,vis);
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};

```

## Intuition
We have to use the concpet of ```boundary traversal``` . This is similar to the connected islands, as we need to mark all those *O* surrounded by *X*, we take a different approach. by boundary traversal we mark all those *O*s which are on the boundary and not surrounded by the *X* leaving *O* inside the *X* untouched, later by marking those *o* that are not visited to *X* we can solve the problem

## Approach
*DFS* technique with boundary traversal 

## Complexity
- Time complexity: O(N*M)


- Space complexity: o(N*M)
