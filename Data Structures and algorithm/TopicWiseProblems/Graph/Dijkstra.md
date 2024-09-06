# Dijkstra Algorithm 
[Problem Link](https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1)

## Problem desciption 

Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.

## constraints
* 1 ≤ V ≤ 1000
* 0 ≤ adj[i][j] ≤ 1000
* 1 ≤ adj.size() ≤ [ (V*(V - 1)) / 2 ]
* 0 ≤ S < V

## Code
```cpp

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        vector<int> dist(V,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        dist[s] = 0;
        pq.push({0,s});
        
        while(!pq.empty()){
            pair<int,int> it = pq.top();
            int node = it.second;
            int wt = it.first;
            pq.pop();
            
            for(auto child : adj[node]){
                int dis = child[1];
                int ch = child[0];
                
                if(dis + wt < dist[ch]){
                    dist[ch] = dis + wt;
                    pq.push({dist[ch],ch});
                }
            }
        }
        return dist;
    }
};

```

## Intuition
Dijkstra is a algorithm that is single source shortest path algorithm, It is used to find the shortest path from the given node to all the node in the given graph, the only condition is that the graph should contain ```non-negative edges``` . The reason for saying non-negaive edges is ...


The reason  why this works is we are using min heap and we have always the least / min distance that we pick and calculate the next smaller distance. 

## Approach

The procedure that we can't afford to forget : 
* create the distance array with all initialised to inf distance 
* create minimim heap to store the distance ( from the sourc to that particular node) and the current node.
* Put the source node into the priority_queue. 
* pop the node from the queue, travere through the adjacency list to get the adjecency nodes 
* for each node calculate the distance ``` distance from curr node to child node + distance from source to the curr node ``` if this is smaller than previously calculated distance from the distance vector, then we update the distance vector and push the new distance and node into the priority queue as we discovered a new shortest way.


## Complexity
- Time complexity: O(ElogV)


- Space complexity: O(V)
