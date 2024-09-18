# Largest Number
[Problem Link](https://leetcode.com/problems/largest-number/description/?envType=daily-question&envId=2024-09-18)

## Problem desciption 
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

# Example 1:

**Input:** nums = [10,2]<br>
**Output:** "210"

# Example 2:

**Input:** nums = [3,30,34,5,9]<br>
**Output:** "9534330"

## constraints

* 1 <= nums.length <= 100
* 0 <= nums[i] <= 109

## Code
```cpp

bool compare(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);

    // Custom comparison to check which concatenation is larger
    if((sa + sb )> (sb + sa)){
        return true;
    }
    return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Sort using the custom comparator
        sort(nums.begin(), nums.end(), compare);

        // If the largest number after sorting is '0', the result is "0"
        if (nums[0] == 0) {
            return "0";
        }

        string ans = "";
        for (int num : nums) {
            ans += to_string(num);
        }

        return ans;
    }
};

```

## Intuition
The goal is to form the largest possible number from a given list of integers. Since simply sorting the numbers won't work (e.g., [9, 34] could incorrectly become 349 instead of 934), we need a custom sorting approach where we concatenate numbers in different orders and compare the results. If concatenating a + b results in a larger number than b + a, a should come before b.

Thus, by sorting the array based on this comparison, the numbers will be ordered correctly to form the largest number.

## Approach
**Convert Integers to Strings:** Since comparing individual digits of integers won't work directly for concatenation, first convert the integer array into an array of strings. This allows us to concatenate and compare the results of a + b and b + a.


**Custom Sorting:** Use a custom comparator to sort the string array. The comparator should compare two strings a and b by checking the results of a + b vs b + a. If a + b is larger, then a should come before b in the sorted array.

**Edge Case:** After sorting, if the largest number is "0" (i.e., if the first element in the sorted array is "0"), return "0", since this means all numbers were zeros.

Construct the Result: Use a StringBuilder to concatenate all the strings in the sorted array into the final result.

## Complexity
- Time complexity: O(nlogn)

- Space complexity: O(n)
