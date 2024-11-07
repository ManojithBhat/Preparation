# Single element in sorted array
[Problem Link](https://leetcode.com/problems/single-element-in-a-sorted-array/)

## Problem desciption 

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

### Example 1:

**Input:** nums = [1,1,2,3,3,4,4,8,8]<br>
**Output:** 2

## constraints


## Code
```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        if( nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-1]) return nums[n-1];

        int low = 0,high = n - 1;
        while( low <= high ){
            int mid = (low + high)/2;

            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) return nums[mid];
            else if(nums[mid] == nums[mid+1]){
                if(mid%2 != 0 ) high = mid-1;
                else low = mid+1;
            }else{
                if(mid%2 != 0) low = mid+1;
                else high = mid - 1; 
            }
        }

        return -1;
    }
};
```

## Intuition

## Approach


## Complexity
- Time complexity: O(log n)


- Space complexity:O(1)
