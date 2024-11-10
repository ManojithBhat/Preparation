# Shortest Subarray With OR at Least K II
[Problem Link](https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/?envType=daily-question&envId=2024-11-10)

## Problem desciption 
You are given an array nums of non-negative integers and an integer k.

An array is called special if the bitwise OR of all of its elements is at least k.

Return the length of the shortest special non-empty  subarray of nums, or return -1 if no special subarray exists.

### Example 1:

**Input:** nums = [1,2,3], k = 2<br>
**Output:** 1<br>
**Explanation:**: The subarray [3] has OR value of 3. Hence, we return 1.<br>


## constraints

* 1 <= nums.length <= 2 * 105
* 0 <= nums[i] <= 109
* 0 <= k <= 109


## Code
```cpp
class Solution {
public:
    /*
        The vector of 32 size contains the bit that is set, take for example
       vector that is 0 0 0 0 0 1 0 1 0 1 1 this is the number,
        * So as we just pass through the array, we set the array bits
        * At every time we check the number value, if it is greater than k
       then,we remove the setbits at the position.
        * the thing here is, we create the hashmap for each of the bit and determine the number. 
    */

    void update(int num, vector<int>& vec, int val) {
        for (int i = 0; i < 32; i++) {
            if ((num >> i) & 1) {
                vec[i] += val;
            }
        }
    }

    int getDecimalFromBinary(vector<int>& vec) {
        int num = 0;
        for (int i = 0; i < 32; i++) {
            if (vec[i] > 0) {
                num |= (1 << i);
            }
        }
        return num;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();
        vector<int> vec(32, 0);
        int result = INT_MAX;

        while (j < n) {
            update(nums[j], vec, 1);

            while (i <= j && getDecimalFromBinary(vec) >= k) {
                result = min(result, j - i + 1);
                update(nums[i], vec, -1);
                i++;
            }
            j++;
        }
        return result == INT_MAX ? -1:result;
    }
};
```

## Intuition
We will keep an array vis, with 32 size which will keep the number of bit set untill now, by tracking the vec[i] > 0 and converting it into the decimal we caluclate the shortest subarray.


## Complexity
- Time complexity: O(NlogN)


- Space complexity: O(32)
