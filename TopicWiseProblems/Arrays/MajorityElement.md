# Majority element 

## Problem desciption 
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

**Example 1**
> **Input:** nums = [2,2,1,1,1,2,2]
> **Output:** 2


**Example 2**
> **Input:** nums = [2,2,1,1,1,2,2]
> **Output:** 2

## constraints
* n == nums.length
* 1 <= n <= 5 * 104
* -109 <= nums[i] <= 109

## Code
```cpp

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = -1;
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (count == 0) {
                element = nums[i];
                count++;
            } else {
                if (element == nums[i])
                    count++;
                else
                    count--;
            }
        }

        int countOriginal = 0;
        for (int i = 0; i < n; i++) {
            if (element == nums[i]) {
                countOriginal++;
            }
        }

        if (countOriginal > n/2)
            return element;
        else
            return -1;
    }
};

```

## Intuition

__Brute force__:
The simplest intution is to keep the map to take a note of the element and the count.
Then we iterate over the map to find the element of the count > n/2 if it is not present than return -1

__optimal solution__:
by keeping the iterator for storing the element and keeping the count, we keep iterating through the array and when ele is -1, we update the element as well as cnt, when cnt is not equal to zero and if the element is same as the ele then we increament the counter or decrease the counter 


## Complexity
- Time complexity: O(N)
- Space complexity: O(1)
