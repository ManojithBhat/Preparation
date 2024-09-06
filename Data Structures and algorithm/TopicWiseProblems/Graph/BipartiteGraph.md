# Bipartitie Graph

[problem link](https://www.geeksforgeeks.org/problems/bipartite-graph/1)

## Problem desciption
Given an adjacency list of a graph adj of V no. of vertices having 0 based index. Check whether the graph is bipartite or not 

## constraints
* 1 ≤ V, E ≤ 10<sup>5


## Code

Using BFS
```cpp

class Solution {
public:
    //using bfs 
    bool bfs(int start,vector<int>adj[],int color[]){
        
        //mark the starting node as 0 first for color 
        color[start] = 0;
        //define a queue and put this starting node
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]){
                if(color[it]==-1){
                    //still not colored so mark with the color 
                    color[it] = !color[node];
                    q.push(it);
                }
                if(color[it]==color[node]){
                    //someone else would have a marked this color in the loop 
                    //and the same as color of the present so it is not biapritie graph
                    return false;
                }
            }
        }
        return true;
        
    }

	bool isBipartite(int V, vector<int>adj[]){
	    //if things fail and have a large test case then there could be multiple components 
	    int color[V];
	    for(int i=0;i<V;i++) color[i]=-1; //initialise all to -1 -- that is not coloured iniitally
	    
	   for(int i=0;i<V;i++){
	       if(color[i]==-1){
	           if(bfs(i,adj,color)==false)
	               return false;
	       }
	   }
	   
	    return true;
	}

};

```

Uisng DFS

```cpp

class Solution {
public:

    bool dfs(int node,int col,vector<int>adj[],int color[]){

        color[node] = col;
        for(auto it: adj[node]){
             if(color[it]==-1){
                    //still not colored so mark with the color
                   if(dfs(it,!col,adj,color)==false)
                        return false;
                }
                if(color[it]==color[node]){
                    //someone else would have a marked this color in the loop 
                    //and the same as color of the present so it is not biapritie graph
                    return false;
                }
            }
        
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    //if things fail and have a large test case then there could be multiple components 
	    int color[V];
	    for(int i=0;i<V;i++) color[i]=-1; //initialise all to -1 -- that is not coloured iniitally
	   
	   for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(dfs(i,0,adj,color)==false)
	                return false;
	        }
	    }
	    return true;
	}

};

```

## Intuition
The bipartite porblem is coloring the graph such that no adjacent nodes are coloured with the same color. <br>
The problem requires us to find whether the given graph is a bipartite or not. <br>
The intution is to keep an array called col which is initialised to -1, and there are 2 colors that is 0 and 1.
<br>
We can either perform a DFS or BFS traversal such that we mark the current nodes color as passed by the prev node, if the col[node] is marked zero then it is un-colored and we colour it, if it is already marked and the color is same as the current node, then we cannot form a bipartite graph.
> Here the color array act as visited array so no need to initialise separetly.


## Approach
* Plain BFS / DFS
* Initialise the color array.
* check for bipartite graph. 

## Complexity
- Time complexity: O(V + 2E) - similar to dfs or bfs 


- Space complexity: O(V) - we are using color array.
