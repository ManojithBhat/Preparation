# Find K-th Smallest Pair Distance
[Problem Link](https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/?envType=daily-question&envId=2024-08-14)

## Problem desciption 
The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

### Example 1:

> **Input:** nums = [1,3,1], k = 1<br>
> **Output:** 0<br>
> **Explanation:** Here are all the pairs:<br>
> (1,3) -> 2<br>
> (1,1) -> 0<br>
> (3,1) -> 2<br>
> Then the 1st smallest distance pair is (1,1), and its distance is 0.<br>

## constraints
* n == nums.length
* 2 <= n <= 104
* 0 <= nums[i] <= 106
* 1 <= k <= n * (n - 1) / 2

## Code
```cpp

class Solution {
public:
    // Find count of pairs having distance <= D
    int slidingWindowCount(vector<int>& nums, int D) {
        int count = 0;
        int n = nums.size();
        int i = 0;
        int j = 1;

        //this exploits the fact that when the pair a,c is less than k in the array [a,b,c], the pair (a,b) should also be less than the k due to the fact that it is b<c and dif of a,b will also be less. remember it is sorted. 
        while (j < n) {
            while (nums[j] - nums[i] > D) {
                ++i;
            }
            count += j - i;
            j++;
        }
        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int l = 0;
        int r = nums[n - 1] - nums[0];
        int result = 0;

        while (l <= r) {
            int mid = (l + r) / 2;
            //it will count the number of pairs that has the distance less than or equal to mid.
            int count = slidingWindowCount(nums, mid);

            //If the count is less than k, which means i need to search in the right side of the mid to get my answer.
            if (count < k) {
                l = mid + 1;
            } else {
                //if the count is greater than k, which means this could be my possible answer, but i can get exactly kth one too, so lets keep trying.
                result = mid;  // Store the mid as a potential result
                r = mid - 1;
            }
        }
        return result;
    }
};


```

## Intuition
This problem involves using the technique of ```sliding window``` and ```binary search```. <br>
The brute force solution would be to generate all the distance pairs and use the ```heap``` to find the kth smallest element. but looking at the constraints and the time taken by this algorithm, O(n^2logk) it will give TLE. 

he intution arrises due the fact that is it required to check all the pairs whether it is kth smallest?. can we make a wild guess of the difference and count all the pairs less than k, and decide should we increase or decrease the search space. Well this is what we have to do. When it comes to guessing and finding it is the binary search problem. and we have used sliding window ( remember this approach (used in inversion pairs too )) to find the number of pairs, the approach see the comments in the code. 


## Complexity
- Time complexity: O(nlogn + wlogn)

- Space complexity:
