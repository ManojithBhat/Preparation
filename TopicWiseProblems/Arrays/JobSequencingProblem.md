# Job Sequencing Problem 
[Problem Link](https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1)

## Problem desciption 
Given a set of n jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with a job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. Deadline of the job is the time on or before which job needs to be completed to earn the profit.

### Example  1
> **Input:** Jobs = [[1,2,100],[2,1,19],[3,2,27],[4,1,25],[5,1,15]]<br>
> **Output:** 2 127<br>
> **Explanation:** 2 jobs can be done with maximum profit of 127 (100+27).<br>

### Example 2 
> **Input:** Jobs = [[1,4,20],[2,1,1],[3,1,40],[4,1,30]]<br>
> **Output:** 2 60<br>
> **Explanation:** Job1 and Job3 can be done with maximum profit of 60 (20+40).

## constraints
> 1 <= n <= 105
> 1 <= Deadline,id <= n
> 1 <= Profit <= 500


## Code
```cpp
//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool greater(Job j1, Job j2){
        if(j1.profit > j2.profit) return true;
        return false;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        //sorting the array based on the profit 
        sort(arr,arr+n,greater);
        
        int maxSize = -1;
        for(int i=0;i<n;i++){
            maxSize = max(maxSize,arr[i].dead);
        }
        
        vector<int> deadline(maxSize+1,-1);
        
        int maxProfit = 0;
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            int currDead = arr[i].dead;
            while(currDead >=1 && deadline[currDead]!=-1){
                currDead--;
            }
            
            if(currDead >=1){
                maxProfit += arr[i].profit;
                deadline[currDead] = arr[i].id;
                cnt++;
            }
        }

        return {cnt,maxProfit};
    } 
};


```

## Intuition


## Approach


## Complexity
- Time complexity: O(NlogN) - as we are sorting


- Space complexity: O(N)
