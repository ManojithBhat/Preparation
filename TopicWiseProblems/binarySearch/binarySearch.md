# Binary Search
[Problem Link](https://leetcode.com/problems/binary-search/)

## Problem desciption 

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

### Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9<br>
Output: 4<br>
Explanation: 9 exists in nums and its index is 4


### Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2<br>
Output: -1<br>
Explanation: 2 does not exist in nums so <br>return -1<br>

## constraints
* 1 <= nums.length <= 104
* -104 < nums[i], target < 104
* All the integers in nums are unique.
* nums is sorted in ascending order.

## Code
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = (low+high)/2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
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
