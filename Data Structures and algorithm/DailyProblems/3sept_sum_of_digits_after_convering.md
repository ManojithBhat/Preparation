# Sum of Digits of String After Convert
[Problem Link](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/?envType=daily-question&envId=2024-09-03)

## Problem desciption 
You are given a string s consisting of lowercase English letters, and an integer k.

First, convert s into an integer by replacing each letter with its position in the alphabet (i.e., replace 'a' with 1, 'b' with 2, ..., 'z' with 26). Then, transform the integer by replacing it with the sum of its digits. Repeat the transform operation k times in total.

For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:

Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
Transform #2: 17 ➝ 1 + 7 ➝ 8
Return the resulting integer after performing the operations described above.

### Example 1:

**Input:** s = "iiii", k = 1
**Output:** 36
**Explanation:** The operations are as follows:
- Convert: "iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
- Transform #1: 9999 ➝ 9 + 9 + 9 + 9 ➝ 36
Thus the resulting integer is 36.



## constraints
* 1 <= s.length <= 100
* 1 <= k <= 10
* s consists of lowercase English letters.

## Code
```cpp
class Solution {
public:

    int returnSumDigit(int currdigit){
         int tempdigit = 0;
            while(currdigit){
                tempdigit += currdigit%10;
                currdigit=currdigit/10;
            }
        return tempdigit;
    }

    int getLucky(string s, int k) {
        int sum = 0;

        for(int i = 0;i<s.size();i++){
            sum += returnSumDigit(s[i] - 'a'+1);
        }
        while(k!=1){
            sum = returnSumDigit(sum);
            k--;
        }
        return sum;
    }
};
```



## Complexity
- Time complexity: O(k*digitLen + n)


- Space complexity: O(1)
