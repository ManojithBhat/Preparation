# Maximum Sum of 3 Non-Overlapping Subarrays
[Problem Link](https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/?envType=daily-question&envId=2024-12-28)

## Problem desciption 
Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

 

### Example 1:

**Input**: nums = [1,2,1,2,6,7,5,1], k = 2<br>
**Output**: [0,3,5]<br>
**Explanation**: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].<br>
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.<br>


## constraints
* 1 <= nums.length <= 2 * 104
* 1 <= nums[i] < 216
* 1 <= k <= floor(nums.length / 3)

## Code
```cpp
class Solution {
private:
    int t[20001][4];

    int helper(vector<int>& sums, int k, int idx, int rem) {
        if (rem == 0) return 0;
        if (idx >= sums.size()) {
            return INT_MIN;
        }

        if (t[idx][rem] != -1) {
            return t[idx][rem];
        }

        int take = sums[idx] + helper(sums, k, idx + k, rem - 1);
        int not_take = helper(sums, k, idx + 1, rem);

        t[idx][rem] = max(take, not_take);
        return t[idx][rem];
    }

    void solve(vector<int>& sums, int k, int idx, int rem, vector<int>& indices) {
        if (rem == 0) return;
        if (idx >= sums.size()) return;

        int take     = sums[idx] + helper(sums, k, idx + k, rem - 1);
        int not_take = helper(sums, k, idx + 1, rem);

        if (take >= not_take) {
            indices.push_back(idx);
            solve(sums, k, idx + k, rem - 1, indices);
        } else {
            solve(sums, k, idx + 1, rem, indices);
        }
    }

public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // Initialize the memoization array with -1
        memset(t, -1, sizeof(t));

        // Number of possible subarray starting positions
        int n = nums.size() - k + 1;

        vector<int> sums;
        int windowSum = 0;
        int i = 0, j = 0;

        // Slide the window
        while (j < nums.size()) {
            windowSum += nums[j];
            
            // Check if the window size is reached
            if (j - i + 1 == k) {
                sums.push_back(windowSum); // Store the sum of the current window
                windowSum -= nums[i];     // Slide the window forward
                i++;
            }
            j++;
        }

        vector<int> indices;

        // Reconstruct the path to find indices
        solve(sums, k, 0, 3, indices);

        return indices;
    }
};

```

## Intuition
It is a sliding window ( used to calcualte the sum of prefixes from the particular index ) and dp question ( based on pick not pick condition),
it involves two recursion, one to find the better sum and other to find the optimal path, both ivolves recursion and only fiding the sum involves the dp. 

## Approach


## Complexity
- Time complexity:n


- Space complexity:n
