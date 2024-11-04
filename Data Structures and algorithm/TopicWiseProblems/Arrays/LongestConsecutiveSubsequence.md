# Longest Consecutive Subsequence
[Problem Link](https://leetcode.com/problems/longest-consecutive-sequence/)

## Problem desciption 
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

### Example 1:

**Input:** nums = [100,4,200,1,3,2]
**Output:** 4
**Explanation:** The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.


## constraints

* 0 <= nums.length <= 105
* -109 <= nums[i] <= 109

## Code
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // brute force is to check every time if the next element exist
        // better solution is to sort the array and check element
        // optimal solution is :

        unordered_set<int> st;
        for (auto num : nums) {
            st.insert(num);
        }
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int len = 0;

            if (st.find(x - 1) == st.end()) {
                // if the prev element is not present then only proceed to check
                // next one, there by reducing redentant checks
                int y = x;
                len = 1;
                while (st.find(y + 1) != st.end()) {
                    len++;
                    y = y + 1;
                }
            }

            maxLen = max(len, maxLen);
        }
        return maxLen;
    }
};

```

## Intuition
The brute force solution is for every element you go, check for the next consecutive element by searching throught the whole array again and again. <br>
The better solution is to sort the array and then check the array for the consecutive sequence if present and update the length accordingly.<br>
The optimal solution is to put every element into the set for easy retrieval, then first check if the prev element is present for the element, if present then do not check, as it would be reduntant to check as we would or would have done the processing, if it is not present then check for the next element iteratively until no element is present and update the length accordingly.

## Approach


## Complexity
- Time complexity: O(N)


- Space complexity: O(N)
