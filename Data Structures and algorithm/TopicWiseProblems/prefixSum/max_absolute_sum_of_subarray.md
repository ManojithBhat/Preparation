# Maximum Absolute sum of any subarray 
[Problem Link](https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/)

## Problem desciption 
You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.

**Example 1:**

> Input: nums = [1,-3,2,3,-4]<br>
> Output: 5<br>
> Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.<br>

**Example 2:**

> Input: nums = [2,-5,1,-4,3,-2]<br>
> Output: 8<br>
> Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.<br>

## constraints
* 1 <= nums.length <= 105
* -104 <= nums[i] <= 104

## Code
```cpp
/*class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        int minSum = 0;
        int maxSum = 0;

        int n = nums.size();

        for(int i = 0;i<n;i++){
            minSum += nums[i];
            maxSum += nums[i];

            minVal = min(minVal,minSum);
            maxVal = max(maxVal,maxSum);

            if(minSum >= 0) minSum = 0;
            if(maxSum <= 0) maxSum = 0;
        }
        
        return max(maxVal,abs(minVal));
    }
};*/

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        /* we neeed to find the maximum absolute sum so when we are at the particular index i, all i need to look is to find the index that will maximise the difference of the sum, so if the current sum is positive i need to look at the prefix sum that is as least as possible so that the difference is achieved, similarly if the sum is negative then i need to look for the max positive sum */

        int maxPrefix = INT_MIN,minPrefix = INT_MAX;
        int currPrefix = 0;

        int result = INT_MIN;

        int n = nums.size();
        for(int i = 0;i<n;i++){
            currPrefix += nums[i];

            maxPrefix = max(maxPrefix,currPrefix);
            minPrefix = min(minPrefix,currPrefix);

            if(currPrefix < 0 ){
                //check the diff with the highest value
                result = max(result, abs(maxPrefix - currPrefix));
            }else{
                //the purpose of checking the max against itself come from the fact that it subarray can start from the first index 
                result = max(result,abs(minPrefix - currPrefix));
            }
        }
        return result;
    }
};

//another straight fwd approach is to calculate the max and the min sum of the array and take the diff of those, this ensures that we get the largest absolute diff 

```

## Intuition


## Approach


## Complexity
- Time complexity:O(N)


- Space complexity:O(1)
