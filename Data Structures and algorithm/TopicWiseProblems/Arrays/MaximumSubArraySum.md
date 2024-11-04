# Maximum Sub Array Sum
[Problem Link](https://leetcode.com/problems/maximum-subarray)

## Problem desciption 
Given an integer array nums, find the  subarray with the largest sum, and return its sum.

### Example 1:

**Input:** nums = [-2,1,-3,4,-1,2,1,-5,4]<br>
**Output:** 6<br>
**Explanation:** The subarray [4,-1,2,1] has the largest sum 6.<br>

## constraints
* 1 <= nums.length <= 105
* -104 <= nums[i] <= 104

## Code
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int maxSum = INT_MIN;

        for(int i = 0;i<n;i++){
            sum += nums[i];

            maxSum = max(sum,maxSum);

            if(sum < 0){
                sum = 0;
            }
        }
        return maxSum;
    }
};
```

## Intuition
The brute force is to check all the subarray sum that is available, <br>
The optimised solution is the ```kadanes algorithm```, where you make the sum equal to zero again when the sum drops to zero as it only contributes to decreasing the sum. it also handles all the cases when all the elements is negative as maxSum is intialised to minimum and first sum calculates the sum and then updtes. 


## Complexity
- Time complexity: O(N)


- Space complexity:O(1)
