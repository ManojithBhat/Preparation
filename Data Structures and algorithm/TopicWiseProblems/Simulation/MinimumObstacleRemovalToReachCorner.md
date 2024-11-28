# Minimum Obstacle Removal to Reach Corner
[Problem Link](https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/?envType=daily-question&envId=2024-11-28)

## Problem desciption 
You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:

0 represents an empty cell,
1 represents an obstacle that may be removed.
You can move up, down, left, or right from and to an empty cell.

Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).

**Example 1:**

**Input:** grid = [[0,1,1],[1,1,0],[1,1,0]]<br>
**Output:** 2<br>
**Explanation:** We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2).<br>
It can be shown that we need to remove at least 2 obstacles, so we return 2.<br>
Note that there may be other ways to remove 2 obstacles to create a path.<br>


## constraints

* m == grid.length
* n == grid[i].length
* 1 <= m, n <= 105
* 2 <= m * n <= 105
* grid[i][j] is either 0 or 1.
* grid[0][0] == grid[m - 1][n - 1] == 0

## Code
```cpp
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[0][0] = 1;
        pq.push({0,{0,0}});
        int obs = 0;

        while(!pq.empty()){
            int nodex = pq.top().second.first;
            int nodey = pq.top().second.second;
            int currObs = pq.top().first;
            pq.pop();

            int row[4] = {0,1,0,-1};
            int col[4] = {1,0,-1,0};

            if(nodex == n-1 && nodey == m - 1) return currObs;

            for(int i = 0;i<4;i++){
                int dirx = nodex + row[i];
                int diry = nodey + col[i];    

                if(dirx >= 0 && dirx < n && diry < m && diry >=0 && vis[dirx][diry]==0 ){
                    vis[dirx][diry] =1;
                    pq.push({grid[dirx][diry]+currObs,{dirx,diry}});
                }

            }
        }
        return -1;
    }
};
```

## Intuition
Its dijkstra which keeps track of the min of the obstacles/

## Approach


## Complexity
- Time complexity:


- Space complexity:
