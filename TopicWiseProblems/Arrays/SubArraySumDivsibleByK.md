# SubarraySum divisible by k

## Problem desciption 
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
A subarray is a contiguous part of an array.

Example 1:
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Example 2:
Input: nums = [5], k = 9
Output: 0

## constraints
* 1 <= nums.length <= 3 * 104
* -104 <= nums[i] <= 104
* 2 <= k <= 104

## Code
```cpp

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int sum = 0;
        int n   = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int count = 0;

        for(int i=0;i<n;i++){
            sum = (sum+nums[i])%k;
            if(sum<0) sum += k;
            if(!mp.empty() && mp.find(sum)!=mp.end()){
                count+=mp[sum];
            }
            mp[sum]++;
        }
        return count;
    }
};

```

## Intuition
The intution is similar to the prefix sum quesitons instead of storing the sum for every index, we keep the reminder of the sum 
<br>
One thing to note is that whenever the sum becames less that 0 then we need to add the integer k as we need to take care of how modulo operator works on the negative numbers
<br>
As it is required to find the number we are required to use the count of occurence of the map element 

## Approach
> to be filled


## Complexity
- Time complexity: o(n)


- Space complexity: O(n) - for map
