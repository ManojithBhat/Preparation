# Pre requsite Tasks 

## Problem desciption

There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

### Example 1:

> **Input:** 
> N = 4, P = 3 <br>
> prerequisites = {{1,0},{2,1},{3,2}} <br>
> **Output:** Yes <br>
> **Explanation:** <br>
> To do task 1 you should have completed
> task 0, and to do task 2 you should 
> have finished task 1, and to do task 3 you 
> should have finished task 2. So it is possible.

## constraints
* 1 ≤ N ≤ 10<sup>4
* 1 ≤ P ≤ 10<sup>5

## Code
```cpp

class Solution {
public:
	bool isPossible(int V,int P, vector<pair<int, int> >& prerequisites) {
	    
	    vector<int> adj[V];
	    //now make a connections 
	    for(auto it:prerequisites){
	        adj[it.second].push_back(it.first);
	    }
	    
	    //now we have our adjecency list ready and now all the thing we need to do is to check for cylce
	    //we can use both dfs as well as bfs(topo sort method)
	   
	    int indegree[V]={0};
        
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        //put all of them into the queue which has zero dependenciy
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        //traverse through the queue untill it's empty
        //consequently we can store in the vector and check the size 
        //the reason why this works is because of concept of dependencies 
        //if at some time dependencies does not became zero - the reason is it is a part of cycle 
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            cnt++;
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        if(cnt==V) return true;
        return false;
	}
};

```

## Intuition
This is the BFS method of finding whether the directed graph is cyclic or not ( by _KAHN'S METHOD_). <br>
If we ever to find the toposort of the given graph, that has to acyclic, exploiting this fact here.<br>
If there exist a cycle, then we cannot have a _n_ verticies in the toposort order, hence if we have less than _n_ verticies in the toposort then we infer that there exist a cycle and hence we cannot have a course sheduld. 

## Approach
Similar to Kahn's algorithm but we keep a node count and compare with the total node count.


## Complexity
- Time complexity: O(V+E) - similar to BFS


- Space complexity: O(V) - as we are using the indegree array to store the nodes 
