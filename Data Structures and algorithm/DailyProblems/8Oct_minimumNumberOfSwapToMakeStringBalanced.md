# 1963. Minimum Number of Swaps to Make the String Balanced
[Problem Link](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/submissions/1415495340/?envType=daily-question&envId=2024-10-08)

## Problem desciption 
You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:

It is the empty string, or
It can be written as AB, where both A and B are balanced strings, or
It can be written as [C], where C is a balanced string.
You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make s balanced.

### Example 1:

> **Input:** s = "][]["<br>
> **Output:** 1<br>
> **Explanation:** You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".<br>

### Example 2:

> **Input:** s = "]]][[["<br>
> **Output:** 2<br>
> **Explanation:** You can do the following to make the string balanced:<br>
> - Swap index 0 with index 4. s = "[]][][".<br>
> - Swap index 1 with index 5. s = "[[][]]".<br>
> The resulting string is "[[][]]".<br>

## constraints
* n == s.length
* 2 <= n <= 106
* n is even.
* s[i] is either '[' or ']'.
The number of opening brackets '[' equals n / 2, and the number of closing brackets ']' equals n / 2.

## Code
```cpp
class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(int i = 0;i<s.size();i++){
            char var = s[i];
            if(var == ']' && (!st.empty() && st.top() == '[')) st.pop();
            else if(var=='[') st.push(var);
        }   

        int n = st.size();
        return (n+1)/2;
    }
};
```

## Intuition
* we need to take into consideration of number of unbalanced paranthesis
* for that we use stack as it is best ds for handling paranthesis related problems

The logic behind this is - if we remove all the balanced paranthesis we always end with this pattern -> ..]]]][[[[...<br>
* now we observe that by swapping one pair of paranthesis we are able to balance
4 paranthesis that is 2 pairs
* consider the pairs - 1 and 4 in ]]][[[ if weswap ->  ][][][ 
* now we require another swap to make the paranthesis balanced <br>
hence if there are n 'opening bracket' and n is even then it is n/2<br>
if n is odd we require another extra pair to swap the last ones so it is (n+1)/2<br>
as integer division yields us the floor value we can use (n+1)/2<br>

## Approach


## Complexity
- Time complexity: o(N)


- Space complexity:O(N)
