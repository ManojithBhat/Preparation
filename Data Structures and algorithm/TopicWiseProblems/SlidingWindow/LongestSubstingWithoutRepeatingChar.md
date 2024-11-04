# Longest Substring Without Repeating Characters
[Problem Link](https://leetcode.com/problems/longest-substring-without-repeating-characters)

## Problem desciption 
Given a string s, find the length of the longest substring without repeating characters.

### Example 1:

**Input:** s = "abcabcbb"<br>
**Output**: 3<br>
Explanation: The answer is "abc", with the length of 3.<br>


## constraints
* 0 <= s.length <= 5 * 104
* s consists of English letters, digits, symbols and spaces.

## Code
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        map<char,int> mp;
        int maxSize = 0;

        while(j<n){
            mp[s[j]]++;
            while(!mp.empty() && mp[s[j]]>1)
            {
                mp[s[i]]--;
                i++;
            }

            maxSize = max(j-i+1,maxSize);
            j++;
        }
        return maxSize;
    }
};
```

## Intuition
variable size sliding window technique 

## Approach


## Complexity
- Time complexity:


- Space complexity:
