

/*

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

*/

//by bfs 
class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row,
             int col) {
        // mark the current node
        vis[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty()) {
            int nrow = q.front().first;
            int ncol = q.front().second;
            q.pop();
            // check if the adjacent nodes are island or water and traverse it
            int arrr[4] = {0, 1, 0, -1};
            int arrc[4] = {1, 0, -1, 0};
            int n = grid.size();
            int m = grid[0].size();

            for (int i = 0; i < 4; i++) {
                int r = nrow + arrr[i];
                int c = ncol + arrc[i];

                if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] &&
                    grid[r][c] == '1') {
                    vis[r][c] = 1;
                    q.push({r, c});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0)); // visited array
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++; // increase the count as it is a poss island
                    // if the node is visited prev and it is a island, call bfs
                    bfs(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
};

//by dfs 

class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis){
        vis[i][j] = 1;
        
        int row[4] = {0,1,-1,0};
        int col[4] = {1,0,0,-1};

        int n = grid.size();
        int m = grid[0].size();

        for(int k=0;k<4;k++){
            int nrow = row[k]+i;
            int ncol = col[k]+j;

            if(nrow>=0 && nrow<n && ncol<m && ncol>=0 && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                dfs(nrow,ncol,grid,vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    islands++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return islands;
    }
};


/*

Intution : The idea behind the problem is we have to find the number of islands that is the ones that are surrounded by the water. the approach would be to travel through the all the 1's that are surrounded by the 0, we can either use the DFS Or BFS technique to do this
like the connected graph property we traverse through the matrix and go for either dfs or bfs only when we encounter the 1 and it is not visited.( this is important and this is where i missed the case ), can perform the dfs or bfs and mark the visited nodes and then increment the count of the islands.

*/