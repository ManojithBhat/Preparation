#  The Number of the Smallest Unoccupied Chair
[Problem Link](https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/?envType=daily-question&envId=2024-10-11)

## Problem desciption 

There is a party where n friends numbered from 0 to n - 1 are attending. There is an infinite number of chairs in this party that are numbered from 0 to infinity. When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.

For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.

You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], indicating the arrival and leaving times of the ith friend respectively, and an integer targetFriend. All arrival times are distinct.

Return the chair number that the friend numbered targetFriend will sit on.

 

### Example 1:

> **Input:** times = [[1,4],[2,3],[4,6]], targetFriend = 1
> **Output:** 1
> **Explanation:** 
- Friend 0 arrives at time 1 and sits on chair 0.<br>
- Friend 1 arrives at time 2 and sits on chair 1.<br>
- Friend 1 leaves at time 3 and chair 1 becomes empty.<br>
- Friend 0 leaves at time 4 and chair 0 becomes empty.<br>
- Friend 2 arrives at time 4 and sits on chair 0.<br>
Since friend 1 sat on chair 1, we return 1.<br>

## constraints
* n == times.length
* 2 <= n <= 104
* times[i].length == 2
* 1 <= arrivali < leavingi <= 105
* 0 <= targetFriend <= n - 1
* Each arrivali time is distinct.

## Code
```cpp
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> chairs(n, -1);

        int target = times[targetFriend][0];

        sort(times.begin(), times.end());
        for (int i = 0; i < n; i++) {
            int start = times[i][0];
            int end = times[i][1];

            for (int j = 0; j < n; j++) {
                if (chairs[j] <= start) {
                    chairs[j] = end;
                    if (start == target) {
                        return j;
                    }
                    break;
                }
            }
        }
        return -1;
    }
};
```

## Intuition


## Approach


## Complexity
- Time complexity:


- Space complexity:
