# Furthest Building You Can Reach
[Problem Link](https://leetcode.com/problems/furthest-building-you-can-reach/description/)

## Problem desciption 

You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.

You start your journey from building 0 and move to the next building by possibly using bricks or ladders.

While moving from building i to building i+1 (0-indexed),

If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.


### Example 1
> **Input:** heights = [4,2,7,6,9,14,12], bricks = 5, ladders = > 1<br>
> **Output:** 4<br>
> **Explanation:** Starting at building 0, you can follow these > steps:
> - Go to building 1 without using ladders nor bricks since 4 >= 2.
> - Go to building 2 using 5 bricks. You must use either bricks or > ladders because 2 < 7.
> - Go to building 3 without using ladders nor bricks since 7 >= 6.
> - Go to building 4 using your only ladder. You must use either > bricks or ladders because 6 < 9.
> It is impossible to go beyond building 4 because you do not have > any more bricks or ladders.
> 
### Example 2:

> **Input:** heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2<br>
> **Output:** 7

## constraints
* 1 <= heights.length <= 105
* 1 <= heights[i] <= 106
* 0 <= bricks <= 109
* 0 <= ladders <= heights.length

## Code
```cpp
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladder) {
        priority_queue<int,vector<int>,greater<int>> pq;
        //The prioriry queue will signify the ladders used.
        //in this greedy approach we will first assign the biggest height to the ladder and then to the ladder, if we encounter any height that is greater than the smallest distacne previously encountere then we give the top of the pq, that is the smallest heigh to the brick and using ladder for the current one. if at any point brick is exhausted then we return i
        for(int i=0;i<heights.size() - 1;i++){
            int diff = heights[i+1] - heights[i];
            if(diff > 0){
                //we will use the ladder first, so push to pq
                pq.push(diff);

                if(ladder < pq.size()){
                    bricks -= pq.top();
                    pq.pop();
                    
                }

                if(bricks < 0 ) return i;
            }
        }
        return heights.size() - 1;
    }
};
```

## Intuition
This is the question of greedy approach, the prime thing to notice here is, we have to use the ladder for maximum height difference and the bricks for the lesser height distance. Hence in our approach we assign the ladder first to the height distance ( which is represented as the size of the priority queue), if the size of the priority queue has became greater than the number of ladders we have, then we use brics for that. 
<br>
The purpose of using min-heap is that it stores the min element at the top and max at the bottom, as we said earlier that min heap size represent the number of ladders, when the ladders are utilised then we pop the height and reduce the bricks, if the brics are also utilised we return the index i, if this is also done, then we return size-1.

## Complexity
- Time complexity: O(nlogk)


- Space complexity: (logk)
