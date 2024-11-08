# Subarray with k different integers
[Problem Link](https://leetcode.com/problems/subarrays-with-k-different-integers/description/)

## Problem desciption 
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

### Example 1:

* **Input:** nums = [1,2,1,2,3], k = 2,<br>
* **Output:** 7,<br>
* **Explanation:** Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2],<br>


## constraints
* 1 <= nums.length <= 2 * 10^4
* 1 <= nums[i], k <= nums.length

## Code
```cpp
class Solution {
public:
    int solve(vector<int> &nums,int k){
        /*
        
        Standard variable size sliding window template which counts the number of substring with atmost k integers and return the value.

        */

        unordered_map<int,int> freq;
        int n = nums.size();
        int i = 0,j = 0;
        int maxSubString = 0;

        while(j<n){
            freq[nums[j]]++;

            while(freq.size() > k){
                freq[nums[i]]--;
                if(freq[nums[i]] == 0 ) freq.erase(nums[i]);
                i++;
            }
            maxSubString += j-i+1;
            j++;
        }
        return maxSubString;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //as we need only exactly k - we can find atmost k - atmost k-1.
        /*
            first find all the substrings with atmost k integers 
            this will generate substrings with 1 integer + 2 integer + 3 integer + ... + k-1 substring + k integer substring
            now we will generate all the substring with k - 1 integers which will generate all the substring with 1 integer + 2 integer + ... + k - 1 integer 

            when we subtract all of them reduce leaving only the k integer substring. 
        
        */
        return solve(nums,k) - solve(nums,k-1);
    }
};
```

My solution on leetcode solution :
[My solution](https://leetcode.com/problems/subarrays-with-k-different-integers/solutions/5855090/easy-variable-size-sliding-window-approach-c-beginner-friendly/)

## Intuition
As we need only exactly k - we can find atmost k - atmost k-1.

* First find all the substrings with atmost k integers
this will generate substrings with 1 integer + 2 integer + 3 integer + ... + k-1 substring + k integer substring.

* Now we will generate all the substring with k - 1 integers which will generate all the substring with 1 integer + 2 integer + ... + k - 1 integer

* Then we will subtract each one of them leaving only the k integer substrings.

## Approach
* We will use the Standard variable size sliding window template which counts the number of substring with atmost k integers and return the value.

* We will call the sliding window function twice one for atmost k and other for k - 1 substring.

## Complexity
- Time complexity:O(n)


- Space complexity:O(k)
