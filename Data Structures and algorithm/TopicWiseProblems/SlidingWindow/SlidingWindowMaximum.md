# Sliding Window Maximum
[Problem Link]()

## Problem desciption 
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

### Example 1:

**Input:** nums = [1,3,-1,-3,5,3,6,7], k = 3<br>
**Output:** [3,3,5,5,6,7]<br>
**Explanation:** <br>
Window position                Max<br>
---------------               -----<br>
[1  3  -1] -3  5  3  6  7       3<br>
 1 [3  -1  -3] 5  3  6  7       3<br>
 1  3 [-1  -3  5] 3  6  7       5<br>
 1  3  -1 [-3  5  3] 6  7       5<br>
 1  3  -1  -3 [5  3  6] 7       6<br>
 1  3  -1  -3  5 [3  6  7]      7<br>

## constraints

* 1 <= nums.length <= 105
* -104 <= nums[i] <= 104
* 1 <= k <= nums.length
* 
## Code
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        int n = nums.size();
        int j = 0;

    /*
        back 
        |   |  |
        |   |  | 
        |   |  \/ decreasing this way
        front
    */

        while (j < n) { //n
            // check if the last element of the deque is out of the window.
            if (!q.empty() && q.front() <= j - k)
                q.pop_front();

            // as we are maintaining monotonically decreasing ( front-back ) pop
            // out all the elements that are smaller than the curr element.
            while ( !q.empty() && nums[q.back()] <= nums[j]) q.pop_back();
            q.push_back(j);

            //as step length is 1 we will see just if j >= k-1
            if( j >= k-1) res.push_back(nums[q.front()]);
            j++;
        }
        return res;
    }
};
```

## Intuition
Okay first of all this isn't the standard sliding window question, in this question we need to use deque ( a double sided queue where we can remove add and delete elements from both the ends ), in this question we have 2 objective, to keep track of the max in the curr window, to maintain the current window size.

First, we will create a deque in which front of the queue will have will have the max element in the queue and the bottom will have recent and min of the window.

So we will have 3 main steps : 
1. check if the element at the top ( as it the max element and non-recent element ) is within the window, if not pop it from front.
2. Pop all the elements from the back which has value less than equal to the curret incoming element.
3. if the size is equal to the window add it to the resultant.


## Complexity
- Time complexity: O(N)


- Space complexity: O(N)
