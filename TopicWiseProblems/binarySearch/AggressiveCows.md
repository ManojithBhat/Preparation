# Aggressive Cows 
[Problem Link](https://www.geeksforgeeks.org/problems/aggressive-cows/1)

## Problem desciption 
You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.

Example 1:

Input:
n=5 
k=3
stalls = [1 2 4 8 9]
Output:
3
Explanation:
The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, 
which also is the largest among all possible ways.

## constraints
* 2 <= n <= 10^5
* 2 <= k <= n
* 0 <= stalls[i] <= 10^9

## Code
```cpp
class Solution {
public:

    int placeCows(int n,int k,vector<int>&stalls){
        
        int cow = 1; //we  can always place one cow at the first poition 
        int currPos = 0; //we have kept at the fist position 
        for(int i = 1;i<n;i++){
            if(stalls[i] - stalls[currPos] >= k){
                //place the cow in this position;
                currPos = i;
                cow++;
            }
        }
        return cow;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(),stalls.end());
        int low = 0;
        int high = stalls[n-1] - stalls[0];
        
        while(low <= high ){
            int dist = (low + high)/2;
            
            int cows = placeCows(n,dist,stalls);
            
            if(cows < k){
                //need to reduce the distance between the cows as we cant place all the cows 
                high = dist - 1;
            }
            else{
                //we can place the cows, but we need to make sure that is there any better solution for this 
                low  = dist + 1;
            }
        }
        return high;
    }
};

```

## Intuition


## Approach


## Complexity
- Time complexity:


- Space complexity:
