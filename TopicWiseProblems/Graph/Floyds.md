# Floyd's Algorithm 

[Problem Link](https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1)

## Problem desciption 
The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j. <br>
Note : Modify the distances for every pair in-place.

## constraints
* 1 <= n <= 100
* -1 <= matrix[ i ][ j ] <= 1000

### Example 1:

> **Input Format:**  <br>
> matrix[][] = { {0, 2, -1, -1}, {1, 0, 3, -1},{-1, -1, 0, -1},{3, 5, 4, 0} }<br>
> 
> **Output:**<br>
> 0 2 5 -1 <br>
> 1 0 3 -1 <br>
> -1 -1 0 -1 <br>
> 3 5 4 0 <br>
> 
> **Explanation:** In this example, the final matrix 
> is storing the shortest distances. For example, matrix[i][j] is 
> storing the shortest distance from node i to j.
> 

## Code
```cpp

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size();
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1) matrix[i][j] = 1e9;
	        }
	    }
	    
	    for(int k = 0; k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e9) matrix[i][j] = -1;
	        }
	    }
	}
};

```

## Intuition

Unlike the other 2 algorithm for finding the shortest path ie. [Dijkstra]() and [BellMan-form]() algorithm which is single source multi destination shortest path algoritm, [Floyd's]() algorithm is multi-source shortest path algorithm.<br>
<br>
In Floyd Warshall's algorithm, we need to check every possible path going via each possible node. And after checking every possible path, we will figure out the shortest path(a kind of brute force approach to find the shortest path). <br>
Here we will calculate dist[i][j] for every possible node k (k = 0, 1….V, where V = no. of nodes), and will select the minimum value as our result.<br>
It is much of brute force, then being intutive. we try to find all the possible path from one point to the another through that node.<br>


## Follow up question that can be asked, 

*How to detect a negative cycle ?*
If we find that the cost of reaching any node from itself is less than 0, we can conclude that the graph has a negative cycle.

If it is know that there is no negative edges, we can apply dijkstra algortithm for every possible node then the time complexity reduces to O(V^2(LOGE))


## Complexity
- Time complexity:  O(V^3)


- Space complexity: O(1)
