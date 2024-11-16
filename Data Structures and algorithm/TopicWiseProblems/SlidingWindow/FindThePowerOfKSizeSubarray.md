# Find the Power of K-Size Subarrays I
[Problem Link](https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/)

## Problem desciption 
You are given an array of integers nums of length n and a positive integer k.

The power of an array is defined as:

Its maximum element if all of its elements are consecutive and sorted in ascending order.
-1 otherwise.
You need to find the power of all 
subarrays
 of nums of size k.

Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].

 

### Example 1:

> **Input:** nums = [1,2,3,4,3,2,5], k = 3<br>
> **Output:** [3,4,-1,-1,-1]<br>
> **Explanation:**
> 
> There are 5 subarrays of nums of size 3:
> [1, 2, 3] with the maximum element 3.<br>
> [2, 3, 4] with the maximum element 4.<br>
> [3, 4, 3] whose elements are not consecutive.<br>
> [4, 3, 2] whose elements are not sorted.<br>
> [3, 2, 5] whose elements are not consecutive.<br>


## constraints
* 1 <= n == nums.length <= 500
* 1 <= nums[i] <= 105
* 1 <= k <= n

## Code
```cpp
class Solution {
public:
    bool check(vector<int>& nums, int i, int j) {
        for (int k = i; k < j; k++) {
            if (!(nums[k] < nums[k + 1] && abs(nums[k] - nums[k + 1]) == 1))
                return false;
        }
        return true;
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = 0;
        vector<int> ans;

        while (j < n) {

            while (j - i + 1 >= k) {
                if (check(nums, i, j)) {
                    ans.push_back(nums[j]);
                } else {
                    ans.push_back(-1);
                }
                i++;
            }

            j++;
        }
        return ans;
    }
};
```

## Intuition
Check for the every subarray and try to satisfy the condition of consecutiveness as well as sortness by using indices. If so, the last element would be the highest element as they are sorted if not add -1 to the answer array.

## Approach
Check for the every subarray and try to satisfy the condition of consecutiveness as well as sortness by using indices. If so, the last element would be the highest element as they are sorted if not add -1 to the answer array.

## Complexity
- Time complexity: O(n*k)


- Space complexity: O(1)
