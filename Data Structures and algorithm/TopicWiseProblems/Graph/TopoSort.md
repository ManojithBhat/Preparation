# Topological sorting - kahn's algoritm 

[Topo sort](https://www.geeksforgeeks.org/problems/topological-sort/1)

## Problem desciption 

Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j such that there is a directed edge from vertex i to vertex j, with  V  vertices and E  edges, your task is to find any valid topological sorting of the graph.
<br>
In a topological sort, for every directed edge u -> v,  u must come before v in the ordering.


> _A special note_ : ( give an example of 3 node graph)
<br>
> This can be possible only for DAG ( Directed acyclic graph) because in an undirected graph we can’t decide which node will come first > > because there will be no direction, and if there is a cycle topological order will not be possible 

## constraints
* 2 ≤ V ≤ 104
* 1 ≤ E ≤ (N*(N-1))/2

## Code

__Kahn's Algoritm - indegree array__

```cpp
class Solution
{
	public:
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{  
	   int indegree[V]={0}; // it will store the numner of incomig edges 
	   
	   for(int i=0;i<V;i++){
	       for(auto it: adj[i])
	            indegree[it]++;
	   }
	   
	   //put all those element into the queue which has 0 indegree
	   queue<int> q;
	   for(int i=0;i<V;i++){
	       if(indegree[i]==0)
	            q.push(i);
	   }
	   
	   //untill the queue gets empty run the while loop
	   // put the front element into the vector reduce the indegree indexing by 1 and if at any point 
	   //indegree becames 0 push into the queue
	   
	   vector<int> ans;
	   while(!q.empty()){
	       int node = q.front();
	       q.pop();
	       ans.push_back(node);
	       
	       for(auto it: adj[node]){
	           indegree[it]--;
	           if(indegree[it]==0)
	                q.push(it);
	       }
	   }
	   return ans;
	}
};

```

__By using stack__
```cpp

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	//linear ordering of vertices such that if there is an edge between u and v
	//u appears before v in that ordering 
	void dfs(int node,vector<int> adj[],int vis[],stack<int> &st){
	    
	    vis[node]=1;
	    
	    for(auto it: adj[node]){
	        if(!vis[it]){
	            dfs(it,adj,vis,st);
	        }
	    }
	    
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    using dfs algo combined with stack
	   int vis[V]={0};
	   stack<int> st;
	   vector<int> ans;
	   for(int i=0;i<V;i++){
	       if(!vis[i])
	           dfs(i,adj,vis,st);
	   }
	    
	   while(!st.empty()){
	        ans.push_back(st.top());
	       st.pop();
	   }
	   return ans;
    } 

};

```

## Intuition
__kahn's algorithm__ 
This method involves using a indegree array to store the indegree of an edge, whenever the indegree of a node becames zero we put those into the queue and perform the usual BFS by storing them in the answer vector _we aren't using any visited array for this method_.
<br>
This method works because indegree specifies the node heirarchy. 

__stack method__
This method is similar to the DFS, but we store the nodes whenever the function call returns, by popping the element out of the stack, we achieve topological ordering.


## Complexity
- Time complexity: O(V+E) similar to the dfs and bfs


- Space complexity: O(V) we are using stack or the indegree array 
