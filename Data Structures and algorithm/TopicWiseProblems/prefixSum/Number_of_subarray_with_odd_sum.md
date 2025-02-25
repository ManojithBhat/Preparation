# Number of Sub-arrays With Odd Sum
[Problem Link](https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/)

## Problem desciption 
Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.

## constraints
* 1 <= arr.length <= 105
* 1 <= arr[i] <= 100

## Code
```cpp
class Solution {
public:
    int mod = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n  = arr.size();

        int oddSum = 0;
        int evenSum = 0; //alternative approach is to start the evenSum with extra 1 
        int sum = 0;
        int cnt = 0;

        for(int i = 0;i<n;i++){
            sum += arr[i];

            if(sum % 2) oddSum += 1;
            else evenSum += 1;

            if(sum%2){
                cnt = (cnt + evenSum + 1)%mod;
            }else{
                cnt = (cnt + oddSum)%mod;
            }
        }
        return cnt%mod;
    }
};
```

## Intuition
The problem can be solved by the idea of difference of odd with odd as well as even with even gives even number while difference of odd with even and even with odd is an odd. We keep a sum variable that keep tracks of the total sum untill the current number, if the sum is odd, then we count the subarray by taking count of the number of even sum as diff the of sum bw odd and even sum gives odd sum subarrays and similar thing is done if the sum is even, we take odd count. 

## Approach
Prefix sum approach

## Complexity
- Time complexity: O(N)


- Space complexity: O(1)
