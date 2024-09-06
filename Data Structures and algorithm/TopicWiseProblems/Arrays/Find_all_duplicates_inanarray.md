# Find All Duplicates in an Array

[Problem Link](https://leetcode.com/problems/find-all-duplicates-in-an-array/description/)

## Problem desciption 
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space

### Example 1:

> **Input:** nums = [4,3,2,7,8,2,3,1] <br>
> **Output:** [2,3]

## constraints
* n == nums.length
* 1 <= n <= 105
* 1 <= nums[i] <= n
* Each element in nums appears once or twice

## Code
```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            
            int pos = abs(nums[i]);
            int val = nums[pos-1];
            
            if(val < 0){
                res.push_back(pos);
            }else{
                nums[pos-1] = -nums[pos-1];
            }
        }
        return res;
    }
};

```

## Intuition
As the elements in the array rangers from 1 to n, we can make use of this fact to map the element with the corresponding index - 1. However, we also exploit the fact that there can be more than one occurance, so when no element is repeated then the elements corresponding to the index value present in the array are marked negative, so if we found any other element that is repeated, we also find that the valued corresponding to the index - 1 is negative, hence it is repeated.



## Complexity
- Time complexity: O(N)


- Space complexity: O(1)
