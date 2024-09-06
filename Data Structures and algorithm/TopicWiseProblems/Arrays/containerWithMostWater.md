# Container with most water
[Problem Link](https://leetcode.com/problems/container-with-most-water/description/)

## Problem desciption 
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

### Example 1
> **Input:** height = [1,8,6,2,5,4,8,3,7]<br>
> **Output:** 49<br>
> **Explanation:** The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

## constraints
* n == height.length
* 2 <= n <= 105
* 0 <= height[i] <= 104

## Code
```cpp

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int  i = 0,j = n - 1;
        int maxCapacity = 0;

        while(i < j){   

            maxCapacity = max(maxCapacity,(j-i)*min(height[i],height[j]));
            if(height[i] >= height[j]) j--;
            else i++;
        }
        return maxCapacity;
    }
};

```

## Intuition
The brute force would be to check for every pillar the maxvolume it can form with the other pillar, but this is O(n2) solution and it is not feasible. 

The best approach is the two pointer, we place two pointers at the starting and ending of the array, we have 2 parameters, that is width and height. so we start with largest width, then we move have to move the pointer, as the min of the largest gives the maximum of volume, we move that pointer which points to the shorter length, there by thinking that the next one would give us a better  result the correct one and we do this untill the end. 

## Approach

keep two pointers every time find the maxvolume, then move the pointer of the smaller length one.

## Complexity
- Time complexity: O(N)


- Space complexity: O(1)
