# Search in a sorted array 
[Problem Link](https://leetcode.com/problems/search-in-rotated-sorted-array/)

## Problem desciption 

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

### Example 1:

> Input: nums = [4,5,6,7,0,1,2], target = 0<br>
> Output: 4<br>

## constraints
* 1 <= nums.length <= 5000
* -104 <= nums[i] <= 104
* All values of nums are unique.
* nums is an ascending array that is possibly rotated.
* -104 <= target <= 104

## Code
```cpp

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //the question can be divided into 2 parts - identify the sorted part and then finding whether the answer is present
        int low = 0;
        int high = nums.size()-1;

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] == target) return mid;
            
            //left sorted part
            if(nums[low] <= nums[mid]){

                if(target >= nums[low] && target <= nums[mid]){
                    //it is there in this search space
                    high = mid-1;
                }else{
                    low = mid + 1;
                }

            }else{
            //right sorted part

            if(target >= nums[mid] && target <= nums[high]){
                    //it is there in this search space
                    low = mid+1;
                }else{
                    high = mid -1;
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
