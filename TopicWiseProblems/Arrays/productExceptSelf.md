# Product except self
[Problem Link](https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1)

## Problem desciption 
Given an array nums[], construct a Product Array nums[] such that nums[i] is equal to the product of all the elements of nums except nums[i].

### Examples:

> Input: nums[] = [10, 3, 5, 6, 2]<br>
> Output: [180, 600, 360, 300, 900]<br>
> Explanation: For i=0, P[i] = 3*5*6*2 = 180.<br>
> For i=1, P[i] = 10*5*6*2 = 600.<br>
> For i=2, P[i] = 10*3*6*2 = 360.<br>
> For i=3, P[i] = 10*3*5*2 = 300.<br>
> For i=4, P[i] = 10*3*5*6 = 900.<br>


## constraints
* 1 <= nums.size() <= 1000
* 0 <= nums[i] <= 200
* nums[i] may contain duplicates.


## Code
```cpp

#define ll long long int
class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
    
        ll p1 = 1,p2 = 1;
        int n = nums.size();
        if(n == 1) return {1};
        vector<ll> pre1(n),pre2(n);
        for(int i=0;i<n;i++){
            p1 *= nums[i];
            pre1[i] = p1;
            
            p2 *= nums[n-i-1];
            pre2[n-i-1] = p2;
        }
        
        vector<ll> ans(n);
        ans[0] = pre2[1];
        ans[n-1] = pre1[n-2];
        for(int i = 1;i<n-1;i++){
            ans[i] = pre1[i-1]*pre2[i+1];
        }
        return ans;
    }
};

```

## Intuition


## Approach


## Complexity
- Time complexity: O(N)


- Space complexity: O(N)
