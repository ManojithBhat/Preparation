# Continous Subarray
[Problem Link](https://leetcode.com/problems/continuous-subarrays/description/?envType=daily-question&envId=2024-12-14)

## Problem desciption 
You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:

Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
Return the total number of continuous subarrays.

A subarray is a contiguous non-empty sequence of elements within an array.

### Example 1:

*Input:* nums = [5,4,2,4]<br>
*Output:* 8<br>
*Explanation:* <br>
Continuous subarray of size 1: [5], [4], [2], [4].<br>
Continuous subarray of size 2: [5,4], [4,2], [2,4].<br>
Continuous subarray of size 3: [4,2,4].<br>
Thereare no subarrys of size 4.<br>
Total continuous subarrays = 4 + 3 + 1 = 8.<br>
It can be shown that there are no more continuous subarrays.<br>


## constraints
* 1 <= nums.length <= 105
* 1 <= nums[i] <= 109

## Code
```cpp
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        map<int, int> mp;

        int i = 0;
        int j = 0;

        long long count = 0;

        while(j < n) {
            mp[nums[j]]++;
            
            while(abs(mp.rbegin()->first - mp.begin()->first) > 2) { //it means it is out of the bound
                //shrink window -move i index
                mp[nums[i]] -= 1;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            count += j-i+1;
            j++;
        }

        return count;
    }
};
```

## Intuition
As the problem states that we need to calculate number of subarrays, sliding window is the great option
we need only to have the minimum and maximum number, so we cnnot keep counter, we keep map and get the max and min element from the start n end of the map.

## Approach


## Complexity
- Time complexity:


- Space complexity:
