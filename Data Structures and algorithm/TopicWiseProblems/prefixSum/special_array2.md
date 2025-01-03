# Special Array 2
[Problem Link](https://leetcode.com/problems/special-array-ii/)

## Problem desciption 
An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
subarray
 nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.


### Example 1:
**Input:** nums = [3,4,1,2,6], queries = [[0,4]]<br>
**Output:** [false]<br>
**Explanation:**
The subarray is [3,4,1,2,6]. 2 and 6 are both even.<br>

### Example 2:
**Input:** nums = [4,3,1,6], queries = [[0,2],[2,3]]<br>
**Output:** [false,true]<br>
**Explanation:**
The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this query is false.<br>
The subarray is [1,6]. There is only one pair: (1,6) and it contains numbers with different parity. So the answer to this query is true.<br>


## constraints
* 1 <= nums.length <= 105
* 1 <= nums[i] <= 105
* 1 <= queries.length <= 105
* queries[i].length == 2
* 0 <= queries[i][0] <= queries[i][1] <= nums.length - 1

## Code
```cpp
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> prefix(n,0);

        prefix[0] = 0;

        for(int i = 1;i<n;i++){
            if((nums[i]%2 == nums[i-1]%2)){
                prefix[i] = prefix[i-1]+1;
            }else{
                prefix[i] = prefix[i-1];
            }
        }

        vector<bool> result(m,false);
        int i = 0;

        for(auto it: queries){
            int start = it[0];
            int end = it[1];

            if(prefix[end] - prefix[start] == 0){
                result[i] = true;
            }
            i++;
        }

        return result;
    }
};
```

## Intuition
keep a prefix array that keeps track of the violating index and use in the given range if there is any violating index

## Approach


## Complexity
- Time complexity:
max(m,n)

- Space complexity: n
