

/*

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.


Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 
Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // prefix sum problem 
        int count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum - k;
            if (!mp.empty() && mp.find(rem) != mp.end()) count += mp[rem];
            mp[sum]++;
        }
        return count;
    }
};


/*

Prefixsubarray sums : https://leetcode.com/discuss/study-guide/4023666/prefix-sum-questions-to-practice

*/ 

/*

Intution : The problem can be solved using the conept of prefix sum concept, where we iterate through the array and keep track of the sum of the elements till that point, and we keep track of the sum of the elements till that point in a map, and we check if the sum - k is present in the map or not, if it is present then we increment the count by the value of the sum - k in the map, and we increment the sum in the map by 1.

TC : O(N) SC : O(N)

*/