# Problem Title
[Problem Link]()

## Problem desciption 

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

## Example 1:

> **Input:** nums1 = [1,3], nums2 = [2]<br>
> **Output:** 2.00000<br>
> **Explanation:** merged array = [1,2,3] and median is 2.<br>

## constraints
* nums1.length == m
* nums2.length == n
* 0 <= m <= 1000
* 0 <= n <= 1000
* 1 <= m + n <= 2000
* -106 <= nums1[i], nums2[i] <= 106

## Code
```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        //it is better to have the smaller size array to search.
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        
        int n = n1 + n2;
        //the +1 is used to accomodate the odd length combined array too 
        int left = (n1 + n2 + 1) / 2; 
        int low = 0, high = n1;
        
        while (low <= high) {
            int mid1 = (low + high)/2; // Calculate mid index for nums1
            int mid2 = left - mid1; // Calculate mid index for nums2
            
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            
            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if (l1 > r2) {
                high = mid1 - 1;
            }
            else {
                low = mid1 + 1;
            }
        }
        
        return 0; 
    }
};


```

## Intuition


## Approach


## Complexity
- Time complexity:O(log(min(n1,n2)))


- Space complexity:O(1)
