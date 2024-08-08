
/*

You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use the recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.

Input: V = 5 , adj = [[2,3,1] , [0], [0,4], [0], [2]]
Output: 0 2 4 3 1
Explanation: 
0 is connected to 2, 3, 1.
1 is connected to 0.
2 is connected to 0 and 4.
3 is connected to 0.
4 is connected to 2.
so starting from 0, it will go to 2 then 4,
and then 3 and 1.
Thus dfs will be 0 2 4 3 1.

*/

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int node,vector<int> adj[],int vis[],vector<int> &ls){
        //mark the node 
        vis[node] = 1;
        //put into the list 
        ls.push_back(node);
        //traverse all its neighbours
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,ls);
            }
        }
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        int vis[V]={0};
        //list which stores visited and all are marked 0 at the start 
        //here start is 0 it can be anything from any node
        int start = 0;
        vector<int> ls; //to store the answer
        
        //rec algo
        dfs(start,adj,vis,ls);
        return ls;
    }
};

/*
  if it was connected graph then we have to traverse all the nodes and check if it is visited or not. if not visited then we have to call the dfs function.
  ie. in the main function 
   for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,adj,vis,ls);
            }
        }
 */

/*
  Depth search traversal is a recursive algorithm, ie is we have to traverse all the nodes and then check if it is visited or not. if not visited then we have to call the dfs function. It is one of the traversal algorithm used which finds the application in man problems like 
    1. finding the connected components
    2. finding the cycle in the graph
    3. finding the topological sort
    
    Time Complexity : O(V+E) as we are traversing all the nodes and all the edges.
    if the input is given in the form of adjacency matrix then the time complexity will be O(V^2) as we have to traverse all the nodes and all the edges.

    Space Complexity : O(V) as we are using the visited array to keep track of the visited nodes. recursion stack will be there but it is not considered in the space complexity.

*/