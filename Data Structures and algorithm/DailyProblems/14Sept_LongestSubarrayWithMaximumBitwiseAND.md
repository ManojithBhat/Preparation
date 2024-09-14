# Longest Subarray With Maximum Bitwise ANDLongest Subarray With Maximum Bitwise AND
[Problem Link](https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/?envType=daily-question&envId=2024-09-14)

## Problem desciption 
You are given an integer array nums of size n.

Consider a non-empty subarray from nums that has the maximum possible bitwise AND.

In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A subarray is a contiguous sequence of elements within an array.

### Example 1:

**Input:** nums = [1,2,3,3,2,2]<br>
**Output:** 2<br>
**Explanation:**<br>
The maximum possible bitwise AND of a subarray is 3.<br>
The longest subarray with that value is [3,3], so we return 2


## constraints
* 1 <= nums.length <= 105
* 1 <= nums[i] <= 106

## Code
```cpp

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //the observation was to find the longest lenght of the subarray with the max element.

        int maxVal = 0;
        int len = 0;
        int maxLen = 0;

        for(int num:nums){
            if(num > maxVal){
                //update the len and maxVal as well as maxLen
                maxVal = num;
                len = 0;
                maxLen = 0;
            }

            if( num == maxVal ){
                len++;
            }else{
                len = 0;
            }

            maxLen = max(maxLen,len);
        }
        return maxLen;
    }
};

```

## Intuition
The most important thing to note here is : 
```bitwise AND of two different numbers will always be strictly less than the maximum of those two numbers.```

now, in order to get the largest xor we need to look for the largest element and find the size of the subarray that has all the maxElement and this is all the intution is.

## Approach
We define 3 variables, a maxVal to keep track of the maxElement, a len variable which stores the current length of the maxVal, and 
maxLen which keeps track of the maximum len we have achieved ,
<br>

we will reset the maxVal , len and maxLen when we encounter any element greater than the currVal. we will increment len when the element is same as the maxVal and reduce len to zero if it discontinues, and take maxLen everytime.


## Complexity
- Time complexity: O(N)


- Space complexity: O(1)
