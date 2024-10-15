# Separate Black and White Balls
[Problem Link]()

## Problem desciption 
There are n balls on a table, each ball has a color black or white.

You are given a 0-indexed binary string s of length n, where 1 and 0 represent black and white balls, respectively.

In each step, you can choose two adjacent balls and swap them.

Return the minimum number of steps to group all the black balls to the right and all the white balls to the left.

### Example 1:

**Input:** s = "101"<br>
**Output:** 1<br>
**Explanation:** We can group all the black balls to the right in the following way:<br>
- Swap s[0] and s[1], s = "011".<br>
Initially, 1s are not grouped together, requiring at least 1 step to group them to the right.<br>

## constraints
* 1 <= n == s.length <= 105
* s[i] is either '0' or '1'.

## Code
```cpp
class Solution {
public:
    long long minimumSteps(string s) {
        int st_idx = 0;
        long long cnt = 0;

        for(int i = 0;i < s.size();i++){
            if(s[i] == '0'){
                cnt += ( i - st_idx);
                st_idx++;
            }
        }
        return cnt;
    }
};
```

## Intuition
The intution is to keep the track of the index where the next probable white ball have to come and keep track of the current white ball index, 
when we encounter the '0' we can calculate swap count by i - st_idx and get the total result. 


## Complexity
- Time complexity: O(n)


- Space complexity:O(1)
