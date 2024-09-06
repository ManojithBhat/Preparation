# Minimum spanning tree by prims algorithm
[Problem Link](https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1)

## Problem desciption 
Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge


## constraints
* 2 ≤ V ≤ 1000
* V-1 ≤ E ≤ (V*(V-1))/2
* 1 ≤ w ≤ 1000
* The graph is connected and doesn't contain self-loops & multiple edges.

## Code
```cpp
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
      priority_queue<pair<int, int>,
		               vector<pair<int, int> >, greater<pair<int, int>>> pq;
	pq.push({0, 0});

       vector<int>vis(V,0);
       int sum = 0;
       
       while(!pq.empty()){
           auto it = pq.top();
           int wt = pq.first;
           int node = pq.second;
           pq.pop();
           
           if(!vis[node]) continue;
           vis[node] = 1;
           sum+=wt;
           
           for(auto child:adj[node]){
               int w = child[0];
               int n = child[1];
               
               if(!vis[n])
                pq.push({w,n});
           }
           
       }
       return sum;
        
    }
};


```

## Intuition



## Approach


## Complexity
- Time complexity:


- Space complexity:
