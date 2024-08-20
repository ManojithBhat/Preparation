# floor and ceil in a array 
[Problem Link](https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%253BbatchId=154)

## Problem desciption 

Given a sorted array arr[] of size n without duplicates, and given a value x. Floor of x is defined as the largest element k in arr[] such that k is smaller than or equal to x. Find the index of k(0-based indexing).

## constraints


## Code
```cpp
class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &v) {
        // code here
        //to find the floor 
        sort(v.begin(),v.end());
         int low = 0;
        int high = v.size() - 1;
        int floor = -1;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            if(v[mid] <= x){
                floor = v[mid];
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        
        //to find the ceil 
        low = 0;
        high = v.size() - 1;
        int ceil = -1;
        while(low <= high){
            int mid = (low + high)/2;
            
            if(v[mid] < x){
                low = mid+1;
            }else{
                ceil = v[mid];
                high = mid-1;
                
            }
        }
        return {floor,ceil};
        
    }
};

```

## Intuition


## Approach


## Complexity
- Time complexity: O(logn)


- Space complexity:
