# Rotten Oranges
[Problem Link](https://www.geeksforgeeks.org/problems/rotten-oranges2536/1)

## Problem desciption 
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 


## constraints
* 1 ≤ n, m ≤ 500

## Code
```cpp
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int cntFresh=0;
        
        //{{r,c},t}    
        queue<pair<pair<int,int>,int>> q;
        //creating a visitied array 
        int vis[n][m];
        
        //push all of them into the queue which are rottened and mark 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }else{
                    vis[i][j]=0;
                }
                
                if(grid[i][j]==1) cntFresh++;
            }
        }
        
        int tm = 0; //to update when time is max 
        int t=0;
        int cnt = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm,t);
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    cnt++;
                }
            }
        }
        if(cnt!=cntFresh) return -1;
        return tm;  
    }
};

```

## Intuition



## Approach


## Complexity
- Time complexity:


- Space complexity:
