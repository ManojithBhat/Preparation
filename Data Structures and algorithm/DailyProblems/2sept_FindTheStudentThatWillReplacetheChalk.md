# Find the Student that Will Replace the Chalk
[Problem Link](https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/?source=submission-noac)

## Problem desciption 

There are n students in a class numbered from 0 to n - 1. The teacher will give each student a problem starting with the student number 0, then the student number 1, and so on until the teacher reaches the student number n - 1. After that, the teacher will restart the process, starting with the student number 0 again.

You are given a 0-indexed integer array chalk and an integer k. There are initially k pieces of chalk. When the student number i is given a problem to solve, they will use chalk[i] pieces of chalk to solve that problem. However, if the current number of chalk pieces is strictly less than chalk[i], then the student number i will be asked to replace the chalk.

Return the index of the student that will replace the chalk pieces.

### Example 1:

> **Input:** chalk = [5,1,5], k = 22<br>
> **Output:** 0<br>
> **Explanation:** The students go in turns as follows:<br>
> - Student number 0 uses 5 chalk, so k = 17.<br>
> - Student number 1 uses 1 chalk, so k = 16.<br>
> - Student number 2 uses 5 chalk, so k = 11.<br>
> - Student number 0 uses 5 chalk, so k = 6.<br>
> - Student number 1 uses 1 chalk, so k = 5.<br>
> - Student number 2 uses 5 chalk, so k = 0.<br>
> Student number 0 does not have enough chalk, so they will have to  replace it.<br>

## constraints

* chalk.length == n
* 1 <= n <= 105
* 1 <= chalk[i] <= 105
* 1 <= k <= 109


## Code
```cpp
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long  sum = 0;
        int n = chalk.size();
        
        for(int i = 0;i<n;i++) sum+=chalk[i];

        long long remSum = k - (k/sum)*sum;
        
        int i=0;
        long long currSum = 0;
        for(i=0;i<n;i++){
            currSum+=chalk[i];
            if(currSum>remSum) break;
        }
        return i;
    }
};

```

## Intuition

this problem involoves to find the index of student who cannot use the chalk. so we what we do is we distribute to all of them first, for that we do ```remSum = k - (k/sum)*sum;``` so we get number of chalks remaining after giving to all of them n number of times, now we look how much can we distribute.



## Complexity
- Time complexity: O(N)


- Space complexity:O(1)
