# Make sum divisible by P
[Problem Link](https://leetcode.com/problems/make-sum-divisible-by-p/description/)

## Problem desciption 

Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.

### Example 1:

> **Input:** nums = [3,1,4,2], p = 6<br>
**Output:** 1<br>
**Explanation:** The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.<br>

## constraints
* 1 <= nums.length <= 105
* 1 <= nums[i] <= 109
* 1 <= p <= 109

## Code
```cpp
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;

        int n = nums.size();
        for(int i = 0;i<n;i++){
            sum = (sum+nums[i])%p;
        }

        int target = sum%p;
        if(target == 0) return 0; //if the target becames 0 then no need to check

        unordered_map<int,int> mp;
        mp[0] = -1;
        int len = n; //it could be the max value
        int curr = 0;

        for(int i = 0;i<n;i++){
            curr = (curr+nums[i])%p;
            int required = (curr - target + p)%p;
            if(mp.find(required) != mp.end()){
                len = min(len, i - mp[required]);
            }
            mp[curr] = i;
        }
        return len == n ? -1:len;
    }
};
```

## Intuition
The problem boils down to find the length of the minimum subarray length with the value equal to target.
where target is the reminder of the sum of nums with modulo p
ie. sum = p*num + target.
If we remove target then we can get a array of sum divisible by p

We will use the concept of prefix sum. where we will store the sum untill that element.

```
CONCEPT 1:
    sum of subarray from i to j = (sum of subarray from 0 to j - sum of subarray i) 
    sum untill i is computed while traversing => call it presum
    sum untill j is computed till now = call it currsum 
    SO TARGET = CURRSUM - PRESUM;
    upon rearranging PRESUM ( to find in the map ) = CURRSUM - TARGET
    * what does it give the whether there is a subarray with the sum = target; 

```
```

CONCEPT 2:
    presum = currsum - target
    (presum)%p = (currsum - target)%p

    how to handle the negative - just add p and take modulo 
    (presum)%p = (currsum - target + p)%p

```
```
CONCEPT 3: 
    why add 0 at first - if we acheieve 0 sum at any moment whcih means the whole subarray from starting have sum equal to sum = required

    Why not sliding window ?
    Target is not remainder always, suppose your p is 8 and remainder is 3 , so you may think that our target sum is 3 but you dont know sum 3 is contained in array or not , there might case where  sum 3 is not present as subarray but as 8+3=11 or 8+8+3=19 etc (n*p+3) removing n*p+remainer alsoo makes whole array divisible by p,

```



## Complexity
- Time complexity:


- Space complexity:
