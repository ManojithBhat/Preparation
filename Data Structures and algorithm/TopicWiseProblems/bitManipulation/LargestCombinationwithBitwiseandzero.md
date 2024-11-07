# Largest Combination With Bitwise AND Greater Than Zero
[Problem Link](https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/?envType=daily-question&envId=2024-11-07)

## Problem desciption 

The bitwise AND of an array nums is the bitwise AND of all integers in nums.

For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
Also, for nums = [7], the bitwise AND is 7.
You are given an array of positive integers candidates. Evaluate the bitwise AND of every combination of numbers of candidates. Each number in candidates may only be used once in each combination.

Return the size of the largest combination of candidates with a bitwise AND greater than 0.

 
### Example 1:

> **Input:** candidates = [16,17,71,62,12,24,14]<br>
> **Output:** 4<br>
> **Explanation:** The combination [16,17,62,24] has a bitwise AND of 16 & 17 & 62 & 24 = 16 > 0.<br>
> The size of the combination is 4.<br>
> It can be shown that no combination with a size greater than 4 has a bitwise AND greater than 0.<br>
> Note that more than one combination may have the largest size.<br>
> For example, the combination [62,12,24,14] has a bitwise AND of 62 & 12 & 24 & 14 = 8 > 0.<br>


## constraints
* 1 <= candidates.length <= 105
* 1 <= candidates[i] <= 107

## Code
```cpp
class Solution {
public:
    int largestCombination(vector<int>& candidates) {

        //we will check the setbits of each of them
        /*
        
        eg :1  -  0 0 0 0 1
            4  -  0 0 1 0 0 
            5  -  0 0 1 0 1
            9  -  0 1 0 0 1
            8  -  0 1 0 0 0
            7  -  0 0 1 1 1 
            ----------------
                  0 2 3 1 4  -> bits sets in each column

            by choosing the one that has more bit set we can find which can be taken to make and > 0

        */
        int maxBitSet = 0;

        //we dont have to have 32 bits, to count the number of bits ( that is the left most bit set position we use this )
        int bits = floor(log2(1e7))+1;

        //we check for each of the bits 
        for(int i = 0;i<bits;i++){
            int cnt = 0;
            
            for(auto num: candidates){
                if((num&(1<<i)) != 0) cnt++;
            }
            maxBitSet = max(maxBitSet,cnt);
        }
        return maxBitSet;
    }
};
```

## Intuition
to count the numbers with the same bit set in the location and get the maxCount out of all.

## Approach


## Complexity
- Time complexity: O(N*32)

- Space complexity: O(`)
