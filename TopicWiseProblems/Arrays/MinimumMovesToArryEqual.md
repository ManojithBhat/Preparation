# Minimum Moves to Equal Array Elements II
[Problem Link](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/)

## Problem desciption 
Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer

Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
Example 2:

Input: nums = [1,10,2,9]
Output: 16
 


## constraints

n == nums.length
1 <= nums.length <= 105
-109 <= nums[i] <= 109
## Code
```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        /*
        int n = nums.size();
        int steps = 0;
        sort(nums.begin(),nums.end());
        int median = nums[n/2];
        
        for(int i = 0;i<n;i++){
            steps += abs(nums[i] - median);
        }
        return steps;
        */
        int n = nums.size(), steps = 0;
        nth_element(nums.begin(), nums.begin()+(n/2), nums.end()); 
        
        int median = nums[n/2];
        for(int i=0; i<n; i++){
            steps += abs(nums[i] - median);
        }
        return steps;

    }
};
```

## Intuition
Now just think after sorting we need to increase the elements at the left side of the array and decrease the elements at the right side of the array. So lets take the first nums[0] and last element nums[n-1], the element to whom they should be made equal be centre. Hence nums[0] <= centre <= nums[n-1]. If we take any other value as centre then total steps needed will be more . Now if we continue doing the same step for 2nd, 3rd ... ith element we get a general relation nums[i] <= centre <= nums[n-1-i].This ends at the central element of the array if n is odd i.e. nums[n/2] and if n is even it end at the condition nums[n/2 -1] <= centre <= nums[n/2]. So centre will be mid value in case of n is odd and can be any value between the two middle values if n is even.

The mean will decrease the squared diff where as median will decrease the absolute diff ie summation of xi - x

## Approach


## Complexity
- Time complexity:


- Space complexity:
