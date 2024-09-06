# Time Needed to Inform All Employees
[Problem Link](https://leetcode.com/problems/time-needed-to-inform-all-employees/description/)

## Problem desciption 
A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company is the one with headID.

Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. Also, it is guaranteed that the subordination relationships have a tree structure.

The head of the company wants to inform all the company employees of an urgent piece of news. He will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know about the urgent news.

The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).

Return the number of minutes needed to inform all the employees about the urgent news.


### Example 1

> **Input:** n = 6, headID = 2, manager = [2,2,-1,2,2,2],  <br>
> **informTime** = [0,0,1,0,0,0] <br>
> **Output:** 1 <br>
> **Explanation:** The head of the company with id = 2 is the direct manager of all the employees in the company and needs 1 minute to inform them all.
The tree structure of the employees in the company is shown.

## constraints
* 1 <= n <= 105
* 0 <= headID < n
* manager.length == n
* 0 <= manager[i] < n
* manager[headID] == -1
* informTime.length == n
* 0 <= informTime[i] <= 1000
* informTime[i] == 0 if employee i has no subordinates.
* It is guaranteed that all the employees can be informed.

## Code
```cpp

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        //creating adjecency list
        unordered_map<int,vector<int>> adj;
        for(int i = 0;i < n;i++){ //N
            if(i != headID){
                adj[manager[i]].push_back(i);
            }
        }

        queue<pair<int,int>> q;
        q.push({0,headID});
        int tm = 0;
        int maxTime = 0;
        while(!q.empty()){ //N
           int node = q.front().second;
           int time = q.front().first;
           q.pop();
           int ttm = time+informTime[node];
           tm = max(tm,ttm);
           for(auto child: adj[node]){ //M
                q.push({ttm,child});
           }
        }
        return tm;
    }
};

```

## Intuition
There is no need to create the adjecency list as there is no back relationship possible or there is a cycle as such. <br>
This problem is similar to the questions of rotten oranges or minimum time to burn the tree. We try to keep a queue which stores the pair ``` queue<pair<int,int>> ``` that is ```{time,node}``` and perform [Bredth First Search](BFS.md) and every time we update the time taken and maxTime taken and push {time time till there + curr time to inform}.

## Approach


## Complexity
- Time complexity: O(M+N) - nodes + edges


- Space complexity: O(N)
