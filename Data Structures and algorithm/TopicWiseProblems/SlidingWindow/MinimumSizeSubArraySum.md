# Minimum Size Subarray Sum
[Problem Link](https://leetcode.com/problems/minimum-size-subarray-sum/)

## Problem desciption 

Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

### Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]<br>
Output: 2<br>
Explanation: The subarray [4,3] has the minimal length under the problem constraint.<br>

## constraints
* 1 <= target <= 109
* 1 <= nums.length <= 105
* 1 <= nums[i] <= 104

## Code
```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0,j = 0;
        int n = nums.size();
        int sum = 0;
        int len = INT_MAX;
        
        while(j<n){
            sum += nums[j];

            while(sum >= target){
                len = min(len,j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }

        return len == INT_MAX ? 0:len;
    }
};

```

## Intuition
standard variable size sliding window technique where we try to shrink the window when the sum exceeds the target sum.

## Approach
Two pointer and sliding window

## Complexity
- Time complexity:
 O(N)

- Space complexity: O(1)
