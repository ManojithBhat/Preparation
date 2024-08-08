
/*

Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

V = 5, E = 4
adj = {{1,2,3},{},{4},{},{}}

Output: 
0 1 2 3 4
Explanation: 
0 is connected to 1 , 2 , 3.
2 is connected to 4.
so starting from 0, it will go to 1 then 2
then 3. After this 2 to 4, thus bfs will be
0 1 2 3 4.


*/

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

/*
    Intution : 
        In this problem we are given a directed graph and we need to find the bfs traversal of the graph starting from the 0th node.
        so the first thing that comes to mind is to use the queue to store the nodes and then traverse the nodes and mark the visited nodes.
        so by this method we can find the bfs traversal of the graph.
        Application of bfs is to find the shortest path in the graph, any application that involves level by level traversal 
        
        Time Complexity : O(V+E) as we are traversing the graph only once.
        if we are using the adjacency matrix then the time complexity will be O(V^2) as we are traversing the graph twice.
        Space Complexity : O(N) as we are using the queue to store the nodes.

*/