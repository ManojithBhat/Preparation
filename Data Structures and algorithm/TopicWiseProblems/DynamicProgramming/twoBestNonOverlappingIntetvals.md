# Two Best Non-Overlapping Events
[Problem Link](https://leetcode.com/problems/two-best-non-overlapping-events/)

## Problem desciption 

You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

### Example 1:<br>
> **Input:** events = [[1,3,2],[4,5,2],[2,4,3]]<br>
> **Output:** 4<br>
> **Explanation:** Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.<br>

## constraints
* 2 <= events.length <= 105
* events[i].length == 3
* 1 <= startTimei <= endTimei <= 109
* 1 <= valuei <= 106

## Code
```cpp
class Solution {
public:

    int n;
    int t[100001][3]; //table to store the index and count;
    int binarySearch(vector<vector<int>>&events,int start){
        int l = 0;
        int r = n-1;
        int res = n; //initalise to n , if we didnt get the valid index will return this, which will return in the next recursion call
        while(l<=r){
            int mid = (l + r)/2;

            if(events[mid][0] > start){
                res = mid;
                r = mid - 1;
            }else{
                l = mid+1;
            }
        }
        return res;
    }

    int solve(vector<vector<int>>&events,int ind,int count){
        //if the count is 2 or out of bound then return 0
        if(count == 2 || ind >= n) return 0;
        if(t[ind][count] != -1) return t[ind][count];
        int nextValidIndex = binarySearch(events,events[ind][1]);
        //as things are sorted, we need to pick the next range that has start time strictly greater than the current end time, for that sake we apply binary search and get the upper bound
        //perform the pick and not pick situation
        int pick = events[ind][2] + solve(events,nextValidIndex,count+1);
        int notPick = solve(events,ind+1,count);
        return t[ind][count] =  max(pick,notPick);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        //the logic is to do a pick and not pick on this and get the result

        n = events.size();
        sort(events.begin(),events.end());
        memset(t,-1,sizeof(t));
        int count = 0;
        return solve(events,0,count);
    }
};
```

## Intuition
A combination of pick not pick of recursion, interval problem, dynamic programming memoizatoin and binary search. 

## Approach


## Complexity
- Time complexity: O(nlogn)


- Space complexity:
