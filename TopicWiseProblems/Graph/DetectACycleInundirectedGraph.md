# Detect A cycle in a undirected Graph 

## Problem desciption 

Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

### Example 1
> **Input:**  V = 5, E = 5
> <br>
> adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}}
><br> 
> **Output:** 1
> <br>
> **Explanation:** 1->2->3->4->1 is a cycle.

## constraints
* 1 ≤ V, E ≤ 105

## Code
```cpp

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool check(int node,int parent,vector<int> adj[],vector<int> &vis){
        vis[node] = 1;
        
        for(auto child : adj[node]){
            if(!vis[child]){
                if(check(child,node,adj,vis)==true) return true;
            }else if(child!=parent) return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(check(i,-1,adj,vis)==true) return true;
            }
        }
        return false;
    }
};

```

## Intuition
Whenever there is a cycle in an undirected graph then adjacent node will be marked visited but ensuring that that particular node is not a parent node.
<br>
We perform usual DFS or BFS traversal, but we keep track of **parent** node, if the particulare node is not marked visited then we call the dfs or put the node into the queue by adding the parent node, if it is visited and it is not a parent node then we return false.
<br>
It is important to node that whenever we are calling the dfs call we do in a if statement, so that when one of the call returns true, all the previous call returns true and the function return, if not we have false condtion mentioned.

<br>

In order to perform this in bfs everything remains the same except that we need to now keep a queue that has a pair with both child and the parent 
```cpp
 queue<pair<int,int>>  q;
 //{node,parent}

```
and when we pop out a node, we check for the above conditions not visited  - put that into the queue.
<br>
Visited and it is not a parent - return false.

## Approach
Follow the intution.

## Complexity
- Time complexity: O(V+E)


- Space complexity: O(V)
 