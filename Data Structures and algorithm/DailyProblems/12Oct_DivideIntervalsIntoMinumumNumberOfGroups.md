# Divide Intervals Into Minimum Number of Groups
[Problem Link](https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/?envType=daily-question&envId=2024-10-12)

## Problem desciption 
You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].

You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other.

Return the minimum number of groups you need to make.

Two intervals intersect if there is at least one common number between them. For example, the intervals [1, 5] and [5, 8] intersect.

### Example 1:

**Input:** intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]<br>
**Output:** 3<br>
**Explanation:** We can divide the intervals into the following groups:<br>
- Group 1: [1, 5], [6, 8].<br>
- Group 2: [2, 3], [5, 10].<br>
- Group 3: [1, 10].<br>
It can be proven that it is not possible to divide the intervals into fewer than 3 groups.<br>


## constraints
* 1 <= intervals.length <= 105
* intervals[i].length == 2
* 1 <= lefti <= righti <= 106

## Code
```cpp
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
       
        int count = 1;

        int n = intervals.size();

        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push({intervals[0][1]});
        for(int i=1;i<n;i++){
            int end = intervals[i][1];
            int start = intervals[i][0];
            if( pq.top() < start){
                pq.pop();
            }else{
                count++;     
            }
            pq.push(end);
        }
        return count;
        
    }
};
```

## Intuition
whenever a new interval comes in we need to check only the smallest element end, because if the current starting is smaller than top then we can pair it obvioulsy, if it is greater than the top element then we need to create another group as it is the smallest end and it is still overlapping.

## Approach
Brute force is to check all the array element but optimal is check the smallest one by pushing the end to the min heap

## Complexity
- Time complexity:
O(NlogN)

- Space complexity:O(N)
