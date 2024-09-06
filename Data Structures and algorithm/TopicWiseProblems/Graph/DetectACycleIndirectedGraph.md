# Detect a cycle in a directed graph

## Problem desciption 
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

## constraints
* 1 ≤ V, E ≤ 10<sup>5</sup>

## Code
```cpp
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<int> adj[],int vis[],int pathVis[]){
        
        vis[node]=1;
        pathVis[node] =1;
        
        //traverse for adjanceny nodes 
        for(auto it: adj[node]){
            if(!vis[it]){
                //this is when the node is not visited once 
                if(dfs(it,adj,vis,pathVis)==true)
                    return true;
            }
            else if(pathVis[it]){
                    //if the node has been previously visited
                    //and and it is also been visited in the same path hence there exist a cycle so returnture
                    return true;
                }
            
        }
        pathVis[node]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        
        int vis[V] = {0};
        int pathVis[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis)==true)
                    return true;
            }
        }
        return false;
        
    }
};

```

## Intuition
In the intution of the problem is similar to the detecting a cycle in a undirected graph, but instead of keeping a parent and child relationship ( which wont be as suitable because we wont be going back to the same parent most of time as it is directed graph, yet loop may exist ( think of graph with 2 nodes and a loop bw them)).
<br>
But we keep another array called as pathVisited array, we say that there exist a cycle only when a particular child node is pathvisited as well as visited, if not then there isnt any cycle.


## Approach
Implementation is through the dfs algorithm, similar to the undirected graph.
<br>
Check the problem for undirected graph here [Detect a cycle in undirected graph](DetectACycleInundirectedGraph.md)

## Complexity
- Time complexity:


- Space complexity:
