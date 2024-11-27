# Shortest Distance After Road Addition Queries I
[Problem Link](https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/)

## Problem desciption 
You are given an integer n and a 2D integer array queries.

There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.

queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of the shortest path from city 0 to city n - 1.

Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.

 
### Example 1:

> **Input:** n = 5, queries = [[2,4],[0,2],[0,4]]
> **Output:** [3,2,1]

## constraints
* 3 <= n <= 500
* 1 <= queries.length <= 500
* queries[i].length == 2
* 0 <= queries[i][0] < queries[i][1] < n
* 1 < queries[i][1] - queries[i][0]
* There are no repeated roads among the queries.


## Code
```cpp
class Solution {
public:
    int djikstra(int src,int dest,unordered_map<int,vector<int>> &adj){
        
        vector<int> dist(dest,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        dist[0] = 0;

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto child:adj[node]){
                if(dist[child] < 1 + dist[node]){
                    pq.push({dis+1,child});
                    dist[child] = 1 + dist[node];
                }

                if(child == dest-1){
                    return dis + 1;
                }
            }
        }
        return dest-1;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        for(int i = 0;i<n-1;i++){
            adj[i].push_back(i+1);
        }

        vector<int> vec;
        for(auto it: queries){
            adj[it[0]].push_back(it[1]);
            vec.push_back(djikstra(0,n,adj));
        }
        return vec;
    }
};
```

## Intuition
Its an application on the djikstra question where we need to calculate the shortest distance. 

## Approach


## Complexity 
- Time complexity: O(nlogv e)


- Space complexity: O(e)
