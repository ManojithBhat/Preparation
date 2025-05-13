# Minimum Operations to Convert All Elements to Zero
[Problem Link](https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/)

## Problem desciption 

You are given an array nums of size n, consisting of non-negative integers. Your task is to apply some (possibly zero) operations on the array so that all elements become 0.

In one operation, you can select a subarray [i, j] (where 0 <= i <= j < n) and set all occurrences of the minimum non-negative integer in that subarray to 0.

Return the minimum number of operations required to make all elements in the array 0.

### Example 1:

Input: nums = [0,2]

Output: 1

Explanation:

Select the subarray [1,1] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [0,0].
Thus, the minimum number of operations required is 1.

### Example 2:

Input: nums = [3,1,2,1]

Output: 3

Explanation:

Select subarray [1,3] (which is [1,2,1]), where the minimum non-negative integer is 1. Setting all occurrences of 1 to 0 results in [3,0,2,0].
Select subarray [2,2] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [3,0,0,0].
Select subarray [0,0] (which is [3]), where the minimum non-negative integer is 3. Setting all occurrences of 3 to 0 results in [0,0,0,0].
Thus, the minimum number of operations required is 3.
### Example 3:

Input: nums = [1,2,1,2,1,2]

Output: 4

Explanation:

Select subarray [0,5] (which is [1,2,1,2,1,2]), where the minimum non-negative integer is 1. Setting all occurrences of 1 to 0 results in [0,2,0,2,0,2].
Select subarray [1,1] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [0,0,0,2,0,2].
Select subarray [3,3] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [0,0,0,0,0,2].
Select subarray [5,5] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [0,0,0,0,0,0].
Thus, the minimum number of operations required is 4.

## constraints
* 1 <= n == nums.length <= 105
* 0 <= nums[i] <= 105

## Code
```cpp
class Solution {
public:
//two observations, you need to always take the subarray that is between the zeroes then only you can move on with the solution.
// first make the lesser one zero,then move on to the next greater and so on.
//eg. [ 1 1 2 2 1 ] -> if 2 done [ 2, 3 ] and then 1 ->  3 moves, if one done first [ 0 4 ] -> then 2 -> 2 moves


    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> a(n);
        for(int i = 0;i<n;i++){
            a[i] = {nums[i], i};
        }
    //start from smaller one and then check if it belongs to the same grp ( before the 0 made index ) if in same grp just move on or else make the new ans count. 
        sort(a.begin(),a.end()); //sort the modified array
        set<int> st{n}; //it keep track of the index that has already been visited or made zero, intially push n.

        int ans = 0;
        for(int i = 0;i<n;i++){
            st.insert(a[i].second);
            if(a[i].first != 0) ans++; //we need one operation to make it zero. 
            while(i + 1 < n && a[i].first == a[i+1].first){
                int preMarkedIndex = *st.upper_bound(a[i].second);
                int nextSameIndex = a[i+1].second;

                if(preMarkedIndex < nextSameIndex) break;
                i++; //just move on as it belongs to the same group. 
                st.insert(a[i].second);
            }
        }
        return ans;
    }
};
```

## Intuition


## Approach


## Complexity
- Time complexity: O(nlogn)


- Space complexity: O(n)
