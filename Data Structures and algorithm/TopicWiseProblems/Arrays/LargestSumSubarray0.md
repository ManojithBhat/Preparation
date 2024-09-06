# Largest Subarray with sum 0
[problem link](https://geeksforgeeks.org/problems/largest-subarray-with-0-sum/1)

## Problem desciption 
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

### Exampl 1
> 
> **Input:** arr[] = [ 15, -2, 2, -8, 1, 7, 10, 23 ] , n = 8<br>
> **Output:** 5<br>
> **Explanation**: The largest subarray with sum 0 is -2 2 -8 1 7.<br>
> 

## constraints
* 1 <= n <= 105
* -1000 <= arr[i] <= 1000, for each valid i

## Code
```cpp

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        
        int sum = 0;
        int maxLen = 0;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
            
            int rem = sum;
            if(mp.find(rem)!=mp.end()){
                int len = i - mp[rem];
                maxLen = max(maxLen,len);
            }else{
                mp[sum] = i;
            }
        }
        return maxLen;
        
    }
};

```

## Intuition
A classic problem of prefix sum problem, this is an extension of [Subarray with sum K](SubArraySumDivsibleByK.md) problem with 2 extra cases<br>
* The subarray sum is equal to zero => that we need to look whether sum is present.
* We are supposed to find the length and not to count the number of subarrays, so instead of count we have lenght variable, which is updated everytime when we get a element in a map. <br>

we iterate through the array and calculate the sum for every iteration and find the sum in the map, if it is present then we calculate the new length, else we push the element into the map. <br>

> please note that we should not update the map, after every iteration - then we wont get the longest subarray as the new position will be updated.


## Complexity
- Time complexity: O(n)


- Space complexity: O(n)
