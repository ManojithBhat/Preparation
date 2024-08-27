# Path with maximum probability
[Problem Link](https://leetcode.com/problems/path-with-maximum-probability/description/?envType=daily-question&envId=2024-08-27)

## Problem desciption 
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.




## constraints
* 2 <= n <= 10^4
* 0 <= start, end < n
* start != end
* 0 <= a, b < n
* a != b
* 0 <= succProb.length == edges.length <= 2*10^4
* 0 <= succProb[i] <= 1
* There is at most one edge between every two nodes.

## Code
```cpp
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
       unordered_map<int,vector<pair<int,double>>> adj;

       for(int i = 0;i<edges.size();i++){
           adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
           adj[edges[i][1]].push_back({edges[i][0],succProb[i]});

       }

       priority_queue<pair<double,int>> pq;
       vector<double> pro(n,0);
 
       pq.push({1,start_node});
       pro[start_node] = 1; 

        while(!pq.empty()){
            int node = pq.top().second;
            double probability = pq.top().first;
            pq.pop();

            if(node == end_node) return probability;

            for(auto it: adj[node]){
                int child = it.first;
                double prob = it.second;

                if(prob*probability > pro[child]){
                    pro[child] = prob*probability;
                    pq.push({pro[child],child});
                }
            }
        }

        return 0.0;
    }
};

```

## Intuition
This is similar to the dijkstra algorithm, but instead of the distance we need to maximise the probability,

when you need to find the distance of the single node and not the array, you can easily brake the loop and return it whenever you got the required node. 
Here we are also using the priority_queue as a maxheap as we need to keep track of the max probability and not the minimum distance. 
It is advised to look after for whether it is directed or undirected graph and see whether it is required to build the adjecency list. 

## Approach
Plain dijkstra algorithm and some modification in the logic ... and u are good to go.

## Complexity
- Time complexity: O(ElogV)


- Space complexity: O(V) 
