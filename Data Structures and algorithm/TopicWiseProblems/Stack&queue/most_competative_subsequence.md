# Find the Most Competitive Subsequence
[Problem Link](https://leetcode.com/problems/find-the-most-competitive-subsequence/description/)

## Problem desciption 
Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.

An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.

We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.

### Example 1:

> **Input:** nums = [3,5,2,6], k = 2
> **Output:** [2,6]
> **Explanation:** Among the set of every possible subsequence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.


## constraints
* 1 <= nums.length <= 105
* 0 <= nums[i] <= 109
* 1 <= k <= nums.length

## Code
```cpp
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        int n = nums.size();
        vector<int> res;

        for(int i = 0;i<n;i++){
            int rem = n - i ;
            while(!st.empty() && st.top() > nums[i] && st.size() + rem -1 >= k ){
                st.pop();
            }

           if(st.size() < k) st.push(nums[i]);
        }

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
```

## Intuition
The question demands to have a subsequence ( order does not matter ) and we need to find the subsequnce with greater number ( so greater -> small ) so using the stack would be the great option ( monotonic option ). now we need the sequence to be of fixed size.
the prime thing is keep poping out the element as you encounter the smaller element at the top but wiht the condition is that the remainig seq along with the rem element is grater than the k , and you add only when size is less than k.


## Complexity
- Time complexity: O(N)


- Space complexity: O(n)
