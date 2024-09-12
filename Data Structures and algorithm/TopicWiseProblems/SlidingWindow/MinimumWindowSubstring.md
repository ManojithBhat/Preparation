# Minimum Window Substring
[Problem Link](https://leetcode.com/problems/minimum-window-substring/)

## Problem desciption 

Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

### Example 1:

> **Input:** s = "ADOBECODEBANC", t = "ABC"<br>
**Output:** "BANC"<br>
**Explanation:** The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

## constraints
* m == s.length
* n == t.length
* 1 <= m, n <= 105
* s and t consist of uppercase and lowercase English letters.

## Code
```cpp

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        unordered_map<char,int> hash;

        for(auto c : t) hash[c]++;

        int i = 0, j = 0; // two pointers
        int cnt = 0, minLength = INT_MAX, startIndex = 0;
        
        while(j < n) {
            if(hash[s[j]] > 0) {
                cnt++;
            }
            hash[s[j]]--;

            while(cnt == m) {
                if(j - i + 1 < minLength) {
                    minLength = j - i + 1;
                    startIndex = i;
                }
                
                hash[s[i]]++;
                if(hash[s[i]] > 0) cnt--;
                i++;
            }
            j++;
        }

        return minLength != INT_MAX ? s.substr(startIndex, minLength) : "";
    }
};

```

## Intuition
Here we keep track of precalculated map values, we decrement the map value when we move accorss j and increment the cnt ,when the cnt is equal to t's len we keep shortnenin the search window from the left. 

## Approach
sliding window

## Complexity
- Time complexity: O(N+m)


- Space complexity: O(m)
