# Shortest palindrome
[Problem Link](https://leetcode.com/problems/shortest-palindrome/description/?envType=daily-question&envId=2024-09-20)

## Problem desciption 
You are given a string s. You can convert s to a 
palindrome
 by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 

### Example 1:

**Input:** s = "aacecaaa"<br>
**Output:** "aaacecaaa"<br>
### Example 2:

**Input:** s = "abcd"<br>
**Output:** "dcbabcd"<br>


## constraints
* 0 <= s.length <= 5 * 104
* s consists of lowercase English letters only.


## Code
```cpp
class Solution {
public:
    string shortestPalindrome(string s) {
         string rev = s;
        reverse(begin(rev), end(rev));
        for(int i = 0; i < s.length(); i++) {

            if(!memcmp(s.c_str(), rev.c_str() + i, s.length()-i)) { //prefix in s == suffix in rev
                return rev.substr(0, i) + s;
            }
        }

        return rev + s;
    }
};
```

## Intuition


## Approach


## Complexity
- Time complexity: O(n2)


- Space complexity: O(n)
