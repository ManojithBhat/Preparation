# Minimum Limit of Balls in a Bag
[Problem Link](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/)

## Problem desciption 
You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.

You can perform the following operation at most maxOperations times:

Take any bag of balls and divide it into two new bags with a positive number of balls.
For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.

Return the minimum possible penalty after performing the operations.

### Example 1:

**Input:** nums = [9], maxOperations = 2<br>
**Output:** 3<br>
**Explanation:** 
- Divide the bag with 9 balls into two bags of sizes 6 and 3. [9] -> [6,3].<br>
- Divide the bag with 6 balls into two bags of sizes 3 and 3. [6,3] -> [3,3,3].<br>
The bag with the most number of balls has 3 balls, so your penalty is 3 and you should return 3.<br>

### Example 2:

**Input:** nums = [2,4,8,2], maxOperations = 4<br>
**Output:** 2<br>
**Explanation:**
- Divide the bag with 8 balls into two bags of sizes 4 and 4. [2,4,8,2] -> [2,4,4,4,2].<br>
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,4,4,4,2] -> [2,2,2,4,4,2].<br>
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,4,4,2] -> [2,2,2,2,2,4,2].<br>
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2].<br>
The bag with the most number of balls has 2 balls, so your penalty is 2, and you should return 2.<br>
 

## constraints
* 1 <= nums.length <= 105
* 1 <= maxOperations, nums[i] <= 109

## Code
```cpp
class Solution {
public:
    bool solve(vector<int> &res, int maxOp,int op){
        int operation = 0;
        int n = res.size();
        for(int i = 0;i<n;i++){
            operation += (res[i]/op);
            if(res[i]%op == 0) operation -= 1;
        }

        if(operation > maxOp) return false;
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int high = INT_MIN;
        for(int i = 0;i<n;i++){
            high = max(high,nums[i]);
        }

        int low = 1;
        int res = 0;
        while(low <= high){
            int mid = ( low + high)/2;
            
            if(solve(nums,maxOperations,mid)){
                res = mid;
                high = mid - 1;
            }else{
                low = mid+1;
            }
        }
        return res;
    }
};
```

## Intuition
Standard binary search on answer pattern problem. 

## Approach


## Complexity
- Time complexity:


- Space complexity:
