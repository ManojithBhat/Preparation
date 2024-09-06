# Bredth Frist Search
[Problem Link]()

## Problem desciption 

Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

### Example 1
> **Input :** V = 5, E = 4<br>
> adj = {{1,2,3},{},{4},{},{}}<br>
> **Output**: <br>
> 0 1 2 3 4<br>
> **Explanation**: <br>
> 0 is connected to 1 , 2 , 3.<br>
> 2 is connected to 4.<br>
> so starting from 0, it will go to 1 then 2<br>
> then 3. After this 2 to 4, thus bfs will be<br>
> 0 1 2 3 4.<br>



## Code
```cpp
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        // 0 based indexing 
        //create a visited array now 
        int vis[V]={0};
        
        //visted the first node; 
        vis[0]=1;
        //creating a vector to return the answer 
        vector<int> bfs;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto it: adj[node]){
                //mark the visit
                if(!vis[it]){
                     vis[it]=1;
                    q.push(it);
                }
            }
            
        }
        return bfs;
        
    }
};
```

## Intuition
 In this problem we are given a directed graph and we need to find the bfs traversal of the graph starting from the 0th node.<br>
        so the first thing that comes to mind is to use the queue to store the nodes and then traverse the nodes and mark the visited nodes.
        so by this method we can find the bfs traversal of the graph.
        Application of bfs is to find the shortest path in the graph, any application that involves level by level traversal 

## Approach


## Complexity
- Time complexity: O(v+E)

- Space complexity: O(V)
