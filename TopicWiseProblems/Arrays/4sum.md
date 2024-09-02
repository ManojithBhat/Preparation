# 4 sum
[Problem Link](https://leetcode.com/problems/4sum/)

## Problem desciption 

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

* 0 <= a, b, c, d < n
* a, b, c, and d are distinct.
* nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

### Example 1:

**Input:** nums = [1,0,-1,0,-2,2], target = 0<br>
**Output:** [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

## constraints
* 1 <= nums.length <= 200
* -109 <= nums[i] <= 109
* -109 <= target <= 109

## Code
```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int start = j + 1;
                int end = n - 1;

                while (start < end) {
                    long long sum = 0;
                    sum += nums[i];
                    sum += nums[j];
                    sum += nums[start];
                    sum += nums[end];

                    if (sum == target) {
                        res.push_back(
                            {nums[i], nums[j], nums[start], nums[end]});
                        start++;
                        end--;
                        while (start < end && nums[start] == nums[start - 1])
                            start++;
                        while (start < end && nums[end] == nums[end + 1])
                            end--;
                    } else if (sum < target) {
                        start++;
                    } else {
                        end--;
                    }
                }
            }
        }
        return res;
    }
};          
```

## Intuition
The intution and all other approaches remain same as 3 sum problem. 
<br>
The only condition is which is extra here for another for loop where we add ``` if(j > i + 1 && nums[j] == nums[j - 1])```
the only thing is the first condition is always is that weneed to ignore the first element.

## Approach
same as 3 sum

## Complexity
- Time complexity: O(nlogn + O(n3 ))


- Space complexity:O(1)
